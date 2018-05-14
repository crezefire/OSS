project(oss
    VERSION 0.0
    LANGUAGES CXX
)

add_library(oss
    STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/engine.cpp
)

add_library(oss::oss
    ALIAS
        oss
)

target_include_directories(oss
    PUBLIC
        $<BUILD_INTERFACE:${oss_BINARY_DIR}/include>
        $<BUILD_INTERFACE:${oss_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(oss
    PRIVATE
        oss::compile-options-private
    PUBLIC
        oss::compile-options-public
)

install(
    TARGETS
        oss
    EXPORT
        OSSTargets
    LIBRARY DESTINATION
        lib
    ARCHIVE DESTINATION
        lib
    RUNTIME DESTINATION
        bin
    INCLUDES DESTINATION
        include
    PUBLIC_HEADER DESTINATION
        include
)

install(
    DIRECTORY
        include/
    DESTINATION
        include
)

install(
    EXPORT
        OSSTargets
    FILE
        OSSTargets.cmake
    NAMESPACE
        oss::
    DESTINATION
        lib/cmake/oss
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "OSSConfigVersion.cmake"
    VERSION
        ${oss_VERSION}
    COMPATIBILITY
        SameMajorVersion
)

install(
    FILES
        "OSSConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/OSSConfigVersion.cmake"
    DESTINATION
        lib/cmake/oss
)

export(
    PACKAGE
        oss
)
