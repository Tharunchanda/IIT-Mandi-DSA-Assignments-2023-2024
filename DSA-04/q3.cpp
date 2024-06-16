#include <iostream>
#include <vector>

using namespace std;

// Node structure for unbounded branch tree
struct TreeNode {
    int key;
    vector<TreeNode*> children;

    TreeNode(int k) : key(k) {}
};

// Unbounded branch tree class using array for storing children
class TreeWithArray {
public:

    TreeNode* root;
    TreeWithArray(int rootKey) {
        root = new TreeNode(rootKey);
    }

    // Function to add a child node to a parent node
    void addChild(TreeNode* parent, int childKey) {
        TreeNode* child = new TreeNode(childKey);
        parent->children.push_back(child);
    }

    // Function to perform preorder traversal
    void preorder(TreeNode* node) {
        if (node != nullptr) {
            cout << node->key << " ";
            for (TreeNode* child : node->children)
                preorder(child);
        }
    }
};

int main() {
    TreeWithArray tree(1); // Create a tree with root key 1

    // Add children to the root node
    tree.addChild(tree.root, 2);
    tree.addChild(tree.root, 3);
    tree.addChild(tree.root, 4);

    // Add children to node 2
    TreeNode* node2 = tree.root->children[0];
    tree.addChild(node2, 5);
    tree.addChild(node2, 6);

    // Add children to node 3
    TreeNode* node3 = tree.root->children[1];
    tree.addChild(node3, 7);

    // Perform preorder traversal
    cout << "Preorder traversal: ";
    tree.preorder(tree.root);

    cout << endl;

    return 0;
}
////////////////////////////////////////////////////////////////////
