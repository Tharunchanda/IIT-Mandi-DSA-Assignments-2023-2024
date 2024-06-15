#include <iostream>
using namespace std;
int MAX = 100;
class Node{
    public:
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;
};
class stack
{
    private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;
    public:
    bool Underflow(){
        if (head == nullptr){
            return true;
        }
        return false;
    }
    bool Overflow(){
        if (length == MAX){
            return true;
        }
        return false;
    }
    void push(int key){
        if(!Overflow()){
         Node* newnode = new Node;
        newnode->value = key;
        if (head == nullptr) {
        head = newnode;
        tail = newnode;
         } 
        else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    length++;
        }
        else{
            cout<<"It is overflow";
        }
    }
    int pop(){
        if(!Underflow() && tail != nullptr){
            int key = tail->value;
            if (length > 1) {
        tail->prev->next = nullptr;
        tail = tail->prev;
    } else if (length == 1) {
        tail = nullptr;
        head = nullptr;
    }
    length--;
            return key;    
        }
        cout<<"underflow";
        return -1;
    }
        
void printstack(){
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

void TOH(stack &A, stack &B, stack &C, int n){

    if(n > 0){
        TOH(A,C,B,n-1);
        C.push(A.pop());
        TOH(B,A,C,n-1);
    }
}
int main(){
    stack A;
    stack B;
    stack C;
    for(int i = 10; i > 0; i--){
    A.push(i);
    }
    A.printstack();
    B.printstack();
    C.printstack();
    TOH(A,B,C,10);
    A.printstack();
    B.printstack();
    C.printstack();
}