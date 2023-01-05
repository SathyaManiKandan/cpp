#include <bits/stdc++.h>
using namespace std;
void reverse(string &str, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    cout << "I am called" << endl;
    swap(str[s++], str[e--]);
    reverse(str, s, e);
}
int main()
{
    string name = "Sathya";
    cout << "HI" << endl;
    reverse(name, 0, name.size() - 1);
    cout << name << endl;
}