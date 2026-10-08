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

int head_deletion(Node* &head){
    if(head ==  nullptr) return -1; // list is empty

    Node* temp = head; // reference to the current head node
    head = head -> next; // update head to point to the next node
    delete temp; // free the memory of the old head node

    cout << "Head node deleted successfully." << endl;

    temp = head;
    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    };
    return 0;
}

int main() {
    
    Node* head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);

    cout << "Before deletion of head node: " << endl;

    Node* temp = head;
    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

    head_deletion(head);   

    return 0;

}