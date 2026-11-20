
#include <iostream>
using namespace std;

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

    ~Stack() {
        delete[] arr;
    }
};

void deleteMiddleElement(Stack& s, int size, int count = 0) {

    if (count == size / 2) {
        cout << "Deleted middle element: " << s.pop() << endl;
        return;
    }
   
    int x = s.pop();

    deleteMiddleElement(s, size, count + 1);

    s.push(x);
}

int main() {

    cout << "Enter the size of stack: ";
    int size;
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size" << endl;
        return 0;
    }

    Stack s(size);

    cout << "Enter the elements to push into stack: ";

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    cout << "\nOriginal stack:" << endl;
    s.transversal();

    deleteMiddleElement(s, size);

    cout << "\nStack after deleting middle element:" << endl;
    s.transversal();

    return 0;
}
