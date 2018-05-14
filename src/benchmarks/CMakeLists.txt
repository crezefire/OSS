project(benchmarks
    VERSION 0.0
    LANGUAGES CXX
)

add_executable(benchmarks
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(oss::benchmarks
    ALIAS
        benchmarks
)

target_link_libraries(benchmarks
    INTERFACE
        oss::compile-options-private
)

if (MSVC)
    target_link_libraries(benchmarks
        PRIVATE
            oss::ext_google_benchmark $<$<CONFIG:Release>:-LTCG>
    )
else()
    target_link_libraries(benchmarks
        PRIVATE
            oss::ext_google_benchmark
    )
endif()
