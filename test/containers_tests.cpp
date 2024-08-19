#define VECTOR 0
#define LIST 1
#define TEST_CONTAINER LIST

#include "tests_container.hpp"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}