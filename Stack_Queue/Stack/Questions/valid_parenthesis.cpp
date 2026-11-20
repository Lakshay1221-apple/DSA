
#include <iostream>
#include <stack>
#include <string>
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


class ValidParenthesis {
public:
    bool isValid(string expression) {
        stack<char> s;

        for (int i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            // Opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                s.push(ch);
            }

            // Closing brackets
            else if (ch == ')' || ch == '}' || ch == ']') {

                // No opening bracket available
                if (s.empty()) {
                    return false;
                }

                char topChar = s.top();

                // Check matching brackets
                if ((ch == ')' && topChar == '(') ||
                    (ch == '}' && topChar == '{') ||
                    (ch == ']' && topChar == '[') {

                    s.pop();
                }
                else {
                    return false;
                }
            }
        }

        // All opening brackets must be matched
        return s.empty();
    }
};

int main() {
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    ValidParenthesis vp;

    if (vp.isValid(expression)) {
        cout << "Valid Parentheses" << endl;
    }
    else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}
