#pragma once

#include <string_view>
#include <optional>

namespace oss {

struct Window {
    struct Handle {
        void* WindowsHandle;
    };

    static std::optional<Handle> CreateOSWindow(std::string_view name, int const width, int const height);

    static bool RunOSUpdateLoop();
};

} // namespace oss
