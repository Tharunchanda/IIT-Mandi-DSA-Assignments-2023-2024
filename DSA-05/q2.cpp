#include<iostream>
using namespace std;

void Max_Heapify(int Arr[], int heap_size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < heap_size && Arr[l] > Arr[largest]) {
        largest = l;
    }
    if (r < heap_size && Arr[r] > Arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(Arr[i], Arr[largest]);
        Max_Heapify(Arr, heap_size, largest);
    }
}

void Build_Max_Heap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        Max_Heapify(A, n, i);
    }
    cout << "Max_Heap Created" << endl;
}

void Max_Heap_Increase_key(int A[], int i, int key) {
    cout << "Entered Element:" << key << endl;
    if (key < A[i]) {
        cout << "you are tying to decrease (ERROR)" << endl;
        return;
    }
    A[i] = key;
    while (i > 0 && A[(i - 1) / 2] < A[i]) {
        swap(A[i], A[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void Print(int A[], int n) {
    cout << "array : ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Max_Heap_Insert(int A[], int& n, int key) {
    cout << "Inserting Element :"<<key<<endl;
    n++;
    A[n - 1] = key;
    Max_Heap_Increase_key(A, n - 1, key);
}

int main() {
    int Arr[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    Print(Arr, n);
    Max_Heap_Increase_key(Arr, 1, 5);
    Print(Arr, n);
    Max_Heap_Insert(Arr, n, 11);
    Print(Arr,n);
    return 0;
}
