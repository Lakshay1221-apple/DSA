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

int transversal(Node* head){
    Node* temp = head;
    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    };
    cout << endl;
    return 0;
}

int insert_tail(Node* &head, int value){

    Node *newNode = new Node(value);

    if(head == nullptr){
        head = newNode;
        
        cout << "Node inserted at tail successfully." << endl;
        return transversal(head);
    }

    Node* temp = head;

    while(temp -> next != nullptr){
        temp = temp -> next;
    }

    temp -> next = newNode;

    cout << "Node inserted at tail successfully." << endl;
    return transversal(head);
}

int main () {
    
    Node* head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);

    cout << "Before the insertion at the taul: " << endl;

    transversal(head);

    insert_tail(head, 40);

    return 0;    
}