#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        prev = nullptr;
        next = nullptr;
    }    
};

void displayForward(Node* head){

    cout << "forward display f double linked list: ";

    Node* temp = head;

    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

void displayBackward(Node* head){

    cout << "backward display of double linked list: ";

    if(head == nullptr) return;

    Node* temp = head;

    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    cout << endl;

    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> prev;
    }

    cout << endl;
}

int main() {
    
    Node* head = new Node(10);

    head -> next = new Node(20);
    head -> next -> prev = head;

    head -> next  -> next = new Node(30);
    head -> next -> next -> prev = head -> next;

    displayForward(head);
    displayBackward(head);
}