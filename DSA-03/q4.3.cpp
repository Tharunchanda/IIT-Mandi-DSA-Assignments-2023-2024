#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    int index;
};
void MatrixMaking(int B[5][6], Node* First[5]) {
    for (int j = 0; j < 5; j++) {
        First[j] = new Node;
        int x = 0;
        Node* temp = First[j];
        for (int i = 0; i < 6; i++) 
        { 
            
            if(B[j][i] != 0){
            if(x == 0){
                First[j]->value = B[j][i];
                First[j]->index = i;
            x++; 
            }
            else
            {
            Node* newnode = new Node;
            newnode->value = B[j][i];
            newnode->index = i;
            temp->next = newnode;
            temp = temp->next;

            }
            
            }
        }
        temp->next = nullptr; 
    }
}

void PrintMatrix(Node* First[5]) {
    for (int i = 0; i < 5; i++) {
        Node* temp = First[i];
        while (temp != nullptr) {
            cout << temp->value<<","<< temp->index;
            temp = temp->next;
            if (temp != nullptr) {
                cout << "->";
            }
        }
        cout << endl;
    }
}

void MatrixMultiplication(Node* First[5], Node* Second[5], int R[6][6]){
    R[6][6] = {};
    for(int i = 0; i < 5; i++){
        
        for(int j = 0;j < 5; j++){
        Node* tempj = Second[j];
        Node* tempi = First[i];
        int value = 0;
        while(tempi != nullptr && tempj != nullptr){
            if(tempi->index == tempj->index){
                value += tempi->value * tempj->value;
                tempj = tempj->next;
            }
            else if(tempi->index < tempj->index){
                tempi = tempi->next;
            }
            else{
                tempj = tempj->next;
            }
        }
        R[i][j] = value;

        }
    }
}

int main() {

    int B[5][6] =
    {
        {0 , 0 , 0 , 0 , 1, 0 },
        {0 , 5 , 0 , 2 , 0, 0 },
        {0 , 0 , 1 , 0 , 0, 5 },
        {2 , 8 , 0 , 0 , 1, 0 },
        {0 , 0 , 4 , 0 , 0, 0 }
    };
     int A[5][6] = 
    { 
        {0 , 0 , 0 , 0 , 9, 0 }, 
        {0 , 8 , 0 , 0 , 0, 0 }, 
        {4 , 0 , 0 , 2 , 0, 0 }, 
        {0 , 0 , 0 , 0 , 0, 5 }, 
        {0 , 0 , 2 , 2 , 0, 0 } 
    };
    int R[6][6] = {};
    Node* First[5] = {nullptr,nullptr,nullptr,nullptr,nullptr};
    Node* Second[5] = {nullptr,nullptr,nullptr,nullptr,nullptr};
    MatrixMaking(B, Second);
    MatrixMaking(A, First);
    PrintMatrix(First);
    cout<<endl;
    PrintMatrix(Second);
    MatrixMultiplication(First , Second , R);
    cout << "Result Matrix:" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
}
