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

Node* insert(Node* root , int d){

    if(root == nullptr){
        root = new Node(d);
        return root;
    }

    if(d < root -> data){
        root -> left = insert(root -> left, d);
    }

    if(d > root -> data){
        root -> right = insert(root -> right ,d);
    }

    return root;
};

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        insert(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root){

    if(root == nullptr){
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == nullptr){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            if(temp->left)  {
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
};

int main (){
    Node* root = nullptr;

    cout << "Enter the data for the root" << endl;
    takeInput(root);

    return 0 ;
}