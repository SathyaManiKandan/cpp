#include <bits/stdc++.h>
#include <stack>
#include <queue>
using namespace std;

int main()
{

    deque<int> q1;
    deque<int> q2;
    stack<int> s;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);
    q1.push(7);
    q1.push(8);
    int n = q1.size();
    for (int i = 0; i < n / 2; i++)
    {
        int val = q1.front();
        q2.push(val);
        q1.pop_front();
    }
}
