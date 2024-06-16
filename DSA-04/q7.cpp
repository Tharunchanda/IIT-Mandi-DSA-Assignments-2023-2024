#include <iostream>
#include <ctime>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a value into the AVL Tree
TreeNode* insert(TreeNode* root, int value) {
    if (!root)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    // Update height and perform rotations (similar to previous AVL example)

    return root;
}

// Function to perform in-order traversal (sorted sequence)
void inOrder(TreeNode* root, int sorted[], int& index) {
    if (!root)
        return;
    inOrder(root->left, sorted, index);
    sorted[index++] = root->data;
    inOrder(root->right, sorted, index);
}

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 10000; // Change n as needed

    // Generate a random permutation of [1, 2, ..., n]
    int permutation[n];
    for (int i = 0; i < n; ++i)
        permutation[i] = i + 1;

    // Shuffle the permutation randomly
    std::random_shuffle(permutation, permutation + n);

    // Construct an AVL tree
    TreeNode* root = nullptr;
    for (int i = 0; i < n; ++i)
        root = insert(root, permutation[i]);

    // Perform in-order traversal to obtain the sorted sequence
    int sorted[n];
    int index = 0;
    inOrder(root, sorted, index);

    // Perform insertion sort on the same permutation
    int copyPermutation[n];
    for (int i = 0; i < n; ++i)
        copyPermutation[i] = permutation[i];

    insertionSort(copyPermutation, n);

    // Compare execution times (use clock time)
    clock_t avlStartTime = clock();
    // Perform AVL tree-based sorting (already done during in-order traversal)
    clock_t avlEndTime = clock();

    clock_t insertionStartTime = clock();
    insertionSort(copyPermutation, n);
    clock_t insertionEndTime = clock();

    double avlTime = double(avlEndTime - avlStartTime) / CLOCKS_PER_SEC;
    double insertionTime = double(insertionEndTime - insertionStartTime) / CLOCKS_PER_SEC;

    std::cout << "AVL Tree-based sorting time: " << avlTime << " seconds" << std::endl;
    std::cout << "Insertion sort time: " << insertionTime << " seconds" << std::endl;

    // Clean up memory (not shown in this example)

    return 0;
}
