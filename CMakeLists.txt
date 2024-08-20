cmake_minimum_required(VERSION 3.2)

project(testContaners)

# Lookup for pre-built gtest
find_package(GTest)

# Test target
add_executable(
    test_list
    test/tests_abstract_container.hpp
    test/containers_tests.cpp
    test/tests_list.cpp
    test/tests_vector.cpp
)

message(STATUS ${GTEST_INCLUDE_DIRS})
message(STATUS ${GTEST_BOTH_LIBRARIES})
message(===============)
# Add googletest to the include directories for the test target
target_include_directories(
    test_list PRIVATE
    test/include
    ${GTEST_INCLUDE_DIRS}
)

# Link test target against gtest libraries
target_link_libraries(
    test_list PRIVATE
    ${GTEST_LIBRARIES}
    ${GTEST_BOTH_LIBRARIES}
)

set_target_properties(test_list PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

if (MSVC)
    target_compile_options(
        test_list PRIVATE
        /W4
    )
else ()
    target_compile_options(
        test_list PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
