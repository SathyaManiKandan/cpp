#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    int N = arr[n - 1] + 1;
    int min = 0, max = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = arr[i] + (arr[max] % N) * N;
            max--;
        }
        else
        {
            arr[i] = arr[i] + (arr[min] % N) * N;
            min++;
        }
        cout << arr[i] / N << " ";
    }
}
