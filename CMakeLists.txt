cmake_minimum_required(VERSION 3.2)

project(testContaners)

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest" 
)

# Test target
add_executable(
    test_list
    test/containers_tests.cpp
    test/tests_abstract_container.hpp
    test/tests_list.cpp
    test/tests_vector.cpp
)

target_include_directories(
    test_list PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/test/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/test"
)

target_link_libraries(
    test_list PRIVATE
    gtest gtest_main gmock
)

set_target_properties(test_list PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

target_compile_options(
    test_list PRIVATE
        -Wall -Wextra -pedantic -Werror
    )

#message(STATUS ${GTEST_INCLUDE_DIRS})
#message(STATUS ${GTEST_BOTH_LIBRARIES})
#message(===============)
## Add googletest to the include directories for the test target
#target_include_directories(
#    test_list PRIVATE
#    "${CMAKE_CURRENT_SOURCE_DIR}/test/include"
#    #${GTEST_INCLUDE_DIRS}
#    /root/googletest_prebuild/include
#)
#
## Link test target against gtest libraries
#target_link_libraries(
#    test_list PRIVATE
#    #gtest gtest_main gmock
#    -L/root/googletest_prebuild/lib/
#    #/root/googletest_prebuild/lib/gtest_main.a
#    #/root/googletest_prebuild/lib/gmock.a
#    #${GTEST_LIBRARIES}
#    ${GTEST_BOTH_LIBRARIES}
#)
#
#set_target_properties(test_list PROPERTIES CXX_STANDARD 17 #CXX_STANDARD_REQUIRED ON)
#
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
#
#if (MSVC)
#    target_compile_options(
#        test_list PRIVATE
#        /W4
#    )
#else ()
#    target_compile_options(
#        test_list PRIVATE
#        -Wall -Wextra -pedantic -Werror
#    )
#endif()
