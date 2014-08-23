//
// resource-manager.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#pragma once

#include <string>
#include <map>
#include <list>
#include <thread>
#include <mutex>
#include <future>
#include <queue>
#include <condition_variable>
#include <memory>


//class ResourceObject;
#include "resource-object.hpp"

class ResourceDecoder;
class FileSystem;


class ResourceManager {
	public:
		ResourceManager();
		~ResourceManager();


		void regDecoder(ResourceDecoder *decoder);
		void regFilesystem(FileSystem *fs);

		std::shared_ptr<ResourceObject> loadObject(std::wstring filename);
		std::future<std::shared_ptr<ResourceObject>> loadObjectAsync(std::wstring filename);


		void removeUnusedObjects();

	private:
		void threadMain();

	private:
		std::map<std::wstring, std::shared_ptr<ResourceObject>> objects;
		std::list<ResourceDecoder *> decoders;
		std::list<FileSystem *> fileSystems;


		struct Task {
			std::promise<std::shared_ptr<ResourceObject>> promiseObject;
			std::wstring filename;
		};

		std::queue<std::shared_ptr<Task>> tasks;

		std::thread thread;

		std::condition_variable	cvIsAnyTask;

		std::mutex mutexObjects;
		std::mutex mutexDecoders;
		std::mutex mutexFileSystems;
		std::mutex mutexTasks;

};


