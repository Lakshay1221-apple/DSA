#include <iostream>
using namespace std;
#include <queue>

class Node{

    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this ->data =d ;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

Node* insertIntoBst(Node* root, int d){

    if(root == nullptr){
        root = new Node(d);
        return root;
    }

    if(d > root -> data){
        insertIntoBst(root -> right, d);
    }
    if(d < root -> data){
        insertIntoBst(root -> left, d);
    }
    return root;
};

void takeInput(Node* &root){
    int d;
    cin >> d;
    while(d != -1){
        root = insertIntoBst(root, d);
        cin >> d;
    }
};

bool findX(Node* root, int x){
    
    if(root == nullptr){
        return false;
    } 

    if(root -> data == x){
        return true;
    }

    if(x > root -> data){
        return findX(root -> right, x);
    }

    else{
        return findX(root -> left, x);
    }
   
}

int main (){
    Node* root = nullptr;

    cout << "Enter the data for the root" << endl;
    takeInput(root);

    return 0 ;
}