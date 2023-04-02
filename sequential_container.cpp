#include "sequential_container.hpp"

void SequentialContainer::push_back(int value) {
    data_.push_back(value);
}

void SequentialContainer::insert(size_t index, int value) {
    if (index <= data_.size()) {
        data_.insert(data_.begin() + index, value);
    }
}

void SequentialContainer::erase(size_t index) {
    if (index < data_.size()) {
        data_.erase(data_.begin() + index);
    }
}

size_t SequentialContainer::size() const {
    return data_.size();
}

int SequentialContainer::operator[](size_t index) const {
    return data_.at(index);
}

void SequentialContainer::print() const {
    for (int value : data_) {
        std::cout << value << ", ";
    }
    std::cout << std::endl;
}
