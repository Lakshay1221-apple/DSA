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

int lenghtofll(Node* head){
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        temp = temp -> next;
        count++;
    }
    cout << "the length of linked list is: " << count << endl;  
    return count;
}

int checkexist(Node* head, int value){
    Node* temp = head;

    while(temp != nullptr){
        if(temp -> data == value)  return 1;
        temp = temp -> next;        
    }

    return 0;
}

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
    cout << endl;

    lenghtofll(first);

    cout << "1 if the value exists in linked list, 0 if not: " << checkexist(first, 20) << endl;

    return 0;
}