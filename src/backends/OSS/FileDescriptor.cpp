// Copyright The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#include "FileDescriptor.hpp"

#include "ErrorCheck.hpp"

#include <utility>

#include <fcntl.h>
#include <unistd.h>

using namespace oss;

FileDescriptor::FileDescriptor() : m_handle(INVALID_HANDLE) {
}

FileDescriptor::FileDescriptor(FileDescriptor &&fd) : m_handle(std::exchange(fd.m_handle, INVALID_HANDLE)) {
}

FileDescriptor::FileDescriptor(const fd_t handle) : m_handle(handle) {
}

FileDescriptor::~FileDescriptor() {
	close();
}

FileDescriptor &FileDescriptor::operator=(FileDescriptor &&fd) {
	m_handle = std::exchange(fd.m_handle, INVALID_HANDLE);
	return *this;
}

bool FileDescriptor::open(const std::string_view path, const int mode) {
	if (*this) {
		close();
	}

	if (m_handle = ::open(path.data(), mode, 0); m_handle == INVALID_HANDLE) {
		printFuncError("open", errno);
		return false;
	}

	return true;
}

void FileDescriptor::close() {
	if (*this) {
		::close(m_handle);
		m_handle = INVALID_HANDLE;
	}
}
