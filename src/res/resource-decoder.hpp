//
// resource-decoder.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#pragma once

#include <memory>

#include "file.hpp"
#include "resource-object.hpp"

class ResourceDecoder {
	public:
		virtual ~ResourceDecoder() {}

		virtual bool canDecode(std::shared_ptr<File> file) const = 0;
		virtual std::shared_ptr<ResourceObject> decode(std::shared_ptr<File> file) const = 0;
};

