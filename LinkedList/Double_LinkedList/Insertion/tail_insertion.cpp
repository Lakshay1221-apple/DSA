#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
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

void backward_display(Node* head){
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
};

int insert_tail(Node* &head, int value){
    Node* newNode = new Node(value);

    if(head == nullptr){
        head = newNode;
        return 0;
    }

    Node* temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }

    temp -> next = newNode;
    newNode -> prev = temp;

    head = head; // head remains unchanged, but this line is redundant and can be omitted

    return 0;
}

int main() {
    Node* head = new Node(10);
    head -> next = new Node(20);
    head -> next -> prev = head;
    head -> next -> next = new Node(30);
    head -> next -> next -> prev = head -> next;

    cout << "Before insertion at tail: " << endl;
    display_forward(head);
    backward_display(head);

    insert_tail(head, 40);

    cout << "After insertion at tail: " << endl;
    display_forward(head);
    backward_display(head);

    return 0;
}

