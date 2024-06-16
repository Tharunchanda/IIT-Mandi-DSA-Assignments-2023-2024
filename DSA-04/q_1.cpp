#include <iostream>
#include <cstdlib> // for rand

const int maxNumberOfLevel = 5; // Maximum Level of the skip list

class Node {
public:
    int data;
    Node** next; // To maintain the levels of the skip list

    Node(int data, int level) : data(data) {
        next = new Node*[level + 1];
        for (int i = 0; i <= level; ++i)
            next[i] = nullptr;
    }

    ~Node() {
        delete[] next;
    }
};

class SkipList {
private:
    Node* head;
    int Level;

public:
    SkipList() {
        head = new Node(-1, maxNumberOfLevel);
        Level = 0;
    }

    ~SkipList() {
        Node* current = head->next[0];
        while (current) {
            Node* temp = current;
            current = current->next[0];
            delete temp;
        }
        delete head;
    }

    void insert(int data);
    bool search(int data);
    void display();
};

void SkipList::insert(int data) {
    int newLevel = 0;

    // Deciding the level of inserting node on the basis of coin toss
    while (newLevel < maxNumberOfLevel && (rand() % 2) == 1)
        newLevel++;

    // Resizing the size of the levels to make place for the inserting value
    if (Level < newLevel) {
        Node** newNext = new Node*[newLevel + 1];
        for (int i = Level + 1; i <= newLevel; ++i)
            newNext[i] = nullptr;
        for (int i = 0; i <= Level; ++i)
            newNext[i] = head->next[i];
        delete[] head->next;
        head->next = newNext;
        Level = newLevel;
    }

    Node* current = head; // pointer to the head to traverse through the skip list
    Node** update = new Node*[Level + 1]; // To store the update node at each level

    // Loop over the levels upto which we want the value to be inserted
    for (int i = Level; i >= 0; --i) {
        // Finding the place for the inserting value
        while (current->next[i] && current->next[i]->data < data) {
            current = current->next[i];
        }
        // Updating the level accordingly
        update[i] = current;
    }

    current = current->next[0]; // Moves the current to the next node at level 0

    if (!current || current->data != data) { // if the current is null then it does not exist we need to insert the value
        Node* newNode = new Node(data, Level);
        for (int i = 0; i <= newLevel; ++i) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;  // To insert the value at each level
        }
        std::cout << "Element " << data << " inserted successfully.\n";
    } else {
        std::cout << "Element " << data << " already exists.\n";  // Incase if value already exists
    }

    delete[] update;
}

bool SkipList::search(int data) {
    int comparisons = 0; // Variable to count comparisons
    Node* current = head; // start by setting a current pointer to the head node to traverse through the skip list

    for (int i = Level; i >= 0; --i) { // Begin traversing from the top level and iteratively approaching the bottom of the skip list
        while (current->next[i] && current->next[i]->data < data) // keep on moving forward if the value of the next node is less than the searching node otherwise  move downward (handled by outer for loop)
            current = current->next[i]; // moving forward
    }

    current = current->next[0]; // Move to the next of the node at level 0

    if (current && current->data == data) { // if value is found
        std::cout << "Element " << data << " found with " << comparisons << " comparisons.\n";
        return true;
    } else { // Incase value does not exist
        std::cout << "Element " << data << " not found with " << comparisons << " comparisons.\n";
        return false;
    }
}

int main() {
    SkipList skipList;
    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(9);
    skipList.insert(12);
    skipList.insert(15);
    skipList.insert(18);
    skipList.insert(21);
    skipList.insert(24);
    skipList.insert(27);
    skipList.insert(30);

    skipList.search(30);
    return 0;
}