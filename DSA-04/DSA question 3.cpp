#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* child;
    TreeNode* sibling;

    TreeNode(int x) : val(x), child(nullptr), sibling(nullptr) {}
};

class UnboundedBranchTreeArray {
private:
    vector<TreeNode*> children;

public:
    UnboundedBranchTreeArray() {}

    void insert(int parent_val, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (parent_val == -1) {
            children.push_back(newNode);
        } else {
            for (TreeNode* node : children) {
                if (node->val == parent_val) {
                    TreeNode* childNode = node->child;
                    if (childNode == nullptr) {
                        node->child = newNode;
                    } else {
                        while (childNode->sibling != nullptr)
                            childNode = childNode->sibling;
                        childNode->sibling = newNode;
                    }
                    break;
                }
            }
        }
    }

    bool search(int val) {
        for (TreeNode* node : children) {
            if (node->val == val)
                return true;
            TreeNode* childNode = node->child;
            while (childNode != nullptr) {
                if (childNode->val == val)
                    return true;
                childNode = childNode->sibling;
            }
        }
        return false;
    }
};

class UnboundedBranchTreeLinkedList {
private:
    TreeNode* root;

    void insertHelper(TreeNode* parent, TreeNode* newNode) {
        if (parent->child == nullptr) {
            parent->child = newNode;
        } else {
            TreeNode* childNode = parent->child;
            while (childNode->sibling != nullptr)
                childNode = childNode->sibling;
            childNode->sibling = newNode;
        }
    }

public:
    UnboundedBranchTreeLinkedList() : root(nullptr) {}

    void insert(int parent_val, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (parent_val == -1) {
            if (root == nullptr)
                root = newNode;
            else
                insertHelper(root, newNode);
        } else {
            TreeNode* parentNode = searchHelper(root, parent_val);
            if (parentNode != nullptr)
                insertHelper(parentNode, newNode);
        }
    }

    TreeNode* searchHelper(TreeNode* node, int val) {
        if (node == nullptr)
            return nullptr;
        if (node->val == val)
            return node;
        TreeNode* result = searchHelper(node->child, val);
        if (result != nullptr)
            return result;
        return searchHelper(node->sibling, val);
    }

    bool search(int val) {
        TreeNode* result = searchHelper(root, val);
        return (result != nullptr);
    }
};

int main() {
    UnboundedBranchTreeArray treeArray;
    UnboundedBranchTreeLinkedList treeLinkedList;

    int choice, parent, element;
    bool found;

    do {
        cout << "1. Insert Element (Array)" << endl;
        cout << "2. Insert Element (Linked List)" << endl;
        cout << "3. Search Element (Array)" << endl;
        cout << "4. Search Element (Linked List)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter parent value (-1 for root): ";
                cin >> parent;
                cout << "Enter element to insert: ";
                cin >> element;
                treeArray.insert(parent, element);
                break;
            case 2:
                cout << "Enter parent value (-1 for root): ";
                cin >> parent;
                cout << "Enter element to insert: ";
                cin >> element;
                treeLinkedList.insert(parent, element);
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> element;
                found = treeArray.search(element);
                if (found)
                    cout << "Element found." << endl;
                else
                    cout << "Element not found." << endl;
                break;
            case 4:
                cout << "Enter element to search: ";
                cin >> element;
                found = treeLinkedList.search(element);
                if (found)
                    cout << "Element found." << endl;
                else
                    cout << "Element not found." << endl;
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
