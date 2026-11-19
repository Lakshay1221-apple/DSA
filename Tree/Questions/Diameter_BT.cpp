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

Node* BuildTree(Node* root){

    cout << "Enter the data" << endl;
    int d;
    cin >> d;

    if(d == -1){
        return nullptr;
    }

    root = new Node(d);

    cout << "Enter data for inserting in left of " << d << endl;
    root -> left = BuildTree(root -> left);

    cout << "Enter data for inserting in right of " << d << endl;
    root -> right = BuildTree(root -> right);

    return root;
};

class Diameter{

    public:

        int height(Node* root){
            if(root == nullptr){
                return 0;
            }

            int left = height(root -> left);
            int right = height(root -> right);

            return max(left, right) + 1;
        }


        int diameter(Node* root){

            if(root == nullptr){
                return 0;
            }

            int left = diameter(root -> left);
            int right = diameter(root -> right);

            int op1 = left;
            int op2 = right;
            int op3 =  height(root -> left) + height(root -> right) + 1;

            return max(op1, max(op2, op3));
        }
};

class oNDiameter{

    public:

    int solve(Node* root, int& height){

        if(root == nullptr){
            height = 0;
            return 0;
        };

    int lh = 0, rh = 0;

    int left = solve(root -> left, lh);
    int right = solve(root -> right, rh);

    int op1 = left;
    int op2 = right;
    int op3 = lh + rh + 1;

    return max(op1, max(op2, op3));    
    }

    int diameter(Node* root){
        
        int height = 0;
        return solve(root, height);
    }
};


void inOrder(Node* root){

    if(root == nullptr){
        return;
    }

    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
};

int main(){

    Node* root = nullptr;

    root = BuildTree(root);

    cout << "In order transversal: ";
    inOrder(root);

    cout << endl;

    return 0;
};

