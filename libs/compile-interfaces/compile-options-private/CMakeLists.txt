project(oss-compile-options-private
    VERSION 0.0
    LANGUAGES CXX
)

option(OSS_USE_LIBCXX "Use clangs libcxx. Only works when using clang." OFF)

add_library(oss-compile-options-private
    INTERFACE
)

add_library(oss::compile-options-private
    ALIAS
        oss-compile-options-private
)

if (MSVC)
    target_compile_options(oss-compile-options-private
        INTERFACE
            /GR-    # Disable RTTI
            #/EH-    # Disable exception handling
            /MP     # Multi-process compilation
            # /Za     # Disable language extensions
            $<$<CONFIG:Release>:/WX>     # Warnings as errors
            /FA     # Generate asm
            /permissive-               # Strict conformance                 
            $<$<CONFIG:Release>:/Fa${PROJECT_BINARY_DIR}/asm-output/>        # Assembly location
            $<$<CONFIG:Debug>:/ZI>     # Edit and continue
            $<$<CONFIG:Release>:/GS->  # No Buffer Security Checks
    )
elseif(UNIX)
    target_compile_options(oss-compile-options-private
        INTERFACE
            -fno-rtti
            -flto
            -Wall
            -Werror
            -march=native
            -fno-exceptions
            -pedantic
            $<$<CONFIG:Release>:-save-temps>
            $<$<CONFIG:RelWithDebInfo>:-fno-omit-frame-pointer>
    )

endif()

if (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") AND OSS_USE_LIBCXX)
        target_compile_options(oss-compile-options-private
            INTERFACE
                -stdlib=libc++
        )
endif()

install(
    TARGETS
        oss-compile-options-private
    EXPORT
        OssCompileOptionsPrivateTargets
)

install(
    EXPORT
        OssCompileOptionsPrivateTargets
    FILE
        OssCompileOptionsPrivateTargets.cmake
    NAMESPACE
        oss::
    DESTINATION
        lib/cmake/OssCompileOptionsPrivateTargets
)
