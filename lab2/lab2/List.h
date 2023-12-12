#pragma once
#include <iostream>
#include <random>

inline int random(int x, int y) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(x, y);
    return dist(gen);
}

template <typename T>
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int size;

    void clear() {
        while (head != nullptr) {
            pop_head();
        }
    };

public:
    LinkedList() {
        head = nullptr;
    }

    LinkedList(const LinkedList& other) {

    }

    LinkedList(int size, int minVal, int maxVal) {

    }

    ~LinkedList() {

    }

    LinkedList& operator=(const LinkedList& other) {

        return *this;
    }

    void push_tail(int value) {

    }

    void push_tail(const LinkedList& other) {

    }

    void push_head(int value) {

    }

    void push_head(const LinkedList& other) {

    }

    void pop_head() {

    }

    void pop_tail() {

    }

    void delete_node(int value) {

    }

    int& operator[](int index) {

    }

    const int& operator[](int index) const {

    }
};