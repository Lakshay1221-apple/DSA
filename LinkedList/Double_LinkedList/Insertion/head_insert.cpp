#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

void display_forward(Node* head){

    cout << "forward display of the double linked list: \n";

    Node* temp = head;

    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
};

void display_backward(Node* head){
    cout << "backward display of the double linked list: \n";

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

int insert_head(Node* &head, int value){

    Node* newNode = new Node(value);
    
    newNode -> next = head;

    if(head != nullptr){
        head -> prev = newNode;
    }

    head = newNode;    
    return 0;
}

int main () {
    Node* head = nullptr;

    insert_head(head, 10);
    insert_head(head, 20);
    insert_head(head, 30);

    display_forward(head);
    display_backward(head);

    return 0;
}