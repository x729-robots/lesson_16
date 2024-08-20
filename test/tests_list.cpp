#include "tests_list.h"

#include <list>
#define __CreateContainer__ CreateList
#define __AddToContainer__ AddToList 
#define __DeleteFromContainer__ DeleteFromList
#define __GetElements__ GetElementsFromList
#define __GetProperties__ GetPropertiesFromList
#define __Container__ std::list
#include "tests_abstract_container.hpp"

int tests_list(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}