#include <iostream>
using namespace std;
#include <queue>

// left order transversal -> LNR (left , node, right)

class node{

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

void inOrder(node* root){

    // base case 
    if(root == nullptr){
        return;
    }

    inOrder(root -> left);
    cout << root -> data << " ";

    inOrder(root -> right);    
};

node* buildTree(node* root){

    cout << "Enter the data" << endl;
    int d;    
    cin >> d;

    if (d == -1){
        return nullptr;
    };

    root = new node(d);

    cout << "Enter data for inserting in left of " << d << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data for inserting in right of " << d << endl;
    root -> right = buildTree(root -> right);

    return root;
} 



int main(){

    node* root = nullptr;

    root = buildTree(root);

    cout << "Inorder transversal is: " << endl; 
    inOrder(root);

    return 0;   
}