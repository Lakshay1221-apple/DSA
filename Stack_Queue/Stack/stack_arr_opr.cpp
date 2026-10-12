#include <iostream>
using namespace std;

const int MAX = 5;

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;
        cout << value << " pushed\n";
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << arr[top] << " popped\n";
        top--;
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top: " << arr[top] << '\n';
    }

    void traverse() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.traverse();  // 30 20 10
    s.peek();      // Top: 30
    s.pop();       // 30 popped
    s.traverse();  // 10
    s.peek();      // Top: 10
    return 0;
}