#include "tests_list.h"
#include <list>
#define __Container__ std::list
#include "tests_container.hpp"

int tests_list(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}