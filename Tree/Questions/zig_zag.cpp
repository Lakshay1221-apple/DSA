
#include <iostream>
#include <queue>
#include <vector>
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

// Build a binary tree (-1 means NULL)
Node* buildTree(Node* root) {
    cout << "Enter the data (-1 for NULL): ";

    int d;
    cin >> d;

    if (d == -1) {
        return nullptr;
    }

    root = new Node(d);

    cout << "Enter left child of " << d << endl;
    root->left = buildTree(root->left);

    cout << "Enter right child of " << d << endl;
    root->right = buildTree(root->right);

    return root;
}

class zigZag {
public:
    vector<int> ZigZag(Node* root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();

            // Create a vector for the current level
            vector<int> ans(size);

            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                // Decide where to store the current value
                int index = leftToRight ? i : size - i - 1;

                ans[index] = frontNode->data;

                // Insert children into the queue
                if (frontNode->left) {
                    q.push(frontNode->left);
                }

                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            // Add the current level to the final result
            for (int value : ans) {
                result.push_back(value);
            }

            // Change direction for the next level
            leftToRight = !leftToRight;
        }

        return result;
    }
};

int main() {
    Node* root = nullptr;
    root = buildTree(root);

    zigZag obj;

    vector<int> result = obj.ZigZag(root);

    cout << "\nZigzag Traversal: ";

    for (int value : result) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}
