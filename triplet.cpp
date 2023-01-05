#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[5] = {0, 3, 5, 1, 6};
    int arr2[4] = {9, 8, 7, 2};
    int m = 5, n = 4;
    int num = m + n;
    long long arr[num];

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr[m - 1 + i] = arr2[i];
    }
    sort(arr, arr + num);
    for (int i = 0; i < num; i++)
        cout << arr[i] << endl;
    return 0;
}
