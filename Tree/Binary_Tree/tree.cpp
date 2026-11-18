
#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int d;
    cin >> d;

    if (d == -1) {
        return nullptr;
    }

    root = new node(d);

    cout << "Enter data for inserting in left of " << d << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << d << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root) {

    if (root == nullptr) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        node* temp = q.front();
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

int main() {

    node* root = nullptr;

    root = buildTree(root);

    cout << "\nLevel Order Traversal:" << endl;
    levelOrderTraversal(root);

    return 0;
}
