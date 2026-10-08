#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Node(int value){
    //     data = value;
    //     next = nullptr;
    // }
};

int main () {

    // Node* head = new Node(10);
    // head -> next = new Node(20);
    // head -> next -> next = new Node(30);

    Node* first = new Node;
    Node* second = new Node;
    Node* third = new Node;

    first -> data = 10;
    first -> next = second;

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = nullptr;

    Node* temp = first;

    while (temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    return 0;
}