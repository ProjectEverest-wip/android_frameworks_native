/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <binder/ParcelFileDescriptor.h>

namespace android {
namespace os {

using android::binder::unique_fd;

ParcelFileDescriptor::ParcelFileDescriptor() = default;

ParcelFileDescriptor::ParcelFileDescriptor(unique_fd fd) : mFd(std::move(fd)) {}

ParcelFileDescriptor::~ParcelFileDescriptor() = default;

status_t ParcelFileDescriptor::writeToParcel(Parcel* parcel) const {
    return parcel->writeDupParcelFileDescriptor(mFd.get());
}

status_t ParcelFileDescriptor::readFromParcel(const Parcel* parcel) {
    return parcel->readUniqueParcelFileDescriptor(&mFd);
}

} // namespace os
} // namespace android
