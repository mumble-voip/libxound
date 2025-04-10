// Copyright The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#ifndef CROSSAUDIO_SRC_BACKENDS_ALSA_ERRORCHECK_HPP
#define CROSSAUDIO_SRC_BACKENDS_ALSA_ERRORCHECK_HPP

#include "Log.hpp"

#include <format>
#include <source_location>

#define OK(func, ...) (ok(std::source_location::current(), #func, func __VA_OPT__(, ) __VA_ARGS__))

namespace alsa {
template< typename F, typename... Args >
static inline bool ok(const std::source_location &location, const char *func_name, F func, Args... args) {
	if (auto ret = func(args...); ret >= 0) {
		return true;
	} else {
		printFuncError(func_name, ret, location);
		return false;
	}
}
}; // namespace alsa

#endif
