#include <iostream>
//hello
using namespace std;

void binSrch(int arr[], int low, int high, int key)
{
    if (key < arr[0] || key > arr[high - 1])
    {
        cout << "Key not in range" << endl;
        return;
    }
    int mid = (low + high) / 2;
    if (low <= high)
    {
        if (arr[mid] == key)
        {
            cout << "Key found at position: " << mid << endl;
            return;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        binSrch(arr, low, high, key);
    }
    else
    {
        cout << "Key is not fount in Arr" << endl;
        return;
    }
}

int main()
{
    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i;
    }
    int key = -1;
    cout << "Enter the key you want to search:" << endl;
    cin >> key;
    binSrch(arr, 0, sizeof(arr) / sizeof(arr[0]), key);
}
