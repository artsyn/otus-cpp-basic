#include <gtest/gtest.h>
#include "sequential_container.hpp"
#include "linked_container.hpp"

// Последовательный контейнер
TEST(SequentialContainer, DefaultConstructor) {
    SequentialContainer container;
    ASSERT_EQ(container.size(), 0);
}

TEST(SequentialContainer, PushBack) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    ASSERT_EQ(container.size(), 2);
}

TEST(SequentialContainer, InsertAtBeginning) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    container.insert(0, 0);
    ASSERT_EQ(container.size(), 3);
    ASSERT_EQ(container[0], 0);
}

TEST(SequentialContainer, InsertAtMiddle) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    container.insert(1, 5);
    ASSERT_EQ(container.size(), 3);
    ASSERT_EQ(container[1], 5);
}

TEST(SequentialContainer, EraseAtEnd) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    container.erase(1);
    ASSERT_EQ(container.size(), 1);
}

TEST(SequentialContainer, EraseAtBeginning) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    container.erase(0);
    ASSERT_EQ(container.size(), 1);
}

TEST(SequentialContainer, EraseAtMiddle) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.erase(1);
    ASSERT_EQ(container.size(), 2);
}

TEST(SequentialContainer, AccessElements) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    ASSERT_EQ(container[0], 1);
    ASSERT_EQ(container[1], 2);
}

TEST(SequentialContainer, GetSize) {
    SequentialContainer container;
    container.push_back(1);
    container.push_back(2);
    ASSERT_EQ(container.size(), 2);
}

// Контейнер спискового типа
TEST(LinkedContainer, DefaultConstructor) {
    LinkedContainer container;
    ASSERT_EQ(container.size(), 0);
}

TEST(LinkedContainer, PushBack) {
    LinkedContainer container;
    container.push_back(1);
    container.push_back(2);
    ASSERT_EQ(container.size(), 2);
}

TEST(LinkedContainer, InsertAtBeginning) {
    LinkedContainer container;
    container.push_back(1);
    container.push_back(2);
    container.insert(0, 0);
    ASSERT_EQ(container.size(), 3);
    ASSERT_EQ(container[0], 0);
}

TEST(LinkedContainer, InsertAtMiddle) {
    LinkedContainer container;
    container.push_back(1);
    container.push_back(2);
    container.insert(1, 5);
    ASSERT_EQ(container.size(), 3);
    ASSERT_EQ(container[1], 5);
}

TEST(LinkedContainer, EraseAtEnd) {
    LinkedContainer container;
    container.push_back(1);
    container.push_back(2);
    container.erase(1);
        ASSERT_EQ(container.size(), 1);
}

TEST(LinkedContainer, EraseAtBeginning) {
    LinkedContainer container;
    container.push_back(1);
    container.push_back(2);
    container.erase(0);
    ASSERT_EQ(container.size(), 1);
}

TEST(LinkedContainer, EraseAtMiddle) {
    LinkedContainer container;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.erase(1);
    ASSERT_EQ(container.size(), 2);
}

TEST(LinkedContainer, AccessElements) {
    LinkedContainer container;
    container.push_back(1);
    container.push_back(2);
    ASSERT_EQ(container[0], 1);
    ASSERT_EQ(container[1], 2);
}

TEST(LinkedContainer, GetSize) {
    LinkedContainer container;
    container.push_back(1);
    container.push_back(2);
    ASSERT_EQ(container.size(), 2)<< "Size should be 2";
}

// template <typename Container>
// void perform_operations() {
//     Container container;

//     for (int i = 0; i < 10; ++i) {
//         container.push_back(i);
//     }

//     container.print();
//     std::cout << "Size: " << container.size() << std::endl;

//     container.erase(2);
//     container.erase(4);
//     container.erase(6);

//     container.print();

//     container.insert(0, 10);
//     container.print();

//     container.insert(container.size() / 2, 20);
//     container.print();

//     container.push_back(30);
//     container.print();
// }

int main(int argc, char **argv) {
    //std::cout << "Sequential container:" << std::endl;
    //perform_operations<SequentialContainer>();

    //std::cout << "Linked container:" << std::endl;
    //perform_operations<LinkedContainer>();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
