#include <iostream>
#include <queue>

using namespace std;

// Node structure for linked implementation
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Tree class using arrays
class ArrayBinaryTree {
private:
    int *tree;
    int capacity;
    int size;

public:
    
    ArrayBinaryTree(int cap) {
        capacity = cap;
        tree = new int[capacity];
        size = 0;
    }
    void print(){
            for( int i=0;i<size;i++){
                cout<<tree[i]<<" ";
            }
    }
    // Insertion in binary tree
    void insert(int val) {
        if (size < capacity) {
            tree[size++] = val;
            cout<<endl;
            cout << "Inserted " << val << " into the binary tree." << endl;
        } else {
            cout << "Binary tree is full. Cannot insert." << endl;
        }
        print();
    }

    // Search operation in binary tree
    bool search(int val) {
        for (int i = 0; i < size; ++i) {
            if (tree[i] == val) {
                return true;
            }
        }
        return false;
    }

    // Deletion operation in binary tree
    void deleteNode(int val) {
        int i;
        for (i = 0; i < size; ++i) {
            if (tree[i] == val) {
                break;
            }
        }
        if (i == size) {
            cout << val << " not found in the binary tree. Cannot delete." << endl;
            return;
        }

        tree[i] = tree[--size];
        cout << "Deleted " << val << " from the binary tree." << endl;
        print();
    }
};
////////////////////////////////////////////////////////////////////////////////////////
// Binary Tree class using linked implementation
class LinkedBinaryTree {
private:
    TreeNode* root;

public:
    LinkedBinaryTree()
    {
        root = nullptr;
    }
    // for printing tree
    // void printInOrder(TreeNode* node) {
    //     if (node == nullptr)
    //         return;

    //     printInOrder(node->left);
    //     cout << node->data << " ";
    //     printInOrder(node->right);
    // }

    // // Function to initiate in-order traversal from the root
    // void printTree() {
    //     cout << "Binary Tree (In-order traversal): ";
    //     printInOrder(root);
    //     cout << endl;
    // }
    // Insertion in binary tree
    void insert(int val) {
        if (!root) {
            root = new TreeNode(val);
            cout << "Inserted " << val << " into the binary tree." << endl;
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        // printTree();
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            else {
                curr->left = new TreeNode(val);
                cout << "Inserted " << val << " into the binary tree." << endl;
                return;
            }
            if (curr->right)
                q.push(curr->right);
            else {
                curr->right = new TreeNode(val);
                cout << "Inserted " << val << " into the binary tree." << endl;
                return;
            }
        }
    }
    bool search(int val) {
        if (!root)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->data == val)
                return true;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        return false;
    }

    // Deletion operation in binary tree
    void deleteNode(int val) {
        if (!root) {
            cout << "Tree is empty. Cannot delete." << endl;
            return;
        }
        TreeNode* deepest = nullptr;
        TreeNode* keyNode = nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            deepest = q.front();
            q.pop();
            if (deepest->data == val)
                keyNode = deepest;
            if (deepest->left)
                q.push(deepest->left);
            if (deepest->right)
                q.push(deepest->right);
        }
        if (!keyNode) {
            cout << val << " not found in the binary tree. Cannot delete." << endl;
            return;
        }
        keyNode->data = deepest->data;
        deleteDeepestNode(deepest);
        cout << "Deleted " << val << " from the binary tree." << endl;
    }

private:
    void deleteDeepestNode(TreeNode* node) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while (!q.empty()) {
            temp = q.front();
            q.pop();

            if (temp == node) {
                temp = nullptr;
                delete node;
                return;
            }
            if (temp->right) {
                if (temp->right == node) {
                    temp->right = nullptr;
                    delete node;
                    return;
                } else
                    q.push(temp->right);
            }
            if (temp->left) {
                if (temp->left == node) {
                    temp->left = nullptr;
                    delete node;
                    return;
                } else
                    q.push(temp->left);
            }
        }
    }
};

int main() {
    // Array binary tree
    ArrayBinaryTree arrayTree(10);
    arrayTree.insert(5);
    arrayTree.insert(3);
    arrayTree.insert(7);
    arrayTree.insert(2);
    arrayTree.insert(8);
    arrayTree.insert(1);
    std::cout << "Search 5: " << (arrayTree.search(5) ? "Found" : "Not found") << endl;
    arrayTree.deleteNode(5);
    cout << "Search 5: " << (arrayTree.search(5) ? "Found" : "Not found") << endl;

    cout << endl;

    // Linked binary tree
    LinkedBinaryTree linkedTree;
    linkedTree.insert(5);
    linkedTree.insert(3);
    linkedTree.insert(7);
    linkedTree.insert(2);
    cout << "Search 7: " << (linkedTree.search(7) ? "Found" : "Not found") << endl;
    linkedTree.deleteNode(7);
    cout << "Search 7: " << (linkedTree.search(7) ? "Found" : "Not found") << endl;

    return 0;
}
