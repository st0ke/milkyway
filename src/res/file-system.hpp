//
// file-system.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#pragma once

#include <memory>
#include "file.hpp"

class FileSystem {
	public:
		virtual ~FileSystem() {}

		virtual bool isFileExist(std::wstring filename) = 0;
		virtual std::shared_ptr<File> loadFile(std::wstring filename) = 0;

};


