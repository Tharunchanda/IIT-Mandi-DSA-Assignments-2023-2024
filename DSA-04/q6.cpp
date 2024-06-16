#include <iostream>

struct TreeNode {
    int data;
    int height; // Height of the subtree rooted at this node
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->data = value;
    newNode->height = 1;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to get the height of a node
int getHeight(TreeNode* node) {
    return (node ? node->height : 0);
}

// Function to update the height of a node
void updateHeight(TreeNode* node) {
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// Function to perform a right rotation
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to insert a value into the AVL Tree
TreeNode* insert(TreeNode* root, int value) {
    if (!root)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else // Duplicate values are not allowed
        return root;

    updateHeight(root);

    // Check balance factor and perform rotations
    int balance = getHeight(root->left) - getHeight(root->right);
    if (balance > 1) {
        if (value < root->left->data)
            return rightRotate(root);
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balance < -1) {
        if (value > root->right->data)
            return leftRotate(root);
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to search for a value in the AVL Tree
bool search(TreeNode* root, int value) {
    if (!root)
        return false;

    if (value == root->data)
        return true;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Clean up memory (not shown in this example)

int main() {
    TreeNode* root = nullptr;

    // Insert values into the AVL Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    // Search for a value
    int searchValue = 20;
    bool found = search(root, searchValue);
    std::cout << "Search for " << searchValue << ": " << (found ? "Found" : "Not found") << std::endl;

    // Clean up memory (not shown in this example)

    return 0;
}
