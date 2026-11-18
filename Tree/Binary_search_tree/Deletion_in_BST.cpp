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

Node* insertInToBst(Node* root, int d){

    if(root == nullptr){
        root = new Node(d);
        return root;
    }

    if(d < root -> data){
        root -> left = insertInToBst(root -> left, d);
    };

    if(d > root -> data){
        root -> right = insertInToBst(root -> right ,d);
    };
    return root;
}

void takeInput(Node* &root){
    int d;
    cin >> d;

    while(d != -1){
        insertInToBst(root, d);
        cin >> d;
    }
};



void levelOrderTraversal(Node* root){

    if(root == nullptr){
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node*  temp = q.front();
        q.pop();

        if(temp == nullptr){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        if(temp != nullptr){
            cout << temp -> data << " ";

            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
} 

int main(){

    Node* root = nullptr;

    cout << "Enter data to create BST : " << endl;  
    takeInput(root);

    cout << "Level order traversal of the BST is : " << endl;
    levelOrderTraversal(root);
}