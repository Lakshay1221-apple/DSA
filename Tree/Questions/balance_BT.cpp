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


Node* BuildTree(Node* root){

    cout << "Enter the data" << endl;
    int d;
    cin >> d;

    if(d == -1){
        return nullptr;
    }

    root = new Node(d);

    cout << "Enter the data for the tree" << endl;
    root -> left = BuildTree(root -> left);
    root -> right = BuildTree(root -> right);

    return root;
}

class checkBalance{

    public:

    int checkBalanceTree(Node* root, bool &ans){

        if(root == nullptr){
            return 0;
        };

        int left = checkBalanceTree(root -> left , ans);
        int right = checkBalanceTree(root -> right, ans);

        if(abs(left - right) > 1){
            ans = false;
        }
        
        return max(left , right) + 1;
        }

    bool isBalanced(Node* root){

        bool ans = true;    
        
        checkBalanceTree(root, ans);
        return ans;
    };
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
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
};

int main(){

    Node* root = nullptr;

    root = BuildTree(root);

    cout << "Level order transversal: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    checkBalance cb;
    if(cb.isBalanced(root)){
        cout << "The tree is balanced." << endl;
    }
    else{
        cout << "The tree is not balanced." << endl;
    }
};