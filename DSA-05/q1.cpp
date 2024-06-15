#include <iostream>
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

void Print_Max(int A[], int n) {
    if (n == 0) {
        cout << "Array is empty" << endl;
    } else {
        cout << "Max element in Max_Heap :" << A[0] << endl;
    }
}

int Extract_Max(int A[], int& n) {
    if (n == 0) {
        cerr << "Heap is empty" << endl;
        return -1;
    }
    int max_element = A[0];
    A[0] = A[n - 1];
    n--;
    Max_Heapify(A, n, 0);
    cout << "Extracted Max Element: " << max_element << endl;
    return max_element;
}

void Print(int A[], int n) {
    cout << "array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int Arr[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    Build_Max_Heap(Arr, n);
    Print(Arr, n);
    Print_Max(Arr, n);
    Extract_Max(Arr, n);
    Print(Arr, n);
    Print_Max(Arr, n);
    return 0;
}
