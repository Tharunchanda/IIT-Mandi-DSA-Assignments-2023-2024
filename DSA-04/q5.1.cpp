#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function for pre-order traversal
void preOrder(TreeNode* root) {
    if (!root)
        return;
    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Function for in-order traversal
void inOrder(TreeNode* root) {
    if (!root)
        return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

// Function for post-order traversal
void postOrder(TreeNode* root) {
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode{1, new TreeNode{2, nullptr, nullptr}, new TreeNode{3, nullptr, nullptr}};

    std::cout << "Pre-order traversal: ";
    preOrder(root);
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    postOrder(root);
    std::cout << std::endl;

    // Clean up memory (not shown in this example)

    return 0;
}
