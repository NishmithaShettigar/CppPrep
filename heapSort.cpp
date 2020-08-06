#include<iostream>

using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
        if ((i+1)%15==0)
            cout<<endl;
    }
    cout<<endl;

}
// MaxHeapify: For array arr of size n(heap size), heapify with top down approach
/*  This function considers i as the root for the binary (sub)tree,
    and recursively converts its child sub trees to max heap */
void heapify(int arr[], int n, int i) {
    int lar = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if (l<n && arr[l] > arr[lar]) {
        lar = l;
    }
    if (r<n && arr[r] > arr[lar]) {
        lar = r;
    }
    if (lar != i) {
        int temp = arr[i];
        arr[i] = arr[lar];
        arr[lar] = temp;

        heapify(arr, n, lar);
    }
}

void heapSort(int arr[], int n) {
    // Convert the existing array into MaxHeap
    for (int i = (n/2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n-1; i >=0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr, i, 0);
    }

}

int main() {

    int n = 20, arr[n];
    // arr[i] = i
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    // Shuffling the Array Fisher Yates algo;
    for (int i = n-1; i > 1; i--)
    {
        int randIndex = rand() % i;
        int temp = arr[randIndex];
        arr[randIndex] = arr[i];
        arr[i] = temp;
    }

    printArr(arr, n);

    heapSort(arr, n);
    cout<<endl<<"After Heap Sort"<<endl<<endl;
    printArr(arr, n);
}

// 8762840329