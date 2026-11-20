#include <iostream>
using namespace std;
#include <stack>

class Stack {
    private:
        int top;
        int capacity;
        int* arr;

    public:
        Stack(int size) {
            capacity = size;
            arr = new int[capacity];
            top = -1;
    }

        void push(int x) {
            if (top == capacity - 1) {
                cout << "Stack overflow" << endl;
                return;
            }
            arr[++top] = x;
        }

        int pop() {
            if (top == -1) {
                cout << "Stack underflow" << endl;
                return -1;
            }
            return arr[top--];
        }

        int peek() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            }

        return arr[top];
    }

        bool empty() {
            return top == -1;
    }

        void transversal() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
            return;
        }

        cout << "Elements in stack (Top to Bottom): ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void pushAtbottom(Stack& s, int x) {

    if(s.empty()){
        s.push(x);return;
    }

    int temp = s.pop();

    pushAtbottom(s, x);

    s.push(temp);
};

int main () {

    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.transversal();

    cout << "Popped element: " << s.pop() << endl;
    cout << "Top element: " << s.peek() << endl;

    s.transversal();

    return 0;
}

