#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack {
    private:
    Node* top;

    public:

    Stack() {
        top = nullptr;
    }

    void push(int value){
        Node* newNode = new Node();

        newNode -> data = value;
        newNode -> next = top;
        top = newNode;
        cout << value << " pushed\n";            
    };

    void pop(){
        if(top == nullptr){
            cout << "Stack Underflow\n";
            return;
        } else {
            Node* temp = top;
            cout << temp->data << " popped\n";

            top = top->next;
            delete temp;
        }
    };

    void peek(){
        if(top == nullptr){
            cout<< "Stack is empty\n";
        } else {
            cout << "Top:" << top->data << '\n';
        }
    }

    void traverse(){

        if(top == nullptr){
            cout << "Stack is empty\n" << endl;

        } else {
            Node* temp = top;
            while(temp != nullptr){
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << '\n';
        }
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.traverse();  // 30 20 10
    s.pop();       // 30 popped
    s.peek();      // Top: 20
    s.traverse();  // 20 10

    return 0;
}