#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* nextSibling;
    TreeNode* firstChild;

    TreeNode(int value) : data(value), nextSibling(nullptr), firstChild(nullptr) {}
};

void addChild(TreeNode* parent, TreeNode* child) {
    if (!parent || !child)
        return;

    if (!parent->firstChild) {
        parent->firstChild = child;
    } else {
        TreeNode* sibling = parent->firstChild;
        while (sibling->nextSibling) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = child;
    }
}

void printTree(TreeNode* root) {
    if (!root)
        return;

    cout << root->data << " ";
    TreeNode* child = root->firstChild;
    while (child) {
        printTree(child);
        child = child->nextSibling;
    }
}
int main() {

    TreeNode* root = new TreeNode(1);
    TreeNode* child2 = new TreeNode(2);
    TreeNode* child3 = new TreeNode(3);
    TreeNode* child4 = new TreeNode(4);
    TreeNode* child5 = new TreeNode(5);

    addChild(root, child2);
    addChild(root, child3);
    addChild(child2, child4);
    addChild(child2, child5);

    cout << "Tree nodes (preorder traversal): ";
    printTree(root);
    cout << endl;

    return 0;
}