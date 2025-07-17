#include <iostream>
using namespace std;

int partition(int a[], int start, int end)
{
    int pivot = a[start];
    int i = start+1;

    for (int j = start + 1; j <= end; j++) {
        if (a[j] < pivot) {
            //i++;
            swap(a[i], a[j]);i++;
        }
    }
    swap(a[start], a[i-1]); // Correct placement of pivot
    return i-1;
}

void quick(int a[], int start, int end)
{
    if (start < end) {
        int p = partition(a, start, end);
        quick(a, start, p - 1);
        quick(a, p + 1, end);
    }
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int a[] = { 23, 8, 28, 13, 18, 26,3,8,3,8,3,6 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Before sorting array elements are - \n";
    printArr(a, n);
    quick(a, 0, n - 1);
    cout << "\nAfter sorting array elements are - \n";
    printArr(a, n);
    return 0;
}

