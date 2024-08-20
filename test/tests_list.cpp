#include "tests_list.h"

#define __SuitName__ list
#define __Container__ std::list
#include "tests_abstract_container.hpp"


//тест на: вставка элементов в начало
TEST(__SuitName__, PushFront) {
    // Arrange
    const size_t count = 10;
    __Container__<size_t> container;
    size_t array[count];
    // Act
    for (size_t i = 0; i < count; ++i) {
        array[i] = count - i - 1;
        container.push_front(i);
    }

    // Assert
    ASSERT_EQ(container.size(), count);
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(checkContainerDataWithArray(container, array, count));
}

//тест на: удаление элементов из начала
TEST(__SuitName__, PopFront) {
    // Arrange
    const size_t count = 10;
    const size_t count_pop_front = 3;
    __Container__<size_t> container;

    size_t array[count];

    for (size_t i = 0; i < count; ++i) {
        array[i] = i;
        container.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count_pop_front; ++i) {
        container.pop_front();
    }

    // Assert
    ASSERT_EQ(container.size(), static_cast<size_t>(count - count_pop_front));
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(checkContainerDataWithArray(container, array+count_pop_front, count - count_pop_front));
}

void tests_list(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return ;
}