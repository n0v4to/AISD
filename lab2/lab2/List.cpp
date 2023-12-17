#include "List.h"
#include <iostream>
#include <cstdlib> 

template<typename T>
void delete_i_element(LinkedList<T>& list, int n) {
    if (list.empty()) {
        return;
    }

    Node<T>* slow = list.get_head();
    Node<T>* fast = list.get_head();

    for (int i = 0; i < n; i++) {
        if (!fast) {
            Node<T>* temp = list.get_head();
            list.pop_head();
            delete temp;
            return;
        }
        fast = fast->next;
    }

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    Node<T>* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
}



int main() {
    LinkedList<float> list;
    list.push_tail(17);
    list.push_tail(3);
    list.push_tail(10.2);
    list.push_tail(1);
    list.push_tail(-7);
    list.push_tail(-5.33);
    list.push_tail(-13);
    list.push_tail(4.25);
    list.push_tail(5);
    list.push_tail(4.5);
    cout << "List: ";
    list.printList();
    int i;
    cout << "Index of element (1<i<10)" << endl;
    cin >> i;
    delete_i_element(list, i);
    list.printList();
}