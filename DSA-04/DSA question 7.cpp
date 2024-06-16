#include <iostream>
#include <ctime>
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

    void inorderTraversal() {
        inorderHelper(root);
        cout << endl;
    }
};

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter the value of n (put greater than 202000): ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = i + 1;

    random_shuffle(arr, arr + n);

    clock_t start, end;
    double avlTime, insertionTime;

    AVLTree avl;
    start = clock();
    for (int i = 0; i < n; ++i)
        avl.insert(arr[i]);
    end = clock();
    avlTime = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    insertionSort(arr, n);
    end = clock();
    insertionTime = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "AVL Tree Time: " << avlTime << " seconds" << endl;
    cout << "Insertion Sort Time: " << insertionTime << " seconds" << endl;

    delete[] arr;
    return 0;
}
