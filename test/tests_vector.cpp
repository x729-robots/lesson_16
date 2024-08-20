#include "tests_vector.h"

#include <vector>
#define __CreateContainer__ CreateVector
#define __AddToContainer__ AddToVector 
#define __DeleteFromContainer__ DeleteFromVector
#define __GetElements__ GetElementsFromVector
#define __GetProperties__ GetPropertiesFromVector
#define __Container__ std::vector
#include "tests_container.hpp"

int tests_vector(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}