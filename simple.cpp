#include <bits/stdc++.h>
using namespace std;

void solve(string str, int k, int i, string &ans)
{
    if (i == str.size() || k == 0)
        return;

    char ch = str[i];
    int j = i;
    for (int idx = i + 1; idx < str.size(); idx++)
    {
        if (str[idx] >= ch)
        {
            ch = str[idx];
            j = idx;
        }
    }
    if (str[i] != ch)
        k--;
    swap(str[i], str[j]);
    if (str.compare(ans) > 0)
        ans = str;

    solve(str, k, i + 1, ans);
    swap(str[i], str[j]);
    return;
}
// string findMaximumNum(string str, int k)

int main()
{
    string ans = "0";
    string str = "675533532219";
    int k = 0;
    // solve(str, k, 0, ans);
    char ch = 'a' + 10;
    cout << ch << endl;
}