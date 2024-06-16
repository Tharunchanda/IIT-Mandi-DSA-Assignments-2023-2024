#include <iostream>
#include <algorithm>

using namespace std;

struct AVLNode {
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    AVLNode* insertHelper(AVLNode* node, int key) {
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->key)
            node->left = insertHelper(node->left, key);
        else if (key > node->key)
            node->right = insertHelper(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode* deleteNodeHelper(AVLNode* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNodeHelper(root->left, key);
        else if (key > root->key)
            root->right = deleteNodeHelper(root->right, key);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                AVLNode* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNodeHelper(root->right, temp->key);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    AVLNode* searchHelper(AVLNode* node, int key) {
        if (node == nullptr || node->key == key)
            return node;

        if (key < node->key)
            return searchHelper(node->left, key);
        else
            return searchHelper(node->right, key);
    }

    void inorderHelper(AVLNode* node) {
        if (node == nullptr)
            return;
        inorderHelper(node->left);
        cout << node->key << " ";
        inorderHelper(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insertHelper(root, key);
    }

    void remove(int key) {
        root = deleteNodeHelper(root, key);
    }

    bool search(int key) {
        AVLNode* result = searchHelper(root, key);
        return (result != nullptr);
    }

    void inorderTraversal() {
        cout << "In-order Traversal: ";
        inorderHelper(root);
        cout << endl;
    }
};

int main() {
    AVLTree avl;

    int choice, element;
    bool found;

    do {
        cout << "1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Search Element" << endl;
        cout << "4. In-order Traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                avl.insert(element);
                cout << "Element inserted." << endl;
                break;
            case 2:
                cout << "Enter element to delete: ";
                cin >> element;
                avl.remove(element);
                cout << "Element deleted." << endl;
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> element;
                found = avl.search(element);
                if (found)
                    cout << "Element found." << endl;
                else
                    cout << "Element not found." << endl;
                break;
            case 4:
                avl.inorderTraversal();
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
