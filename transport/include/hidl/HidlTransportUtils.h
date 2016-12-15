/*
 * Copyright (C) 2016 The Android Open Source Project
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

#ifndef ANDROID_HIDL_TRANSPORT_UTILS_H
#define ANDROID_HIDL_TRANSPORT_UTILS_H

#include <android/hidl/base/1.0/IBase.h>

namespace android {
namespace hardware {

/*
 * Verifies the interface chain of 'interface' contains 'castTo'
 */
inline bool canCastInterface(::android::hidl::base::V1_0::IBase* interface, const char* castTo) {
    if (interface == nullptr) {
        return false;
    }

    bool canCast = false;
    interface->interfaceChain([&](const hidl_vec<hidl_string> &types) {
        for (size_t i = 0; i < types.size(); i++) {
            if (types[i] == castTo) {
                canCast = true;
                break;
            }
        }
    });
    return canCast;
}

}   // namespace hardware
}   // namespace android

#endif //ANDROID_HIDL_TRANSPORT_UTILS_H
