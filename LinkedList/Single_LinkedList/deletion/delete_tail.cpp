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

int taildeletion(Node* &head){

    if(head == nullptr) return -1;

    if(head -> next == nullptr){
        delete head;
        head = nullptr;
        return 0;
    }

    Node* temp = head;

    while (temp -> next -> next != nullptr){
        temp = temp -> next;
    }

    Node* toDelete = temp -> next;
    temp -> next = nullptr;
    delete toDelete;

    cout << "Tail node deleted successfully." << endl;
    
    temp = head;
    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    };
    return 0;

    return 0;
}


int main() {
    
    Node* head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);

    cout << "Before deletion of tail node: " << endl;

    Node* temp = head;
    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

    taildeletion(head);


    return 0;

}