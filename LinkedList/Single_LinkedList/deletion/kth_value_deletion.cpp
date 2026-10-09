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

int deleteKth(Node*& head, int k){

    if(head == nullptr) return -1; // list is empty

    if(k <= 0) return -2; // invalid position

    if(k ==1){
        Node* temp = head;
        head = head -> next;
        delete temp;

        cout << "Head node deleted successfully." << endl;

        temp = head;
        while (temp != nullptr){
            cout << temp -> data << " ";
            temp = temp -> next;
        }; 
        cout << endl;

        return 0;
    }

    Node* temp =head;   

    for (int i = 1 ; i < k -1; i++){
        if(temp -> next == nullptr) return -3; // k is greater than the length of the list
        temp = temp -> next;
    }
    if(temp -> next == nullptr){
        return -3 ;
    }

    Node* toDelete = temp -> next;
    temp -> next = temp -> next -> next;
    delete toDelete;

    cout << "Node at position " << k << " deleted successfully." << endl;
    temp = head;
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

    cout << "Before deletion of head node: " << endl;

    Node* temp = head;
    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

    int k;
    cout << "Enter the position of the node to delete: ";
    cin >> k;

    int result = deleteKth(head, k);
    if(result == -1){
        cout << "The list is empty." << endl;
    } else if(result == -2){
        cout << "Position must be greater than 0." << endl;
    } else if(result == -3){
        cout << "Position is greater than the length of the list." << endl;
    }

    return 0;

}