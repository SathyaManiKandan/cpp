#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int ln = m - l + 1;
    int rn = r - m;
    int larr[ln];
    int rarr[rn];
    int count = 0;

    for (int i = 0; i < ln; i++)
    {
        larr[i] = arr[l + i];
    }
    for (int j = 0; j < rn; j++)
    {
        rarr[j] = arr[m + j + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < ln && j < rn)
    {
        if (larr[i] < rarr[j])
        {
            arr[k] = larr[i];
            i++;
            k++;
            count++;
        }
        if (rarr[j] < larr[i])
        {
            arr[k] = rarr[j];
            j++;
            k++;
            count++;
        }
    }
    while (i < ln)
    {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < rn)
    {
        arr[k] = rarr[j];
        j++;
        k++;
    }
    cout << count << " ";
}
void mergeSort(int arr[], int l, int r)
{
    // code here
    if (l < r)
    {
        int m = (r + l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int arr[6] = {3, 352, 452534, 25, 24, 223};
    mergeSort(arr, 0, 5);
    // for (int i = 0; i < 6; i++)
    //   cout << arr[i] << " ";
}