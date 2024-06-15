#include <iostream>
using namespace std;

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
    void push(int key){        
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
    int pop(){
        if(!Underflow()){
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
        return -1;
        cout<<"underflow";
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

string Matching(string str)
{
    string parenthesisStart = "[{(";
    string parenthesisEnd = "]})";
    stack stk;
    int size = str.length();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 3; j++ ){
            if(str[i] == parenthesisStart[j]){
                stk.push(j);     
            }
            else if(str[i] == parenthesisEnd[j]){
                int poppedIndex = stk.pop();
                
                if(poppedIndex != j){
                    return "It is not following Parenthesis Matching";
                }
            }
        }
    }
    if(stk.Underflow()){
        return "It is following Parenthesis Matching";
    }
    else{
        return "It is not following Parenthesis Matching";
    }
}

int main(){
string a = "(a) + (b)";
string b = "{abc)";

cout<<Matching(a)<<endl;
cout<<Matching(b)<<endl;
}