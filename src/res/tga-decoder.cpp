//
// tga-decoder.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#include "tga-decoder.hpp"

#include "value-parser.hpp"
#include "../video/texture.hpp"



bool TgaDecoder::canDecode(std::shared_ptr<File> file) const {
	if (!file->getFileExtension().compare(L"tga")) {
		return false;
	}
	return true;
}
std::shared_ptr<ResourceObject> 
TgaDecoder::decode(std::shared_ptr<File> file) const {
	std::shared_ptr<ResourceObject> retval;

	return retval;
}

