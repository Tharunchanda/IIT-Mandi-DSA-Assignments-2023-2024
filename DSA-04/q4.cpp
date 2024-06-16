#include <iostream>
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
TreeNode* insert(TreeNode* root, int value, int& comparisons) {
    if (!root) {
        comparisons++;
        return createNode(value);
    }
    if (value < root->data) {
        comparisons++;
        root->left = insert(root->left, value, comparisons);
    } else if (value > root->data) {
        comparisons++;
        root->right = insert(root->right, value, comparisons);
    }
    return root;
}
bool search(TreeNode* root, int value, int& comparisons) {
    if (!root) {
        comparisons++; // Count the comparison made during search
        return false;
    }
    if (value == root->data) {
        comparisons++; // Count the comparison made during search
        return true;
    } else if (value < root->data) {
        comparisons++; // Count the comparison made during search
        return search(root->left, value, comparisons);
    } else {
        comparisons++; // Count the comparison made during search
        return search(root->right, value, comparisons);
    }
}
TreeNode* remove(TreeNode* root, int value, int& comparisons) {
    if (!root) {
        comparisons++; // Count the comparison made during deletion
        return nullptr;
    }   
    if (value < root->data) {
        comparisons++; // Count the comparison made during deletion
        root->left = remove(root->left, value, comparisons);
    } else if (value > root->data) {
        comparisons++; // Count the comparison made during deletion
        root->right = remove(root->right, value, comparisons);
    } else {
        comparisons++; // Count the comparison made during deletion
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* minRightSubtree = root->right;
        while (minRightSubtree->left) {
            minRightSubtree = minRightSubtree->left;
            comparisons++; // Count the comparison made during deletion
        }
        root->data = minRightSubtree->data;
        root->right = remove(root->right, minRightSubtree->data, comparisons);
    }
    return root;
}
void deleteBST(TreeNode* root) {
    if (!root)
        return;
    deleteBST(root->left);
    deleteBST(root->right);
    delete root;
    
}
void inOrder(TreeNode* root) {
    if (!root)
        return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);

}
int main() {
    TreeNode* root = nullptr;
    int comparisons = 0;
    root = insert(root, 50, comparisons);
    root = insert(root, 30, comparisons);
    root = insert(root, 70, comparisons);
    root = insert(root, 20, comparisons);
    root = insert(root, 40, comparisons);
    inOrder(root);
    int searchValue = 40;
    bool found = search(root, searchValue, comparisons);
    std::cout<<std::endl;
    std::cout << "Search for " << searchValue << ": " << (found ? "Found" : "Not found") << std::endl;
    int deleteValue = 30;
    root = remove(root, deleteValue, comparisons);
    std::cout << "Deleted " << deleteValue << std::endl;
    deleteBST(root);
    std::cout << "Total comparisons made: " << comparisons << std::endl;
    return 0;
}
