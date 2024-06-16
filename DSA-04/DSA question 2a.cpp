#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTreeArray {
private:
    vector<int> tree;

public:
    BinaryTreeArray() {}

    void insert(int val) {
        tree.push_back(val);
    }

    bool search(int val) {
        for (int node_val : tree) {
            if (node_val == val)
                return true;
        }
        return false;
    }

    void remove(int val) {
        for (int i = 0; i < tree.size(); ++i) {
            if (tree[i] == val) {
                tree[i] = tree.back();
                tree.pop_back();
                return;
            }
        }
    }

    void display() {
        cout << "Binary Tree: ";
        for (int node_val : tree) {
            cout << node_val << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTreeArray tree;

    int choice, element;
    bool found;

    do {
        cout << "1. Insert Element" << endl;
        cout << "2. Search Element" << endl;
        cout << "3. Delete Element" << endl;
        cout << "4. Display Tree" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                tree.insert(element);
                break;
            case 2:
                cout << "Enter element to search: ";
                cin >> element;
                found = tree.search(element);
                if (found)
                    cout << "Element found." << endl;
                else
                    cout << "Element not found." << endl;
                break;
            case 3:
                cout << "Enter element to delete: ";
                cin >> element;
                tree.remove(element);
                break;
            case 4:
                tree.display();
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
