#include <algorithm>
#include <list>

#include <gtest/gtest.h>

//#define DEBUG_OUT

struct BaseListFixture : public testing::Test {

    // Arrange
    static const size_t numsCount = 5;

    // Arrange
    const int nums[numsCount];

    BaseListFixture() : nums{2, 0, 6, -14, 5} {}

    // Per-test-suite set-up.
    static void SetUpTestSuite() {
        std::cout << "SetUpTestSuite" << std::endl;
    }

    // Per-test-suite tear-down.
    static void TearDownTestSuite() {
        std::cout << "TearDownTestSuite" << std::endl;
    }

    // Per-test set-up
    void SetUp() override {
        std::cout << "SetUp" << std::endl;
    }

    // You can define per-test tear-down logic as usual.
    void TearDown() override {
        std::cout << "TearDown" << std::endl;
        // Nothing to do for now
    }
};

//сравнение данных листа и массива
template <typename T>
bool checkListDataWithArray(const std::list<T>& list, const T* array,
                            size_t array_len) {
    int index = 0;
    if (list.size() != array_len) {
#ifdef DEBUG_OUT
        std::cout << "Bad size..." << std::endl;
#endif
        return false;
    }
    for (auto const& elem : list) {
#ifdef DEBUG_OUT
        std::cout << "elem == " << elem << " ,"
                  << "array[index] == " << array[index] << std::endl;
#endif
        if (elem != array[index]) {
            return false;
        }
        index++;
    }
    return true;
}

struct CreateListFixture : public BaseListFixture {};

//тест на создание контейнера пустого
TEST_F(CreateListFixture, Empty) {
    // Act (empty for this test)
    std::list<int> list;

    // Assert
    ASSERT_EQ(list.size(), static_cast<size_t>(0));
    ASSERT_TRUE(list.empty());
}

//TODO тест на вызов и уничтожение деструктора сделать: т.е. повесить mock????
//тест на создание контейнера непустого с инициализацией массивом
TEST_F(CreateListFixture, fromArray) {
    // Act (empty for this test)
    std::list<int> list{nums, nums + numsCount};

    // Assert
    ASSERT_EQ(list.size(), static_cast<size_t>(numsCount));
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(checkListDataWithArray(list, nums, numsCount));
}

//тест на: вставка элементов в конец
TEST(AddToList, PushBack) {
    // Arrange
    const size_t count = 10;
    std::list<size_t> list;
    size_t array[count];
    // Act
    for (size_t i = 0; i < count; ++i) {
        array[i] = i;
        list.push_back(i);
    }

    // Assert
    ASSERT_EQ(list.size(), count);
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(checkListDataWithArray(list, array, count));
}

//тест на: вставка элементов в начало
TEST(AddToList, PushFront) {
    // Arrange
    const size_t count = 10;
    std::list<size_t> list;
    size_t array[count];
    // Act
    for (size_t i = 0; i < count; ++i) {
        array[i] = count - i - 1;
        list.push_front(i);
    }

    // Assert
    ASSERT_EQ(list.size(), count);
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(checkListDataWithArray(list, array, count));
}

//тест на: вставка элементов в середину
TEST(AddToList, PushMiddle) {
    // Arrange
    const size_t count = 10;
    std::list<size_t> list;
    size_t arrayFirst[count];
    size_t insertValue = 111;
    const size_t insert_length = 1;
    size_t arrayLast[count];

    for (size_t i = 0; i < count; ++i) {
        arrayFirst[i] = i;
        list.push_back(i);
    }
    for (size_t i = 0; i < count; ++i) {
        arrayLast[i] = i;
        list.push_back(i);
    }
    auto it = list.begin();
    advance(it, count);

    // Act
    list.insert(it, insert_length, insertValue);

    size_t ResArray[count + insert_length + count];
    std::copy(arrayFirst, arrayFirst + count, ResArray);
    ResArray[count] = insertValue;
    std::copy(arrayLast, arrayLast + count, ResArray + count + insert_length);

    // Assert
    ASSERT_EQ(list.size(), count + insert_length + count);
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(
        checkListDataWithArray(list, ResArray, count + insert_length + count));
}

//тест на: удаление элементов из конца
TEST(DeleteFromList, PopBack) {
    // Arrange
    const size_t count = 10;
    const size_t count_pop_back = 4;
    std::list<size_t> list;

    size_t array[count];

    for (size_t i = 0; i < count; ++i) {
        array[i] = i;
        list.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count_pop_back; ++i) {
        list.pop_back();
    }

    // Assert
    ASSERT_EQ(list.size(), static_cast<size_t>(count - count_pop_back));
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(checkListDataWithArray(list, array, count - count_pop_back));
}

//тест на: удаление элементов из начала
TEST(DeleteFromList, PopFront) {
    // Arrange
    const size_t count = 10;
    const size_t count_pop_front = 3;
    std::list<size_t> list;

    size_t array[count];

    for (size_t i = 0; i < count; ++i) {
        array[i] = i;
        list.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count_pop_front; ++i) {
        list.pop_front();
    }

    // Assert
    ASSERT_EQ(list.size(), static_cast<size_t>(count - count_pop_front));
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(checkListDataWithArray(list, array+count_pop_front, count - count_pop_front));
}

//тест на: удаление элементов из середины
TEST(DeleteFromList, EraseMiddle) {
    // Arrange
    const size_t count = 5;
    const size_t res_count = 4;
    const size_t middle = 3;
    size_t array[count] = {3,2,5,7,3};
    size_t res_array[count] = {3,2,7,3};
    std::list<size_t> list (array, array + count);
    auto it = list.begin();
    advance(it,middle-1);

    //Act
    list.erase(it);

    // Assert
    ASSERT_EQ(list.size(), res_count);
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(checkListDataWithArray(list, res_array, res_count));
}

//тест на: получение и проверку всех элементов контейнера
TEST(GetElements, GetNext) {
    // Arrange
    std::list<int> list;
    for (int i = 0 ; i < 5 ; i++)
        list.push_back(i);

    auto it = list.begin();
    for (int i = 0 ; i < 5 ; i++)
        ASSERT_EQ(*it++, i);
}

//тест на получение размера контейнера
TEST(GetProperties, GetSize) {
    // Act
    std::list<int> list{0,0,0,0,0};

    // Assert
    ASSERT_EQ(list.size(), static_cast<size_t>(5));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}