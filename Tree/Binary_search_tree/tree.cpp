#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int d){
        this -> data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};  

Node* insertIntoBst(Node* root, int d){

    if(root == nullptr){
        root = new Node(d);
        return root;
    }

    if(d < root -> data){
        insertIntoBst(root -> left, d);
    }
    else{
        insertIntoBst(root -> right, d);
    }
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        insertIntoBst(root, data);
        cin >> data;
    }
}

int main (){
    Node* root = nullptr;

    cout << "Enter the data for the root" << endl;
    takeInput(root);

    

    return 0 ;
}