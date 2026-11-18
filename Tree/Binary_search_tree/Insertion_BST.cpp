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
        root -> left = insert(root -> left,  d);
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

Node* findMin(Node* root){ // finding min value 

    while(root -> left != nullptr){
        root = root -> left;
    }

    return root;
}

Node* deleteNode(Node* root, int val){

    if(root == nullptr){
        return root;
    };

    if(val < root -> data){
        root -> left = deleteNode(root -> left,val);
    }

    else if(val > root -> data){ 
        root -> right = deleteNode(root -> right ,val);
    }

    else {
        // no child 
        if(root -> left == nullptr && root -> right == nullptr){
            delete root;
            return nullptr;
        }

        // only right child 

        else if(root ->left == nullptr){
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // only left child 

        else if (root -> right == nullptr){
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        // two children 

        else {
            Node* temp = findMin(root -> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right, temp -> data);
        }
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