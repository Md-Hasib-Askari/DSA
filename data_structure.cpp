#include <iostream>
using namespace std;

// Node class for any datatype
template<class T>
class Node {
public:
    T value;
    Node *next;

    // For giving value and making the next node null
    Node(T v) {
        value = v;
        next = NULL;
    }
};

// Linked List Class for any datatype
template<class T>
class LinkedList {
    Node<T> *head = NULL; // taking head as NULL
public:
    // append() - for appending new value to the list
    void append(T v) {
        Node<T> *p = head;
        if (head == NULL) {
            head = new Node<T>(v);
        } else {
            Node<T> *NewNode = new Node<T>(v);
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = NewNode;
        }
    }
    // show() - for showing all the values in the list
    void show() {
        Node<T> *p = head;
        if (head == NULL) return;
        while (p != NULL) {
            cout << p->value << " ";
            p = p->next;
        }
    };
    // searchNode() - returns true if value exists, otherwise false
    bool searchNode(int key) {
        Node<T> *p = head;
        while (p != NULL) {
            if (p->value == key) return true;
            p = p->next;
        }
        return false;
    }
    // deleteNode() - deletes given value, shows "Key: x Not found!" if doesn't exist
    void deleteNode(T key){
        Node<T> *p = head;
        if (p->value == key) {
            head = head->next;
            delete p;
            return;
        }
        bool flag = false;
        while ((p->next)->next != NULL) {
            if ((p->next)->value == key) {
                Node<T> *temp = p->next;
                p->next = (p->next)->next;
                delete temp;
                flag = true;
                break;
            }
            p = p->next;
        }
        if (!flag) cout << "Key: " << key << " Not found!" << endl;
    }
};

int main() {
    LinkedList<int> ls; // Creating linked list

    ls.show(); // showing empty list

    ls.append(15); // appending new value
    ls.append(20);
    ls.append(30);
    ls.append(40);
    ls.append(50);

    ls.deleteNode(15); // deleting a value

    ls.show(); // showing all values after insertion and deletion

    cout << endl << (ls.searchNode(15) ? "Found!" : "Not Found!"); // Searching for a value
}