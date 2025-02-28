// Copyright The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#ifndef CROSSAUDIO_LOG_H
#define CROSSAUDIO_LOG_H

#include "ErrorCode.h"
#include "Macros.h"

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

CROSSAUDIO_EXPORT enum CrossAudio_ErrorCode CrossAudio_logInit(FILE *stream);

#ifdef __cplusplus
}
#endif

#endif
