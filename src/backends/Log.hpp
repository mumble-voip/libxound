// Copyright The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#ifndef CROSSAUDIO_SRC_BACKENDS_LOG_HPP
#define CROSSAUDIO_SRC_BACKENDS_LOG_HPP

#include "Log.h"

#include <filesystem>
#include <format>
#include <source_location>
#include <string_view>

#define DEBUG(...) (debug(std::format(__VA_ARGS__)))

static inline void debug(const std::string_view message,
						 const std::source_location &location = std::source_location::current()) {
	auto path = std::filesystem::relative(location.file_name(), BACKENDS_DIR);

	print("%s | [%s]:%u\n", message.data(), path.c_str(), location.line());
}

template< typename T >
static inline void printFuncError(const char *funcName, const T error,
								  const std::source_location &location = std::source_location::current()) {
	debug(std::format("{}() failed with error {}!", funcName, error), location);
}

#endif
