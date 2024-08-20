#include "tests_list.h"
#include "tests_vector.h"
#include <gtest/gtest.h>

int main(int argc, char** argv){
    tests_vector(argc, argv);
    tests_list(argc, argv);
    return RUN_ALL_TESTS();
}
