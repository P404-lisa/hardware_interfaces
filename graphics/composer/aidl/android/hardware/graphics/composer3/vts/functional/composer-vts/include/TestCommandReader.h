/**
 * Copyright (c) 2021, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

// TODO(b/129481165): remove the #pragma below and fix conversion issues
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"

#include <android/hardware/graphics/composer3/command-buffer.h>

// TODO(b/129481165): remove the #pragma below and fix conversion issues
#pragma clang diagnostic pop  // ignored "-Wconversion

namespace aidl::android::hardware::graphics::composer3::vts {

class TestCommandReader : public CommandReaderBase {
  public:
    virtual ~TestCommandReader() = default;

    std::vector<std::pair<uint32_t, uint32_t>> mErrors;
    std::vector<std::pair<uint64_t, uint32_t>> mCompositionChanges;

    // Parse all commands in the return command queue.  Call GTEST_FAIL() for
    // unexpected errors or commands.
    void parse();
    virtual void parseSingleCommand(int32_t commandRaw, uint16_t length);
};
}  // namespace aidl::android::hardware::graphics::composer3::vts
