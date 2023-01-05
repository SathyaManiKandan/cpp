#include <bits/stdc++.h>

class Solution
{
public:
    bool isSafe(int row, int col, vector<vector<int>> &board, int n)
    {
        int x = row;
        int y = col;
        while (y >= 0)
        {
            if (board[x][y] == 1)
            {
                return false;
            }
            y--;
        }
        x = row;
        y = col;
        while (y >= 0 && x >= 0)
        {
            if (board[x][y] == 1)
            {
                return false;
            }
            y--;
            x--;
        }
        x = row;
        y = col;
        while (y >= 0 && x < n)
        {
            if (board[x][y] == 1)
            {
                return false;
            }
            y--;
            x++;
        }
        return true;
    }
    void pushAnswer(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
    {
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    temp.push_back(make_pair(j, i + 1));
                }
            }
        }
        sort(temp.begin(), temp.end());
        vector<int> perm;
        for (auto i : temp)
        {
            perm.push_back(i.second);
        }

        ans.push_back(perm);
        return;
    }
    void solve(vector<vector<int>> &ans, vector<vector<int>> &board, int col, int n)
    {
        if (col == n)
        {
            pushAnswer(board, ans, n);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 1;
                solve(ans, board, col + 1, n);
                board[row][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        int col = 0;
        solve(ans, board, col, n);
        return ans;
    }
};