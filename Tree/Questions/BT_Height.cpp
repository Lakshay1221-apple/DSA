#include <iostream>
using namespace std;
#include <queue>

class Node{

    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int d){
        this ->  data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

Node* buildTree(Node* root){

    cout << "Enter the data" << endl;
    int d;
    cin >> d;

    if (d == -1){
        return nullptr;
    }

    root = new Node(d);

    cout << "Enter data for inserting in left of " << d << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data for inserting in right of " << d << endl;
    root -> right = buildTree(root -> right);

    return root;
}

class Height{

    public:
        int height(struct Node* root){

            if(root == nullptr){
                return 0;
            }

            int left = height(root -> left);
            int right = height(root -> right);

            return max(left, right) + 1;
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
        Node* temp = q.front();
        q.pop();

        if(temp == nullptr){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
            else {
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
}

int main () {

    Node* root = nullptr;

    root = buildTree(root);

    cout << "Level order transversal is: " << endl; 
    levelOrderTraversal(root);

    return 0;
}