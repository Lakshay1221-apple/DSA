#include <iostream>
using namespace std;

class Stack{

    private:
        int top;
        int* arr;
        int capacity;

    public:

    Stack(int size ){
        capacity = size;
        top = -1;
        arr = new int [capacity];
    }

    void push(int x){

        if(arr[top] == capacity - 1){
            cout << "stack overflow" << endl;
        };

        arr[++top] = x; 
        cout << "pushed element: " << x << endl;
        }
    
    void pop(){

        if(top == -1){
            cout << "stack underflow" << endl;
        };

        cout << "popped element: " << arr[top--] << endl;
    }

    void traversal(){
        cout << "Elements in the stack are: ";

        if(top == -1){
            cout << "stack is empty"  << endl;
        };

        for(int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void peek(){
        if(top == -1){
            cout << "stack is empty" << endl;
        };

        cout << "top element is: " << arr[top] << endl;
    }

    ~Stack() {
        delete[] arr;
    }


};

int main() {

    int size;

    cout << "Enter the size of the stack: ";
    cin >> size;

    if(size <= 0) {
        cout << "Invalid stack size. Please enter a positive integer." << endl;
        return 1; // Exit the program with an error code
    }

    Stack s(size);

    cout << "Enter the elements to push into the stack: ";
    for(int i = 0; i < size; i++){
        int element;
        cin >> element;
        s.push(element);
    }


    s.traversal();
    s.pop();
    s.traversal();
}
    


