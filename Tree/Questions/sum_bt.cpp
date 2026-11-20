#include <iostream>
using namespace std;

class Node{
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

Node* buildTree(Node* root){

    cout << "Enter the Data" << endl;
    int d;
    cin >> d;

    if(d == -1){
        return nullptr;
    }

    root = new Node(d);

    root -> left = buildTree(root -> left);
    root -> right = buildTree(root -> right);

    return root;
};

void sum(Node* root){

    if(root == nullptr){
        return;
    }

    int s = 0;

    if(root -> left != nullptr){ // left node 
        s += root -> left -> data;
    }

    if(root -> right != nullptr){ // right node 
        s += root -> right -> data;
    }

    root -> data += s;     // current node 

    sum(root -> left);
    sum(root -> right);
}

void PostOrder(Node* root){

    if(root == nullptr){
        return;
    };

    PostOrder(root -> left);
    PostOrder(root -> right);
    cout << root -> data << " ";
};

int main (){

    Node* root = nullptr;

    root = buildTree(root);

    PostOrder(root);

    sum(root);

    cout << endl;
    cout << "After Sum of all child nodes" << endl;
    PostOrder(root);

    cout << endl;

    return 0;
}