#include <iostream>
using namespace std;
#include <queue>

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

void builFromLevelOrder(node* &root){

    queue<node*>q;
    cout << "Enter the data for the root"<< endl;
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter the left node for: " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter the right node for: " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }            
    }
};

void inorder(node* root){
    
    if(root == nullptr){
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int noLeafNode(node* root, int &count){


    if (root == nullptr){
        return 0;
    }
    inorder(root -> left);
    inorder(root -> right);

    if(root -> left == nullptr && root -> right == nullptr){
        count++;        
    }
};

int main () {
    node* root = nullptr;

    int count = 0;

    inorder(root);

    builFromLevelOrder(root);
    noLeafNode(root, count);
    cout << "Number of leaf nodes: " << count << endl;

    return 0;
}