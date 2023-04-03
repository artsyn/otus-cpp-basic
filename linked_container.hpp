#pragma once
#include <cstddef>
#include <iostream>

class LinkedContainer {
public:
    LinkedContainer();
    ~LinkedContainer();

    void push_back(int value);
    void insert(size_t index, int value);
    void erase(size_t index);
    size_t size() const;
    int operator[](size_t index) const;
    void print() const;

private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
    };

    Node* head_;
    Node* tail_;
    size_t size_;

    Node* getNode(size_t index) const;
};
