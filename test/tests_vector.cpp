#include "tests_vector.h"

#define __SuitName__ vector
#define __Container__ std::vector
#include "tests_abstract_container.hpp"

void tests_vector(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return;
}