#include <iostream>
using namespace std;
#include <queue>

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
        root =  new Node(d);
        return root;
    }       

    if(d > root -> data){
        insertIntoBst(root -> right, d);
    };

    if(d < root -> data){
        insertIntoBst(root -> left, d);
    };
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        insertIntoBst(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {

    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            cout << endl;
            if (!q.empty()) {
                q.push(nullptr);
            }
        }

        else {
            cout << temp->data << " ";

            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(Node* root){
    if(root == nullptr){
        return;
    }

    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void preOrder(Node* root){

    if(root == nullptr){
        return;
    }

    cout << root -> data << " ";

    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(Node* root){

    if(root == nullptr){
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";    
}

int main (){
    Node* root = nullptr;

    cout << "Enter the data for the root" << endl;
    takeInput(root);

    cout << "Level order traversal: ";
    levelOrderTraversal(root);   

    return 0 ;
}