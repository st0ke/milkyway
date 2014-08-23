//
// resource-manager.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#pragma once


class ResourceObject {
	public:
		ResourceObject(std::wstring _filename): filename (_filename) {}
		virtual ~ResourceObject() {}

		std::wstring getFilename() const { return filename; }

	private:
		std::wstring filename;
};

