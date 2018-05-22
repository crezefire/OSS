project(oss-benchmarks
    VERSION 0.0
    LANGUAGES CXX
)

add_executable(oss-benchmarks
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(oss::oss-benchmarks
    ALIAS
        oss-benchmarks
)

target_link_libraries(oss-benchmarks
    INTERFACE
        oss::compile-options-private
)

if (MSVC)
    target_link_libraries(oss-benchmarks
        PRIVATE
            oss::ext_google_benchmark $<$<CONFIG:Release>:-LTCG>
    )
else()
    target_link_libraries(oss-benchmarks
        PRIVATE
            oss::ext_google_benchmark
    )
endif()
