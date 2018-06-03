# External libraries
if (OSS_ENABLE_BENCHMARKING)
    
    if(NOT TARGET benchmark)
        set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
        set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
        set(BENCHMARK_ENABLE_EXCEPTIONS OFF CACHE BOOL "" FORCE)
        set(BENCHMARK_ENABLE_LTO ON CACHE BOOL "" FORCE)
        set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)

        if (OSS_USE_LIBCXX)
            set(BENCHMARK_USE_LIBCXX ON CACHE BOOL "" FORCE)
        endif()
        
        add_subdirectory(external/google/benchmark/ external/google/benchmark)
        set_property(TARGET benchmark PROPERTY FOLDER "external-libs")
    endif()

    add_library(oss::ext_google_benchmark
        ALIAS
            benchmark
    )
endif()

if (OSS_ENABLE_TESTING)

    if(NOT TARGET gtest_main)
        set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
        set(BUILD_GTEST ON CACHE BOOL "" FORCE)
        set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
        set(INSTALL_GMOCK OFF CACHE BOOL "" FORCE)
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

        add_subdirectory(external/google/googletest/ external/google/googletest)
        
        set_property(TARGET gtest_main PROPERTY FOLDER "external-libs")
        set_property(TARGET gtest PROPERTY FOLDER "external-libs")
    endif()


    add_library(oss::ext_google_test
        ALIAS
            gtest_main
    )
endif()

# Internal libraries
add_subdirectory(compile-interfaces/compile-options-private/)
add_subdirectory(compile-interfaces/compile-options-public/)

add_subdirectory(oss/)
set_property(TARGET oss PROPERTY FOLDER "libs")
