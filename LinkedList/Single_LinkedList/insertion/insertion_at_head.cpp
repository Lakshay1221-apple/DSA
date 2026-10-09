#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

int insert_head(Node* &head , int value){

    Node* newNode = new Node(value);
    newNode -> next = head;
    head = newNode;

    cout << "Node inserted at head successfully." << endl;

    Node* temp = head;
    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }; 
    cout << endl;

    return 0; 
}

int main() {
    
    Node* head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);

    cout << "Before insertion at head: " << endl;

    Node* temp = head;
    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

    insert_head(head, 5);

    return 0;
}