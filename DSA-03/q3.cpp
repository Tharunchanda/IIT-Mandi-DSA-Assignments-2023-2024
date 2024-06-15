#include <iostream>
using namespace std;

class Node{
    public:
    int value = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class LinkedList{
    public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;
    void extend(int value){
        Node* newnode = new Node;
        newnode->value = value;
        if (head == nullptr){
            head = newnode;
            tail = newnode;
        }
        else{
           tail->next = newnode;
           newnode->prev = tail;
           tail = newnode;
        }
        length++;
    }
   void print()
   {
    Node* temp = head; 
    cout << "{";
    while (temp != nullptr) {
        cout << temp->value;
        temp = temp->next;
        if (temp != nullptr) {
            cout << ",";
        }
    }
    cout << "}" << endl;
   }

};
void insertionSort(LinkedList list){
    Node* temp = list.head;
    for(int j = 1; j < list.length; j++){
        temp = temp->next;
        int key = temp->value;
        Node* temp2 = temp->prev;
        Node* temp3 = nullptr;
        while(temp2 != nullptr && temp2->value > key){
            temp2->next->value = temp2->value;
            temp3 = temp2;      
            temp2 = temp2->prev;
        }
        if(temp3!=nullptr){
        temp3->value = key;
    }
    }
}
int main(){
    LinkedList list;
    for(int i = 10; i > 0; i--){
    list.extend(i);
    }
    list.print();
    insertionSort(list);
    list.print();
}