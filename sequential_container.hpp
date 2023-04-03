#pragma once
#include <vector>
#include <iostream>

class SequentialContainer {
public:
    void push_back(int value);
    void insert(size_t index, int value);
    void erase(size_t index);
    size_t size() const;
    int operator[](size_t index) const;
    void print() const;

private:
    std::vector<int> data_;
};