#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTreeLinked {
private:
    TreeNode* root;

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    void inorder(TreeNode* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

public:
    BinaryTreeLinked() : root(nullptr) {}

    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr)
            return new TreeNode(val);

        if (val < node->val)
            node->left = insert(node->left, val);
        else if (val > node->val)
            node->right = insert(node->right, val);

        return node;
    }

    bool search(TreeNode* node, int val) {
        if (node == nullptr)
            return false;
        if (node->val == val)
            return true;
        if (val < node->val)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    TreeNode* remove(TreeNode* node, int val) {
        if (node == nullptr)
            return nullptr;

        if (val < node->val)
            node->left = remove(node->left, val);
        else if (val > node->val)
            node->right = remove(node->right, val);
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = findMin(node->right);
            node->val = temp->val;
            node->right = remove(node->right, temp->val);
        }
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    void remove(int val) {
        root = remove(root, val);
    }

    void display() {
        cout << "Binary Tree: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTreeLinked tree;

    int choice, element;
    bool found;

    do {
        cout << "1. Insert Element" << endl;
        cout << "2. Search Element" << endl;
        cout << "3. Delete Element" << endl;
        cout << "4. Display Tree" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                tree.insert(element);
                break;
            case 2:
                cout << "Enter element to search: ";
                cin >> element;
                found = tree.search(element);
                if (found)
                    cout << "Element found." << endl;
                else
                    cout << "Element not found." << endl;
                break;
            case 3:
                cout << "Enter element to delete: ";
                cin >> element;
                tree.remove(element);
                break;
            case 4:
                tree.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
