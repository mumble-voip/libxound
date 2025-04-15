// Copyright The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#ifndef CROSSAUDIO_SRC_BACKENDS_OSS_FILEDESCRIPTOR_HPP
#define CROSSAUDIO_SRC_BACKENDS_OSS_FILEDESCRIPTOR_HPP

#include <string_view>

namespace oss {
class FileDescriptor {
public:
	using fd_t = int;

	FileDescriptor();
	FileDescriptor(FileDescriptor &&fd);
	FileDescriptor(fd_t handle);
	~FileDescriptor();

	constexpr explicit operator bool() const { return m_handle != INVALID_HANDLE; }

	FileDescriptor &operator=(FileDescriptor &&fd);

	constexpr fd_t get() const { return m_handle; }

	bool open(std::string_view path, int mode);
	void close();

private:
	static constexpr fd_t INVALID_HANDLE = -1;

	fd_t m_handle;
};
} // namespace oss

#endif
