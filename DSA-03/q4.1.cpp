#include <iostream>
using namespace std;


void MatrixDenseMultiplication(int A[5][6],int B[5][6],int R[6][6]){
 int C[6][5] = {};
for(int i = 0; i < 6; i++){
        for(int j = 0; j <= i; j++){
            C[j][i] = B[i][j];
            C[i][j] = B[j][i];
        }
    }

    for(int i = 0; i < 5;i++){
        for(int j = 0; j <5; j++){
            R[i][j] = 0;
            for(int k = 0; k < 6; k++){
                R[i][j] += A[i][k] * C[k][j];
            }
        }
    }
}



int main(){
     int A[5][6] = 
    { 
        {0 , 0 , 0 , 0 , 9, 0 }, 
        {0 , 8 , 0 , 0 , 0, 0 }, 
        {4 , 0 , 0 , 2 , 0, 0 }, 
        {0 , 0 , 0 , 0 , 0, 5 }, 
        {0 , 0 , 2 , 2 , 0, 0 } 
    }; 
int B[5][6] =
 {
 {0 , 0 , 0 , 0 , 1, 0 },
 {0 , 5 , 0 , 2 , 0, 0 },
 {0 , 0 , 1 , 0 , 0, 5 },
 {2 , 8 , 0 , 0 , 1, 0 },
 {0 , 0 , 4 , 0 , 0, 0 }
 };


int R[6][6] = {};
MatrixDenseMultiplication(A,B,R);
    cout << "Result Matrix:" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << R[i][j] << "   ";
        }
        cout << endl;
    }
}