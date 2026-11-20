#include <iostream>
using namespace std;
#include <vector>

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

    cout << "Enter the Data" << endl;
    int d;
    cin >> d;

    if(d == -1){
        return nullptr;
    }

    root = new Node(d);

    root -> left = buildTree(root -> left);
    root -> right = buildTree(root -> right);

    return root;
};

class boundary {

    public:
        void leftBoundary(Node* root, vector<int>& ans){

            if((root == nullptr) || (root -> left == NULL && root -> right == NULL)){
                return;
            }

            ans.push_back(root -> data);

            if(root -> left != NULL){
                leftBoundary(root -> left, ans);
            }
            else{
                leftBoundary(root -> right, ans);
            }

        };

        void traversalLeaf(Node* root, vector<int>& ans){

            if(root == nullptr){
                return;
            }

            if(root -> left == NULL && root -> right == NULL){
                ans.push_back(root -> data);
                return;
            }
            traversalLeaf(root -> left, ans);
            traversalLeaf(root -> right, ans);
        };

        void traversalRight(Node* root, vector<int>& ans){

            if((root == nullptr) || (root -> left == NULL && root -> right == NULL)){
                return;
            }

            if(root -> right != NULL){
                traversalRight(root -> right, ans);
            }
            else{
                traversalRight(root -> left, ans);
            }

            ans.push_back(root -> data);
        };

        vector<int> boundaryTraversal(Node* root){

            vector<int> ans;
            if(root == nullptr){
                return ans;
            }

            ans.push_back(root -> data);

            leftBoundary(root -> left, ans);
            traversalRight(root -> right, ans);
            traversalLeaf(root -> left, ans);
            traversalLeaf(root -> right, ans);
            return ans;
        }
};

int main(){

    Node* root = nullptr;

    root = buildTree(root);
    cout << endl;

    boundary b;
    vector<int> ans = b.boundaryTraversal(root);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
};