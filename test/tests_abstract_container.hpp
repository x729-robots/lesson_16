#include <algorithm>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

//сравнение данных листа и массива
template <typename T>
bool checkContainerDataWithArray(const __Container__<T>& container,
                                 const T* array, size_t array_len) {
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

//тест: создание контейнера (пустого)
TEST(__SuitName__, Empty) {
    // Act (empty for this test)
    __Container__<int> container;

    // Assert
    ASSERT_EQ(container.size(), static_cast<size_t>(0));
    ASSERT_TRUE(container.empty());
}

// TODO тест на вызов и уничтожение деструктора сделать: т.е. повесить mock????
//тест: создание контейнера (непустого с инициализацией массивом)
TEST(__SuitName__, fromArray) {
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

//тест: вставка элементов в конец
TEST(__SuitName__, PushBack) {
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

//тест: вставка элементов в начало
TEST(__SuitName__, InsertFront) {
    // Arrange
    const size_t count = 10;
    __Container__<size_t> container;
    size_t array[count];
    // Act
    for (size_t i = 0; i < count; ++i) {
        array[i] = count - i - 1;
        container.insert(container.begin(), i);
    }

    // Assert
    ASSERT_EQ(container.size(), count);
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(checkContainerDataWithArray(container, array, count));
}

//тест: вставка элементов в середину
TEST(__SuitName__, PushMiddle) {
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
    ASSERT_TRUE(checkContainerDataWithArray(container, ResArray,
                                            count + insert_length + count));
}

//тест: удаление элементов из конца
TEST(__SuitName__, PopBack) {
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
    ASSERT_TRUE(
        checkContainerDataWithArray(container, array, count - count_pop_back));
}

//тест: удаление элементов из начала
TEST(__SuitName__, Erase) {
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
    ASSERT_TRUE(checkContainerDataWithArray(container, array + count_pop_front,
                                            count - count_pop_front));
}

//тест: удаление элементов из середины
TEST(__SuitName__, EraseMiddle) {
    // Arrange
    const size_t count = 5;
    const size_t res_count = 4;
    const size_t middle = 3;
    size_t array[count] = {3, 2, 5, 7, 3};
    size_t res_array[count] = {3, 2, 7, 3};
    __Container__<size_t> container(array, array + count);
    auto it = container.begin();
    advance(it, middle - 1);

    // Act
    container.erase(it);

    // Assert
    ASSERT_EQ(container.size(), res_count);
    ASSERT_FALSE(container.empty());
    ASSERT_TRUE(checkContainerDataWithArray(container, res_array, res_count));
}

//тест: получение элементов из контейнера (проверку всех элементов)
TEST(__SuitName__, GetNext) {
    // Arrange
    __Container__<int> container;
    for (int i = 0; i < 5; i++)
        container.push_back(i);

    auto it = container.begin();
    for (int i = 0; i < 5; i++)
        ASSERT_EQ(*it++, i);
}

//тест: получение размера контейнера (фактическое количество элементов)
TEST(__SuitName__, GetSize) {
    // Act
    __Container__<int> container{0, 0, 0, 0, 0};

    // Assert
    ASSERT_EQ(container.size(), static_cast<size_t>(5));
}

//тест: копирование контейнера (Дополнительное задание 1)
TEST(__SuitName__, CopyContaner) {
    // Arrange
    __Container__<int> container1;
    for (int i = 0; i < 5; i++)
        container1.push_back(i);
    __Container__<int> container2;

    // Assert
    container2 = container1;

    auto it = container2.begin();
    for (int i = 0; i < 5; i++)
        ASSERT_EQ(*it++, i);
}

struct CDestructorInterface {
  public:
    virtual void constructorCalled() = 0;
    virtual void destructorCalled() = 0;
};

class CTest {
  public:
    CTest(int value, CDestructorInterface* m_interface)
        : m_interface(m_interface), item(value) {
        m_interface->constructorCalled();
    };
    ~CTest() {
        m_interface->destructorCalled();
    };
    CDestructorInterface* m_interface;

  private:
    int item;
};

// gmock object implementation
struct MockCTest : CDestructorInterface {
    MOCK_METHOD(void, constructorCalled, (), (override));
    MOCK_METHOD(void, destructorCalled, (), (override));
};

using ::testing::NiceMock;

//тест: удаление контейнера (Дополнительное задание 2)
TEST(__SuitName__, DeleteContaner) {
    // Arrange
    NiceMock<MockCTest> m_mockCTest;
    __Container__<CTest> container1;
    for (int i = 0; i < 3; i++)
        container1.push_back(CTest(0, &m_mockCTest));

    // Assert
    EXPECT_CALL(m_mockCTest, constructorCalled()).Times(0);
    EXPECT_CALL(m_mockCTest, destructorCalled()).Times(3);
}

class CTestMove {
  public:
    explicit CTestMove() {
        // callNumber=riseCallNumber();
        static int item = 0;
        item++;
        callNumber = &item;
        std::cout << "============" << "CONSTRUCTOR______" << std::endl;
    };
    ~CTestMove(){};
    int getCallNumber(){
        return *callNumber;
    }
    // int * riseCallNumber(){
    //
    //}
  private:
    int* callNumber;
};

//тест: проверка работы перемещающего оператора присваивания
TEST(__SuitName__, MoveContaner) {
    // Arrange
    CTestMove m_testmove_1;
    CTestMove m_testmove_2;
    __Container__<CTestMove> container1;
    __Container__<CTestMove> container2;
    __Container__<CTestMove> container3;

    container1.push_back(std::move(m_testmove_1));
    container1.push_back(m_testmove_2);

    // Action
    container2 = container1; //check copy operator

    std::cout << "============" << container2.begin()->getCallNumber() << std::endl;

    // Action
    // container3 = std::move(container2); //check copy operator

    // Assert
    // EXPECT_CALL(m_mockCTest, constructorCalled()).Times(3);
    // EXPECT_CALL(m_mockCTest_1, destructorCalled()).Times(2);
    // EXPECT_CALL(m_mockCTest_2, destructorCalled()).Times(2);
}
