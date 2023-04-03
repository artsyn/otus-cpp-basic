#include <iostream>
#include "sequential_container.hpp"
#include "linked_container.hpp"

template <typename Container>
void perform_operations() {
    Container container;

    for (int i = 0; i < 10; ++i) {
        container.push_back(i);
    }

    container.print();
    std::cout << "Size: " << container.size() << std::endl;

    container.erase(2);
    container.erase(4);
    container.erase(6);

    container.print();

    container.insert(0, 10);
    container.print();

    container.insert(container.size() / 2, 20);
    container.print();

    container.push_back(30);
    container.print();
}

int main() {
    std::cout << "Sequential container:" << std::endl;
    perform_operations<SequentialContainer>();

    std::cout << "Linked container:" << std::endl;
    perform_operations<LinkedContainer>();

    return 0;
}
