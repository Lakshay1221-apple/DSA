#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
    private:
    Node* front;
    Node* rear;

    public:
    
    Queue(){
        front = rear = nullptr;
    }

     bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value){

        Node* newNode = new Node{value , nullptr};

        if(rear == nullptr){
            front = rear = newNode;
        } else {
            rear -> next = newNode;
            rear = newNode;
        }
    }

    void dequeue(){
        
        if(isEmpty()){
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << temp->data << endl;
        front = front -> next;
        delete temp;

        if(front == nullptr){
            rear = nullptr;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front: " << front->data << '\n';
        }
    }

    void traverse() {
        Node* current = front;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << '\n';
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.traverse();  // 10 20 30
    q.peek();      // Front: 10
    q.dequeue();   // 20 removed
    q.traverse();  // 30
    q.dequeue();   // 30 removed
    q.traverse();  // (empty)
    return 0;
}