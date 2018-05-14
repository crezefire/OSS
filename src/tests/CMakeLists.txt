project(tests
    VERSION 0.0
    LANGUAGES CXX
)

add_executable(tests
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(oss::tests
    ALIAS
        tests
)

target_link_libraries(tests
    INTERFACE
        oss::compile-options-private
    PRIVATE
        oss::ext_google_test
)
