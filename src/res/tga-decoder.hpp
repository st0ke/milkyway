//
// tga-decoder.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#pragma once

#include "resource-decoder.hpp"


class TgaDecoder: public ResourceDecoder {
	public:
		bool canDecode(std::shared_ptr<File> file) const;
		std::shared_ptr<ResourceObject> decode(std::shared_ptr<File> file) const;
};

