
#include <iostream>
using namespace std;

class Node {
    
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Build Binary Tree
Node* buildTree(Node* root) {

    cout << "Enter the data (-1 for NULL): ";
    int d;
    cin >> d;

    if (d == -1) {
        return nullptr;
    }

    root = new Node(d);

    cout << "Enter data for inserting in left of " << d << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << d << endl;
    root->right = buildTree(root->right);

    return root;
}

// Check whether two trees are identical
class Identical {
public:

    bool checkIdentical(Node* root1, Node* root2) {

        // Both nodes are NULL
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }

        // Only one node is NULL
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }

        // Compare current node values
        if (root1->data != root2->data) {
            return false;
        }

        // Compare left and right subtrees
        bool left = checkIdentical(root1->left, root2->left);
        bool right = checkIdentical(root1->right, root2->right);

        return left && right;
    }
};

// Postorder traversal
void postOrder(Node* root) {

    if (root == nullptr) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);

    cout << root->data << " ";
}

int main() {

    Node* root1 = nullptr;
    Node* root2 = nullptr;

    cout << "\nBUILD FIRST TREE\n";
    root1 = buildTree(root1);

    cout << "\nBUILD SECOND TREE\n";
    root2 = buildTree(root2);

    cout << "\nPostorder traversal of first tree: ";
    postOrder(root1);

    cout << "\nPostorder traversal of second tree: ";
    postOrder(root2);

    Identical obj;

    if (obj.checkIdentical(root1, root2)) {
        cout << "\n\nBoth trees are identical." << endl;
    }
    else {
        cout << "\n\nTrees are not identical." << endl;
    }

    return 0;
}
