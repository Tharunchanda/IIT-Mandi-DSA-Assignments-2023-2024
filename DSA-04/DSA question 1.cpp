#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime> 

#define MAX_LEVEL 6
const float P = 0.5;

using namespace std;

struct snode {
    int value;
    snode** forw;

    snode(int level, int& value) {
        forw = new snode*[level + 1];
        memset(forw, 0, sizeof(snode*) * (level + 1));
        this->value = value;
    }

    ~snode() {
        delete[] forw;
    }
};

struct skiplist {
    snode* header;
    int value;
    int level;

    skiplist() {
        header = new snode(MAX_LEVEL, value);
        level = 0;
    }

    ~skiplist() {
        delete header;
    }

    bool contains(int&);
    void insert_element(int&);
    void delete_element(int&);
    void display();
    bool search_element(int&);
};

float frand() {
    return static_cast<float>(rand()) / RAND_MAX;
}

int random_level() {
    static bool first = true;
    if (first) {
        srand(static_cast<unsigned>(time(NULL)));
        first = false;
    }
    int lvl = static_cast<int>(log(frand()) / log(1. - P));
    return (lvl < MAX_LEVEL) ? lvl : MAX_LEVEL;
}

void skiplist::insert_element(int& value) {
    snode* x = header;
    snode* update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(snode*) * (MAX_LEVEL + 1));

    for (int i = level; i >= 0; --i) {
        while (x->forw[i] != nullptr && x->forw[i]->value < value) {
            x = x->forw[i];
        }
        update[i] = x;
    }

    x = x->forw[0];
    if (x == nullptr || x->value != value) {
        int lvl = random_level();
        if (lvl > level) {
            for (int i = level + 1; i <= lvl; ++i) {
                update[i] = header;
            }
            level = lvl;
        }

        x = new snode(lvl, value);
        for (int i = 0; i <= lvl; ++i) {
            x->forw[i] = update[i]->forw[i];
            update[i]->forw[i] = x;
        }
    }
}

bool skiplist::search_element(int& value) {
    snode* x = header;
    for (int i = level; i >= 0; --i) {
        while (x->forw[i] != nullptr && x->forw[i]->value < value) {
            x = x->forw[i];
        }
    }
    x = x->forw[0];
    return (x != nullptr && x->value == value);
}

void skiplist::display() {
    const snode* x = header->forw[0];
    while (x != nullptr) {
        cout << x->value << " ";
        x = x->forw[0];
    }
    cout << endl;
}

int main() {
    skiplist ss;
    int choice, element;
    bool found;

    do {
        cout << "1. Insert Element" << endl;
        cout << "2. Search Element" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                ss.insert_element(element);
                break;
            case 2:
                cout << "Enter element to search: ";
                cin >> element;
                found = ss.search_element(element);
                if (found)
                    cout << "Element found." << endl;
                else
                    cout << "Element not found." << endl;
                break;
            case 3:
                cout << "Skip List: ";
                ss.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
