#include <iostream>
using namespace std;
#include <queue>

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

    cout << "Enter the data" << endl;
    int d;
    cin >> d;

    if(d == -1){
        return nullptr;
    }

    root = new Node(d);

    cout << "Enter data for inserting in left of " << d << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data for inserting in right of " << d << endl;
    root -> right = buildTree(root -> right);

    return root;
}

class Identical{

    public:
        int checkIdentical(Node* root1, Node* root2){

        if(root1 == nullptr || root2 == nullptr){
            return false;
        }

        if(root1 -> data != root2 -> data){
            return false;
        }

        checkIdentical(root1 -> left, root2 -> left);
        checkIdentical(root1 -> right, root2 -> right);

    return true;

    }
};

void postOrder(Node* root){

    if(root == nullptr){
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
};

int main() {

    Node* root = nullptr;

    root = buildTree(root);

    cout << "Post order transversal: ";
    postOrder(root);

    cout << endl;
};