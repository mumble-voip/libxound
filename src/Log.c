// Copyright The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#include "Log.h"

#include <stdarg.h>
#include <stdio.h>

typedef enum CrossAudio_ErrorCode ErrorCode;

static FILE *g_stream = NULL;

ErrorCode CrossAudio_logInit(FILE *stream) {
	g_stream = stream;
	return CROSSAUDIO_EC_OK;
}

void print(const char *format, ...) {
	if (!g_stream) {
		return;
	}

	va_list args;
	va_start(args, format);
	vfprintf(g_stream, format, args);
	va_end(args);
}
