//
// native-fs.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#pragma once

#include "file-system.hpp"


class NativeFileSystem : public FileSystem {
	public:
		static const int MaxFilenameSize;

	public:

		bool isFileExist(std::wstring filename);
		std::shared_ptr<File> loadFile(std::wstring filename);


};

