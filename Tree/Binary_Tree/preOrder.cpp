#include <iostream>
using namespace std;

// pre order transversal -> NLR (node, left, right)
class node{
    
    public:
        int data;
        node* left;
        node* right;

    node (int d){
        this -> data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

node* buildTree(node* root){

    cout << "Enter the data" << endl;
    int d;
    cin >> d;

    if (d == -1){
        return  nullptr;
    };

    root = new node(d);

    cout << "Enter data for inserting in left of " << d << endl;
    root -> left = buildTree(root -> left); 

    cout << "Enter data for inserting in right of " << d << endl;
    root -> right = buildTree(root -> right);   
};

void preOrder(node* root){

    // base case 
    if(root == nullptr){
        return;
    }

    cout << root -> data << " ";

    preOrder(root -> left);
    preOrder(root -> right);    
};


int main() {
    
    node* root = nullptr;

    // creating a tree
    root = buildTree(root);

    cout << "Printing the tree in pre order transversal" << endl;
    preOrder(root);

    return 0;
}