//
// resource-manager.cpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#include <algorithm>

#include "resource-manager.hpp"
#include "resource-decoder.hpp"
#include "file-system.hpp"



ResourceManager::ResourceManager() {
	thread = std::thread(std::bind(&ResourceManager::threadMain, this));
}

ResourceManager::~ResourceManager() {
	/* TODO delete decoders and filesystems */
}



void 
ResourceManager::regDecoder(ResourceDecoder *decoder) {
	if (decoder && std::find(decoders.begin(), decoders.end(), decoder) == decoders.end()) {
		std::unique_lock<std::mutex> lck(mutexDecoders);
		decoders.push_back(decoder);
	}
}
void 
ResourceManager::regFilesystem(FileSystem *fs) {
	if (fs && std::find(fileSystems.begin(), fileSystems.end(), fs) == fileSystems.end()) {
		std::unique_lock<std::mutex> lck(mutexFileSystems);
		fileSystems.push_back(fs);
	}
}


std::shared_ptr<ResourceObject> 
ResourceManager::loadObject(std::wstring filename) {
	mutexObjects.lock();
	auto it = objects.find(filename);
	if (it != objects.end()) {
		return it->second;
	}
	mutexObjects.unlock();
			


	std::shared_ptr<File> file;

	mutexFileSystems.lock();
	for (auto it = fileSystems.begin(); it != fileSystems.end(); ++it) {
		auto fs = *it;
		file = fs->loadFile(filename);
		if (file.get() != nullptr) {
			break;
		}
	}
	mutexFileSystems.unlock();

	if (file.get() == nullptr) {
		return nullptr;
	}



	std::unique_lock<std::mutex> lckDecoders(mutexDecoders);

	for (auto it = decoders.begin(); it != decoders.end(); ++it) {
		auto decoder = *it;

		if (decoder->canDecode(file)) {
			auto object = decoder->decode(file);
			std::unique_lock<std::mutex> lckObjects(mutexObjects);
			objects[filename]= object;
		}
	}

	return nullptr;
}

std::future<std::shared_ptr<ResourceObject>> 
ResourceManager::loadObjectAsync(std::wstring filename) {
	std::shared_ptr<Task> task(new Task);
	task->filename = filename;

	{
		std::unique_lock<std::mutex> lck(mutexTasks);

		tasks.push(task);
		cvIsAnyTask.notify_all();
	}

	return task->promiseObject.get_future();
}


void 
ResourceManager::removeUnusedObjects() {
	// TODO
}


void
ResourceManager::threadMain() {
	while(1) {
		std::unique_lock<std::mutex> lckTasks(mutexTasks);

		while (tasks.empty()) {
			cvIsAnyTask.wait(lckTasks);
		}

		auto task = tasks.front();
		tasks.pop();
		lckTasks.unlock();

		auto obj = loadObject(task->filename);
		task->promiseObject.set_value(obj);
	}
}
