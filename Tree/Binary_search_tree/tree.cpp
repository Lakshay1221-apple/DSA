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
        root = new Node(d);
        return root;
    }

    if(d < root -> data){
        insertIntoBst(root -> left, d);
    }
    else{
        insertIntoBst(root -> right, d);
    }
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        insertIntoBst(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root){
    
    if (root == nullptr){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node* current = q.front();
        q.pop();

        cout << current -> data << " ";

        if (current -> left){
            q.push(current -> left);
        }

        if (current -> right){
            q.push(current -> right);
        }
    }
}

int main (){
    Node* root = nullptr;

    cout << "Enter the data for the root" << endl;
    takeInput(root);

    cout << "Level order traversal: ";
    levelOrderTraversal(root);   

    return 0 ;
}