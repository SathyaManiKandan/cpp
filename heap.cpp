#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (i != largest)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
    return;
}
void heapsort(int arr[], int n)
{
    int size = n - 1;
    while (size > 0)
    {
        swap(arr[size], arr[0]);
        size--;
        heapify(arr, size, 0);
    }
}

int main()
{
    int arr[] = {23, 34, 54, 65, 45, 57, 2, 367, 56, 34, 63, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    heapsort(arr, n);
}