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

int insert_kth(Node* &head , int value , int k){

    if(k <= 0) return -1;

    if(k == 1){
        Node* newNode = new Node(value);
        newNode -> next = head;
        head = newNode;

        cout << "Node inserted at position " << k << " successfully." << endl;

        return transversal(head);
    }

    Node* temp = head;

    for(int i = 1; i < k - 1; i++){
        if(temp == nullptr) return -1;
        temp = temp -> next;
    }

    if(temp == nullptr) return -1;
 

    Node* newNode = new Node(value);
    newNode -> next = temp -> next;
    temp -> next = newNode;

    cout << "Node inserted at position " << k << " successfully." << endl;

    return transversal(head);
};

int main () {
    
    Node* head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);

    cout << "Before insertion at position k: " << endl;

    transversal(head);

    insert_kth(head, 15, 2);

    return 0;
}

