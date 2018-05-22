if (OSS_ENABLE_BENCHMARKING)
    add_subdirectory(benchmarks)
    set_property(TARGET oss-benchmarks PROPERTY FOLDER "src")
endif()

if (OSS_ENABLE_TESTING)
    add_subdirectory(tests)
    set_property(TARGET oss-tests PROPERTY FOLDER "src")
endif()
