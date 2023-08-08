#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        
        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteNode(int val) {
        Node* current = head;

        while (current) {
            if (current->data == val) {
                if (current == head) {
                    head = current->next;
                    if (head) head->prev = nullptr;
                } else if (current == tail) {
                    tail = current->prev;
                    if (tail) tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                delete current;
                break;
            }

            current = current->next;
        }
    }

    void traverseForward() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void traverseBackward() {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtBeginning(0);
    dll.insertAtEnd(3);

    dll.traverseForward();  // Output: 0 1 2 3
    dll.traverseBackward(); // Output: 3 2 1 0

    dll.deleteNode(1);
    dll.deleteNode(3);

    dll.traverseForward();  // Output: 0 2

    return 0;
}
