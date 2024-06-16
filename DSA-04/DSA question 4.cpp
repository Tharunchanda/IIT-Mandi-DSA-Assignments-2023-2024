#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    int comparisons;

    TreeNode* insertHelper(TreeNode* node, int val) {
        if (node == nullptr)
            return new TreeNode(val);

        comparisons++;
        if (val < node->val)
            node->left = insertHelper(node->left, val);
        else if (val > node->val)
            node->right = insertHelper(node->right, val);

        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    TreeNode* removeHelper(TreeNode* node, int val) {
        if (node == nullptr)
            return nullptr;

        comparisons++;
        if (val < node->val)
            node->left = removeHelper(node->left, val);
        else if (val > node->val)
            node->right = removeHelper(node->right, val);
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
            node->right = removeHelper(node->right, temp->val);
        }
        return node;
    }

    TreeNode* searchHelper(TreeNode* node, int val) {
        if (node == nullptr || node->val == val)
            return node;

        comparisons++;
        if (val < node->val)
            return searchHelper(node->left, val);
        else
            return searchHelper(node->right, val);
    }

public:
    BinarySearchTree() : root(nullptr), comparisons(0) {}

    void insert(int val) {
        root = insertHelper(root, val);
    }

    void remove(int val) {
        root = removeHelper(root, val);
    }

    bool search(int val) {
        TreeNode* result = searchHelper(root, val);
        return (result != nullptr);
    }

    int getComparisons() {
        return comparisons;
    }

    void resetComparisons() {
        comparisons = 0;
    }
};

int main() {
    BinarySearchTree bst;

    int choice, element;
    bool found;

    do {
        cout << "1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Search Element" << endl;
        cout << "4. Report Comparisons" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                bst.insert(element);
                cout << "Element inserted." << endl;
                break;
            case 2:
                cout << "Enter element to delete: ";
                cin >> element;
                bst.remove(element);
                cout << "Element deleted." << endl;
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> element;
                found = bst.search(element);
                if (found)
                    cout << "Element found." << endl;
                else
                    cout << "Element not found." << endl;
                break;
            case 4:
                cout << "Total comparisons made: " << bst.getComparisons() << endl;
                bst.resetComparisons();
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
