#include <iostream>
using namespace std;
#include <stack>

class Stack{
    
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

void sortStack(Stack& s, int x){
    if(s.empty() || s.peek() <= x){
        s.push(x);
        return;
    }

    int temp = s.pop();
    sortStack(s, x);
    s.push(temp);
}

int main(){
        cout << "Enter the size of stack: ";
        int size;
        cin >> size;

        if(size <= 0) {
            cout << "Invalid size. Please enter a positive integer." << endl;
            return 1; // Exit the program with an error code
        }
        Stack s(size);

        cout << "Enter elements in stack: ";
        for(int i = 0; i < size; i++){
            int element;
            cin >> element;
            s.push(element);
        }
        s.transversal();
        return 0;
}