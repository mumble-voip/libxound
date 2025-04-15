// Copyright The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#include "Mixer.hpp"

#include "ErrorCheck.hpp"

#include <fcntl.h>

#include <sys/ioctl.h>
#include <sys/soundcard.h>

using namespace oss;

bool Mixer::open() {
	return FileDescriptor::open("/dev/mixer", O_RDONLY);
}

bool Mixer::getAudioInfo(oss_audioinfo &info) {
	return OK(ioctl, get(), SNDCTL_AUDIOINFO, &info);
}

bool Mixer::getSysInfo(oss_sysinfo &info) {
	return OK(ioctl, get(), SNDCTL_SYSINFO, &info);
}
