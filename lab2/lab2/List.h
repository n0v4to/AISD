#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node<T>* next;
	Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;

public:
	LinkedList() : head(nullptr) {}

	LinkedList(const LinkedList& other) : head(nullptr) {
		if (other.head) {
			head = new Node<T>(other.head->data);
			Node<T>* current = head;
			Node<T>* otherCurrent = other.head->next;

			while (otherCurrent) {
				current->next = new Node<T>(otherCurrent->data);
				current = current->next;
				otherCurrent = otherCurrent->next;
			}
		}
	}

	LinkedList(int size) : head(nullptr) {
		for (int i = 0; i < size; ++i) {
			T value = rand() % 100;
			push_tail(value);
		}
	}

	~LinkedList() {
		while (head) {
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	LinkedList& operator=(const LinkedList& other) {
		if (this != &other) {
			LinkedList temp(other);
			std::swap(head, temp.head);
		}
		return *this;
	}

	void push_tail(const T& value) {
		Node<T>* newNode = new Node<T>(value);
		if (!head) {
			head = newNode;
		}
		else {
			Node<T>* current = head;
			while (current->next) {
				current = current->next;
			}
			current->next = newNode;
		}
	}

	void push_tail(const LinkedList& other) {
		Node<T>* otherCurrent = other.head;
		while (otherCurrent) {
			push_tail(otherCurrent->data);
			otherCurrent = otherCurrent->next;
		}
	}

	void push_head(const T& value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
	}

	void push_head(const LinkedList& other) {
		LinkedList temp(other);
		temp.push_tail(*this);
		*this = temp;
	}

	void pop_head() {
		if (head) {
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void pop_tail() {
		if (!head) {
			return;
		}
		if (!head->next) {
			delete head;
			head = nullptr;
			return;
		}
		Node<T>* current = head;
		while (current->next->next) {
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}

	void delete_node(const T& value) {
		Node<T>* current = head;
		Node<T>* prev = nullptr;

		while (current) {
			if (current->data == value) {
				if (prev) {
					prev->next = current->next;
					delete current;
					current = prev->next;
				}
				else {
					Node<T>* temp = head;
					head = head->next;
					delete temp;
					current = head;
				}
			}
			else {
				prev = current;
				current = current->next;
			}
		}
	}

	const T& operator[](int index) const {
		if (index < 0 || !head) {
			throw std::out_of_range("Index out of range or list is empty");
		}

		Node<T>* current = head;
		for (int i = 0; i < index; ++i) {
			if (!current->next) {
				throw std::out_of_range("Index out of range");
			}
			current = current->next;
		}
		return current->data;
	}

	T& operator[](int index) {
		return const_cast<T&>(static_cast<const LinkedList&>(*this)[index]);
	}
	void printList() const {
		Node<T>* current = head;
		while (current) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	Node<T>* get_head() {
		return head;
	}
	bool empty() const {
		return head == nullptr;
	}

};