#undef __CreateContainer__
#undef __AddToContainer__
#undef __DeleteFromContainer__
#undef __GetElements__
#undef __GetProperties__
#undef __Container__

#include <vector>
#define __CreateContainer__ CreateVector
#define __AddToContainer__ AddToVector 
#define __DeleteFromContainer__ DeleteFromVector
#define __GetElements__ GetElementsFromVector
#define __GetProperties__ GetPropertiesFromVector
#define __Container__ std::vector
#include "tests_container.hpp"

#undef __CreateContainer__
#undef __AddToContainer__
#undef __DeleteFromContainer__
#undef __GetElements__
#undef __GetProperties__
#undef __Container__

#include <list>
#define __CreateContainer__ CreateList
#define __AddToContainer__ AddToList 
#define __DeleteFromContainer__ DeleteFromList
#define __GetElements__ GetElementsFromList
#define __GetProperties__ GetPropertiesFromList
#define __Container__ std::list
#include "tests_container.hpp"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}