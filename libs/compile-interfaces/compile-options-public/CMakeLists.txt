project(oss-compile-options-public
    VERSION 0.0
    LANGUAGES CXX
)

add_library(oss-compile-options-public
    INTERFACE
)

add_library(oss::compile-options-public
    ALIAS
        oss-compile-options-public
)

if (MSVC)
    target_compile_options(oss-compile-options-public
        INTERFACE
            /Oi         # Enable intrinsic functions
            /std:c++17  # Enable C++ 17 features
    )
elseif (UNIX)
    target_compile_options(oss-compile-options-public
        INTERFACE
            -std=c++17
    )
endif()

install(
    TARGETS
        oss-compile-options-public
    EXPORT
        CompileOptionsPublicTargets
)

install(
    EXPORT
        CompileOptionsPublicTargets
    FILE
        CompileOptionsPublicTargets.cmake
    NAMESPACE
        oss::
    DESTINATION
        lib/cmake/CompileOptionsPublicTargets
)
