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

void deleteValue(Node*& head, int X) {

    // Empty list
    if (head == nullptr) {
        return;
    }

    // If head contains X
    if (head->data == X) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    // Find the node before X
    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != X) {
        temp = temp->next;
    }

    // X was not found
    if (temp->next == nullptr) {
        return;
    }

    // Delete the node containing X
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
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

    int valueToDelete = 20;
    deleteValue(head, valueToDelete);

    cout << "After deletion of node with value " << valueToDelete << ": " << endl;

    temp = head;
    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

    return 0;

}