#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class LinkedListBinaryTree {
private:
    TreeNode* root;

public:
    LinkedListBinaryTree() : root(nullptr) {}

    void Insert(int val) {
        root = insertRecursive(root, val);
        cout << "Inserted " << val << " into the binary tree." << endl;
    }

    TreeNode* insertRecursive(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        } else {
            // Randomly choose whether to insert to the left or right child
            if (rand() % 2 == 0) {
                node->left = insertRecursive(node->left, val);
            } else {
                node->right = insertRecursive(node->right, val);
            }
            return node;
        }
    }

    void preorder(TreeNode* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void printTree() {
        cout << "Tree: ";
        preorder(root);
        cout << endl;
    }

    void Remove(int val) {
        root = removeRecursive(root, val);
    }

    TreeNode* removeRecursive(TreeNode* node, int val) {
        if (node == nullptr) {
            return node;
        }

        if (val < node->data) {
            node->left = removeRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = removeRecursive(node->right, val);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeRecursive(node->right, temp->data);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    bool Search(int val) {
        return searchRecursive(root, val);
    }

    bool searchRecursive(TreeNode* node, int val) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == val) {
            return true;
        }
        return searchRecursive(node->left, val) || searchRecursive(node->right, val);
    }
};

int main() {
    LinkedListBinaryTree linkedTree;
    linkedTree.Insert(5);
    linkedTree.Insert(3);
    linkedTree.Insert(7);
    linkedTree.Insert(2);

    linkedTree.printTree(); // Print the binary tree

    linkedTree.Remove(3);
    linkedTree.printTree(); // Print the binary tree after removing node with value 3

    cout << "Search for value 7: " << (linkedTree.Search(7) ? "Found" : "Not Found") << endl;
    cout << "Search for value 3: " << (linkedTree.Search(3) ? "Found" : "Not Found") << endl;

    return 0;
}