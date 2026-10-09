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

int insert_before_value(Node*  &head , int value, int x){
    
    if(head == nullptr) return -1; // list is empty

    if(head -> data == x){
        Node* newNode = new Node(value);
        newNode -> next = head;
        head = newNode;

        cout << "Node inserted before value " << x << " successfully." << endl;

        return transversal(head);
    }
    
    Node* temp = head;

    while(temp -> next != nullptr && temp -> next -> data != x){
        temp = temp -> next;
    }

    if(temp -> next == nullptr)  return -1;

    Node* newNode = new Node(value);
    newNode -> next = temp -> next;
    temp -> next = newNode;

    cout << "Node inserted before value " << x << " successfully." << endl;

    return transversal(head);
};

int main() {
    
    Node* head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);

    cout << "Initial linked list: ";
    transversal(head);

    int value, x;
    cout << "Enter the value to insert: ";
    cin >> value;
    cout << "Enter the value before which to insert: ";
    cin >> x;

    int result = insert_before_value(head, value, x);
    if(result == -1){
        cout << "Value " << x << " not found in the list." << endl;
    }

    return 0;
}