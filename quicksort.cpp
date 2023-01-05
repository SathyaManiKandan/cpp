#include <bits/stdc++.h>
using namespace std;
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r], pindex = l;
    for (int i = l; i < r; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr, i, pindex);
            pindex++;
        }
    }
    swap(arr, pindex, r);
    return pindex;
}
void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
    }
};
int main()
{
    int arr[5] = {2, 4, 1, 7, 4};
    quicksort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}