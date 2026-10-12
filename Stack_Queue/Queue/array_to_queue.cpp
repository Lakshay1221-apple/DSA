#include <iostream>
using namespace std;

const int MAX = 5;

class Queue {
    private:
    int arr[MAX];
    int front , rear;

    public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int value){
        if(isFull()){
            cout << "Queue Overflow\n";
            return;
        }

        if(isEmpty()){
            front = 0;
        }

        arr[++rear] = value;
        cout << value << " enqueued\n";
    };

    void dequeue(){

        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " removed\n";

        if(front == rear){
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek(){
        if(isEmpty()){
            cout << "Queue is empty\n";
        } else {
            cout << "Front: " << arr[front] << '\n';
        }
    }

    void traverse(){ {
        if(isEmpty()){
            cout << "Queue is empty\n";
        } else {
            for(int i = front; i <= rear ; i++){
                cout << arr[i] << " ";
            }   
        }
        cout << '\n';
    }};
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.traverse();  // 10 20 30
    q.peek();      // Front: 10
    q.dequeue();   // 10 removed
    q.traverse();  // 20 30

    return 0;
}