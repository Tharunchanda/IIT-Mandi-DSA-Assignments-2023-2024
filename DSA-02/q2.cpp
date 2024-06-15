#include<iostream>
using namespace std;

void merge(int A[], int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;
    int l[leftSize], r[rightSize];

    for (int i = 0; i < leftSize; i++) {
        l[i] = A[low + i];
    }
    for (int i = 0; i < rightSize; i++) {
        r[i] = A[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < leftSize && j < rightSize) {
        if (l[i] <= r[j]) {
            A[k++] = l[i++];
        } else {
            A[k++] = r[j++];
        }
    }

    while (i < leftSize) {
        A[k++] = l[i++];
    }
    while (j < rightSize) {
        A[k++] = r[j++];
    }
}

void merge_sort(int A[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

void print(int A[], int n) {
    cout << "sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {1, 5, 3, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);
    merge_sort(A, 0, n - 1);
    print(A, n);
    return 0;
}
