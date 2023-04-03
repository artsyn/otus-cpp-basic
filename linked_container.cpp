#include "linked_container.hpp"

LinkedContainer::LinkedContainer() : head_(nullptr), tail_(nullptr), size_(0) {}

LinkedContainer::~LinkedContainer() {
    while (head_) {
        Node* temp = head_->next;
        delete head_;
        head_ = temp;
    }
}

void LinkedContainer::push_back(int value) {
    Node* new_node = new Node{value, tail_, nullptr};

    if (tail_) {
        tail_->next = new_node;
    } else {
        head_ = new_node;
    }
    tail_ = new_node;
    ++size_;
}

void LinkedContainer::insert(size_t index, int value) {
    if (index <= size_) {
        if (index == size_) {
            push_back(value);
        } else {
            Node* current = getNode(index);
            Node* new_node = new Node{value, current->prev, current};

            if (current->prev) {
                current->prev->next = new_node;
            } else {
                head_ = new_node;
            }
            current->prev = new_node;
            ++size_;
        }
    }
}

void LinkedContainer::erase(size_t index) {
    if (index < size_) {
        Node* current = getNode(index);

        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head_ = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail_ = current->prev;
        }

        delete current;
        --size_;
    }
}

size_t LinkedContainer::size() const {
    return size_;
}

int LinkedContainer::operator[](size_t index) const {
    return getNode(index)->value;
}

void LinkedContainer::print() const {
    Node* current = head_;
    while (current) {
        std::cout << current->value << ", ";
        current = current->next;
    }
    std::cout << std::endl;
}

LinkedContainer::Node* LinkedContainer::getNode(size_t index) const {
    Node* current = head_;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}
