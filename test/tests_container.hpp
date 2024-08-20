#include <algorithm>

#include <gtest/gtest.h>

//сравнение данных листа и массива
template <typename T>
bool checkContainerDataWithArray(const __Container__ <T> & container, const T* array,
                            size_t array_len) {
    int index = 0;
    if (container.size() != array_len) {
        return false;
    }
    for (auto const& elem : container) {
        if (elem != array[index]) {
            return false;
        }
        index++;
    }
    return true;
}

//тест на создание контейнера пустого
TEST(__CreateContainer__, Empty) {
    // Act (empty for this test)
    __Container__<int> container;

    // Assert
    ASSERT_EQ(container.size(), static_cast<size_t>(0));
    ASSERT_TRUE(container.empty());
}

//TODO тест на вызов и уничтожение деструктора сделать: т.е. повесить mock????
//тест на создание контейнера непустого с инициализацией массивом
TEST(__CreateContainer__, fromArray) {
    // Arrange
    static const size_t numsCount = 5;
    const int nums[numsCount] = {2, 0, 6, -14, 5};

    // Act (empty for this test)
    __Container__<int> container{nums, nums + numsCount};

    // Assert
    ASSERT_EQ(container.size(), static_cast<size_t>(numsCount));
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(checkContainerDataWithArray(container, nums, numsCount));
}

//тест на: вставка элементов в конец
TEST(__AddToContainer__, PushBack) {
    // Arrange
    const size_t count = 10;
    __Container__<size_t> container;
    size_t array[count];
    // Act
    for (size_t i = 0; i < count; ++i) {
        array[i] = i;
        container.push_back(i);
    }

    // Assert
    ASSERT_EQ(container.size(), count);
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(checkContainerDataWithArray(container, array, count));
}
/*TODO
#ifdef TEST_LIST
//тест на: вставка элементов в начало
TEST(AddToContainer, PushFront) {
    // Arrange
    const size_t count = 10;
    container<size_t> container;
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
#endif
*/
//тест на: вставка элементов в начало
TEST(__AddToContainer__, InsertFront) {
    // Arrange
    const size_t count = 10;
    __Container__<size_t> container;
    size_t array[count];
    // Act
    for (size_t i = 0; i < count; ++i) {
        array[i] = count - i - 1;
        container.insert(container.begin(),i);
    }

    // Assert
    ASSERT_EQ(container.size(), count);
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(checkContainerDataWithArray(container, array, count));
}

//тест на: вставка элементов в середину
TEST(__AddToContainer__, PushMiddle) {
    // Arrange
    const size_t count = 10;
    __Container__<size_t> container;
    size_t arrayFirst[count];
    size_t insertValue = 111;
    const size_t insert_length = 1;
    size_t arrayLast[count];

    for (size_t i = 0; i < count; ++i) {
        arrayFirst[i] = i;
        container.push_back(i);
    }
    for (size_t i = 0; i < count; ++i) {
        arrayLast[i] = i;
        container.push_back(i);
    }
    auto it = container.begin();
    advance(it, count);

    // Act
    container.insert(it, insert_length, insertValue);

    size_t ResArray[count + insert_length + count];
    std::copy(arrayFirst, arrayFirst + count, ResArray);
    ResArray[count] = insertValue;
    std::copy(arrayLast, arrayLast + count, ResArray + count + insert_length);

    // Assert
    ASSERT_EQ(container.size(), count + insert_length + count);
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(
        checkContainerDataWithArray(container, ResArray, count + insert_length + count));
}

//тест на: удаление элементов из конца
TEST(__DeleteFromContainer__, PopBack) {
    // Arrange
    const size_t count = 10;
    const size_t count_pop_back = 4;
    __Container__<size_t> container;

    size_t array[count];

    for (size_t i = 0; i < count; ++i) {
        array[i] = i;
        container.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count_pop_back; ++i) {
        container.pop_back();
    }

    // Assert
    ASSERT_EQ(container.size(), static_cast<size_t>(count - count_pop_back));
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(checkContainerDataWithArray(container, array, count - count_pop_back));
}

/*
#ifdef TEST_LIST
//тест на: удаление элементов из начала
TEST(DeleteFromContainer, PopFront) {
    // Arrange
    const size_t count = 10;
    const size_t count_pop_front = 3;
    container<size_t> container;

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
#endif
*/

//тест на: удаление элементов из начала
TEST(__DeleteFromContainer__, Erase) {
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
        container.erase(container.begin());
    }

    // Assert
    ASSERT_EQ(container.size(), static_cast<size_t>(count - count_pop_front));
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(checkContainerDataWithArray(container, array+count_pop_front, count - count_pop_front));
}

//тест на: удаление элементов из середины
TEST(__DeleteFromContainer__, EraseMiddle) {
    // Arrange
    const size_t count = 5;
    const size_t res_count = 4;
    const size_t middle = 3;
    size_t array[count] = {3,2,5,7,3};
    size_t res_array[count] = {3,2,7,3};
    __Container__<size_t> container (array, array + count);
    auto it = container.begin();
    advance(it,middle-1);

    //Act
    container.erase(it);

    // Assert
    ASSERT_EQ(container.size(), res_count);
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(checkContainerDataWithArray(container, res_array, res_count));
}

//тест на: получение и проверку всех элементов контейнера
TEST(__GetElements__, GetNext) {
    // Arrange
    __Container__<int> container;
    for (int i = 0 ; i < 5 ; i++)
        container.push_back(i);

    auto it = container.begin();
    for (int i = 0 ; i < 5 ; i++)
        ASSERT_EQ(*it++, i);
}

//тест на получение размера контейнера
TEST(__GetProperties__, GetSize) {
    // Act
    __Container__<int> container{0,0,0,0,0};

    // Assert
    ASSERT_EQ(container.size(), static_cast<size_t>(5));
}

