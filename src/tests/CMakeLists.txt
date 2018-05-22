project(oss-tests
    VERSION 0.0
    LANGUAGES CXX
)

add_executable(oss-tests
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(oss::oss-tests
    ALIAS
        oss-tests
)

target_link_libraries(oss-tests
    INTERFACE
        oss::compile-options-private
    PRIVATE
        oss::ext_google_test
)
