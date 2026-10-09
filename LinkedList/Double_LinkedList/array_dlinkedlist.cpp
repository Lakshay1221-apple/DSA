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

void displayForward(Node* head){
    
    cout << "forward display of double linked list: ";

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

int array_to_dl(Node*& head , int arr[], int n){

    if (n == 0) return 0;

    head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1 ; i < n ; i++){

        Node* newNode = new Node(arr[i]);
        temp -> next = newNode;
        newNode -> prev = temp;

        temp = newNode;        
    }

    cout << "double linked list created from array: " << endl;

    cout << "forward display of double linked list: ";
    displayForward(head);

    cout << "backward display of double linked list: ";
    displayBackward(head);

    return 1;
} 

int main () {
    
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = nullptr;

    array_to_dl(head , arr , n);

    return 0;
}