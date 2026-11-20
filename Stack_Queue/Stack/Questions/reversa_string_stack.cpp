#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int topIndex;
    char* arr;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        topIndex = -1;
        arr = new char[capacity];
    }

    void push(char x) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }

        arr[++topIndex] = x;
    }

    char pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }

        return arr[topIndex--];
    }

    bool empty() {
        return topIndex == -1;
    }

    ~Stack() {
        delete[] arr; 
    }
};

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    Stack s(str.length());

    // Step 1: Push every character into the stack
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    // Step 2: Pop characters and create reversed string
    string ans = "";

    while (!s.empty()) {
        ans.push_back(s.pop());
    }

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << ans << endl;

    return 0;
}