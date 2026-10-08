#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    };
};

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;

    Node* head = new Node(arr[0]);

    Node* temp = head;

    for(int i = 1; i < n ; i++){
        temp -> next = new Node(arr[i]);
        temp = temp -> next;
    }

    // printing the linked list 
    cout << "Linked List: ";
    temp = head;
    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
}

    cout << endl;

    return 0;
}