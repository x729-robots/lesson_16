cmake_minimum_required(VERSION 3.2)

project(testContaners)

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    #By default, new Visual Studio projects link the C runtimes dynamically
    #but GoogleTest links them statically. This will generate an error
    #Enabling this option will make gtest link the runtimes dynamically too
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest" 
)

# Test target
add_executable(
    test_container
    test/containers_tests.cpp
    test/tests_abstract_container.hpp
    test/tests_list.cpp
    test/tests_vector.cpp
)

target_include_directories(
    test_container PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/test/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/test"
)

target_link_libraries(
    test_container PRIVATE
    gtest gtest_main gmock
)

set_target_properties(test_container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

if (MSVC)
    target_compile_options(
        test_container PRIVATE
        /W4
    )
else ()
    target_compile_options(
        test_container PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()