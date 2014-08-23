//
// native-fs.cpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#include <cstdio>
#include <cstdlib>

#include "native-fs.hpp"


const int NativeFileSystem::MaxFilenameSize = 2048;



class NativeFile : public File {
	public:
		NativeFile(std::wstring filename)
			: File(filename) {
			char filenameUTF8[NativeFileSystem::MaxFilenameSize];
			if (wcstombs(filenameUTF8, filename.c_str(), NativeFileSystem::MaxFilenameSize) == NativeFileSystem::MaxFilenameSize) {
				filenameUTF8[NativeFileSystem::MaxFilenameSize - 1] = '\0';
			}

			file = fopen(filenameUTF8, "rb");
		}
		~NativeFile() {
			if (file) {
				fclose(file);
				file = nullptr;
			}
		}

		bool read(void *buf, size_t size) {
			if (!isOk()) {
				return false;
			}
			if (fread(buf, size, 1, file) != 1) {
				return false;
			}
			return true;
		}

		size_t seek(size_t size, SeekTypes type) {
			if (!isOk()) {
				return 0;
			}
			switch (type) {
				case File::SEEK_FORWARD:
					fseek(file, size, SEEK_CUR);
					break;
				case File::SEEK_BACKWARD:
					fseek(file, -((long int)size), SEEK_CUR);
					break;
				case File::SEEK_START:
					fseek(file, size, SEEK_SET);
					break;
			}
			return size;
		}

		bool isEOF() const {
			if (!isOk()) { 
				return true;
			}
			return feof(file);
		}


		bool isOk() const { return file != NULL; }

	private:
		FILE *file;

};



bool NativeFileSystem::isFileExist(std::wstring filename) {
	NativeFile f(filename);
	return f.isOk();
}
std::shared_ptr<File> NativeFileSystem::loadFile(std::wstring filename) {
	NativeFile *f = new NativeFile(filename);

	std::shared_ptr<File> retval;

	if (f->isOk()) {
		retval.reset(f);
	} else {
		delete f;
	}
	return retval;
}


