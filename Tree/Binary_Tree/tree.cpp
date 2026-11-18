#include <iostream>
using namespace std;

class node {

    public:
        int data;
        node* left;
        node* right; 

    node(int d){
        this -> data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }   
};

node* buildTree(node* root){

    cout << "Enter the data: " << endl;
    int d;
    cin >> d;

    root = new node(d);

    if(d == -1){
        return nullptr;
    }

    cout << "Enter data for inserting in left of " << d << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data for inserting in right of " << d << endl;
    root -> right = buildTree(root -> right);

    return root;

};

int main () {

    node* root = NULL;

    root = buildTree(root);
    return 0;
}