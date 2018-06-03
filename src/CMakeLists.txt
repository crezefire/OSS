if (OSS_ENABLE_BENCHMARKING)
    add_subdirectory(benchmarks)
    set_property(TARGET oss-benchmarks PROPERTY FOLDER "benchmarks")
endif()

if (OSS_ENABLE_TESTING)
    add_subdirectory(tests)
    set_property(TARGET oss-tests PROPERTY FOLDER "tests")
endif()
