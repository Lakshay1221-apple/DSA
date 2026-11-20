#include <iostream>
using namespace std;

class TwoStack{

    private:
        int top1, top2;
        int* arr;
        int capacity;
    
    public:

    TwoStack(int size){
        capacity = size;
        top1 = -1;
        top2 = capacity;
        arr = new int[capacity];
    }

    void push1(int x){
        if(top1 + 1 == top2){
            cout << "stack overflow" << endl;
            return;
        };

        arr[++top1] = x;
        cout << "pushed element in stack 1: " << x << endl;
    }

    void push2(int x){
        if(top2 - 1 == top1){
            cout << "stack overflow" << endl;
            return;
        };

        arr[--top2] = x;
        cout << "pushed element in stack 2: " << x << endl;
    }


    void transversal1(){
        cout << "Elements in stack 1 are: ";

        if(top1 == -1){
            cout << "stack 1 is empty" << endl;
            return;
        };

        for(int i = top1; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void transversal2(){
        cout << "Elements in stack 2 are: ";

        if(top2 == -1){
            cout << "stack 2 is empty" << endl;
            return ;
        };

        for(int i = top2; i < capacity; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void pop(){
        if(top1 != -1){
            cout << "popped element from stack 1: " << arr[top1--] << endl;
        }
        else if(top2 != -1){
            cout << "popped element from stack 2: " << arr[top2++] << endl;
        }
        else{
            cout << "both stacks are empty" << endl;
        }
    }
};

int main(){

    int size1;
    int size2;

    cout << "Enter the size of stack 1: ";
    cin >> size1;

    cout << "Enter the size of stack 2: ";
    cin >> size2;

    TwoStack ts(size1 + size2);

    cout << "Pushing elements into stack 1..." << endl;
    for(int i = 0; i < size1; i++){
        int element;
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        ts.push1(element);
    }

    cout << "Pushing elements into stack 2..." << endl;
    for(int i = 0; i < size2; i++){
        int element;        
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        ts.push2(element);
    }

    cout << "Traversing stack 1..." << endl;
    ts.transversal1(); 

    cout << "Traversing stack 2..." << endl;
    ts.transversal2();

    return 0;
}