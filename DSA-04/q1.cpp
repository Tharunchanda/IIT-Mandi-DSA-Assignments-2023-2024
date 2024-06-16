#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

// Node structure for Skip List
struct Node {
    int key;
    Node** forward;
    Node(int k, int level);
    ~Node() { 
        delete[] forward; 
        }
};

Node::Node(int k, int level) {
    key = k;
    forward = new Node *[level + 1];
    for (int i = 0; i < level + 1; ++i) {
        forward[i] = nullptr;
    }
}

// Skip List implementation
class SkipList {
    int MAXLVL; // Maximum level for this skip list
    float P;    // Probability
    int level;  // Current level of the skip list
    Node *header; // Header node of the skip list

public:
    SkipList(int maxlvl, float p);
    ~SkipList();
    int randomLevel();
    Node *createNode(int key, int level);
    void insertElement(int key);
    void deleteElement(int key);
    Node *searchElement(int key, int &compari5sons);
    void displayList();
};

SkipList::SkipList(int maxlvl, float p) {
    MAXLVL = maxlvl;
    P = p;
    level = 0;
    header = new Node(INT_MIN, MAXLVL);
}

SkipList::~SkipList() {
    Node *current = header->forward[0];
    while (current) {
        Node *next = current->forward[0];
        delete current;
        current = next;
    }
    delete[] header->forward;
    delete header;
}

int SkipList::randomLevel() {
    float r = (float)rand() / RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL) {
        lvl++;
        r = (float)rand() / RAND_MAX;
    }
    return lvl;
}

Node *SkipList::createNode(int key, int level) {
    Node *newNode = new Node(key, level);
    return newNode;
}

void SkipList::insertElement(int key) {
    Node *update[MAXLVL + 1];
    for (int i = 0; i < MAXLVL + 1; ++i) {
        update[i] = nullptr;
    }
    Node *current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];

    if (current == nullptr || current->key != key) {
        int newlevel = randomLevel();
        if (newlevel > level) {
            for (int i = level + 1; i < newlevel + 1; i++)
                update[i] = header;
            level = newlevel;
        }
        Node *newNode = createNode(key, newlevel);
        for (int i = 0; i <= newlevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
        cout << "Inserted element " << key << endl;
    }
}

void SkipList::deleteElement(int key) {
    Node *update[MAXLVL + 1];
    for (int i = 0; i < MAXLVL + 1; ++i) {
        update[i] = nullptr;
    }
    Node *current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];

    if (current != nullptr && current->key == key) {
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != current)
                break;
            update[i]->forward[i] = current->forward[i];
        }
        delete current;

        while (level > 0 && header->forward[level] == nullptr)
            level--;

        cout << "Deleted element " << key << endl;
    }
}

Node *SkipList::searchElement(int key, int &comparisons) {
    Node *current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key) {
            current = current->forward[i];
            comparisons++;
        }
    }

    current = current->forward[0];

    if (current != nullptr && current->key == key) {
        comparisons++;
        cout << "Element " << key << " Found" << endl;
        return current;
    } else {
        cout << "Element " << key << " Not Found" << endl;
        return nullptr;
    }
}

void SkipList::displayList() {
    cout << "Skip List:" << endl;
    for (int i = 0; i <= level; i++) {
        Node *node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != nullptr) {
            cout << node->key << " ";
            node = node->forward[i];
        }
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(0));

    SkipList sl(3, 0.5); // Maximum level is 3, probability is 0.5

    sl.insertElement(3);
    sl.insertElement(6);
    sl.insertElement(7);
    sl.insertElement(9);
    sl.insertElement(12);
    sl.insertElement(19);
    sl.insertElement(17);
    sl.insertElement(26);
    sl.insertElement(21);
    sl.insertElement(25);
    sl.displayList();

    int comparisons = 0;
    sl.searchElement(19, comparisons);
    cout << "Number of comparisons made to find the key: " << comparisons << endl;

    return 0;
}
