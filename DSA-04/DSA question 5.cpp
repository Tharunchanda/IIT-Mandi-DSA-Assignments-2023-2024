#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    void preorderHelper(TreeNode* node) {
        if (node == nullptr)
            return;

        cout << node->val << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void inorderHelper(TreeNode* node) {
        if (node == nullptr)
            return;

        inorderHelper(node->left);
        cout << node->val << " ";
        inorderHelper(node->right);
    }

    void postorderHelper(TreeNode* node) {
        if (node == nullptr)
            return;

        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->val << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    void preorderTraversal() {
        cout << "Pre-order Traversal: ";
        preorderHelper(root);
        cout << endl;
    }

    void inorderTraversal() {
        cout << "In-order Traversal: ";
        inorderHelper(root);
        cout << endl;
    }

    void postorderTraversal() {
        cout << "Post-order Traversal: ";
        postorderHelper(root);
        cout << endl;
    }

    void insert(int val) {
        root = insertHelper(root, val);
    }

    bool search(int val) {
        TreeNode* result = searchHelper(root, val);
        return (result != nullptr);
    }

private:
    TreeNode* insertHelper(TreeNode* node, int val) {
        if (node == nullptr)
            return new TreeNode(val);

        if (val < node->val)
            node->left = insertHelper(node->left, val);
        else if (val > node->val)
            node->right = insertHelper(node->right, val);

        return node;
    }

    TreeNode* searchHelper(TreeNode* node, int val) {
        if (node == nullptr || node->val == val)
            return node;

        if (val < node->val)
            return searchHelper(node->left, val);
        else
            return searchHelper(node->right, val);
    }
};

int main() {
    BinaryTree binaryTree;
    int choice, element;
    bool found;

    do {
        cout << "1. Insert Element" << endl;
        cout << "2. Search Element" << endl;
        cout << "3. Pre-order Traversal" << endl;
        cout << "4. In-order Traversal" << endl;
        cout << "5. Post-order Traversal" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                binaryTree.insert(element);
                cout << "Element inserted." << endl;
                break;
            case 2:
                cout << "Enter element to search: ";
                cin >> element;
                found = binaryTree.search(element);
                if (found)
                    cout << "Element found." << endl;
                else
                    cout << "Element not found." << endl;
                break;
            case 3:
                binaryTree.preorderTraversal();
                break;
            case 4:
                binaryTree.inorderTraversal();
                break;
            case 5:
                binaryTree.postorderTraversal();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
