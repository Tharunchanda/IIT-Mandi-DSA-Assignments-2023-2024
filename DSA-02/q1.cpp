#include<iostream>
using namespace std;

void insertion_sort(int A[],int n){
  for(int j =1;j<n;j++){
      int key = A[j];
      int i = j-1;
      while(i>0 && A[i]>key){
        A[i+1]=A[i];
        i=i-1;
      }A[i+1]=key;
  }
}
void print(int A[],int n){
  cout<<"sorted Array :";
  for (int i=0;i<n;i++){
    cout<<A[i]<<" ";
  }
}
int main(){
  int A[]= {1,5,9,3,6,7};
  int n = sizeof(A)/sizeof(A[0]);
  insertion_sort(A,n);
  print(A,n);
  return 0;
}

