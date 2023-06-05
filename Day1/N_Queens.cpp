#include <bits/stdc++.h>

void solve(vector<vector<int>>& ans , vector<vector<int>> board , int n , int col , unordered_map<int,bool> isLeft , unordered_map<int,bool> isLeftTop , unordered_map<int,bool> isLeftBottom)
{
    if(col == n)
    {
        vector<int> temp;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
    }

    for(int row = 0 ; row < n ; row++)
    {
        if( !isLeft[row] && !isLeftTop[(n-1) + (row-col)] && !isLeftBottom[row+col])
        {
            board[row][col] = 1;
            isLeft[row] = true;
            isLeftTop[(n-1) + (row-col)] = true;
            isLeftBottom[row+col] = true;

            solve(ans , board , n , col+1 , isLeft , isLeftTop , isLeftBottom);
            //Backtrack
            board[row][col] = 0;
            isLeft[row] = false;
            isLeftTop[(n-1) + (row-col)] = false;
            isLeftBottom[row+col] = false;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n , vector<int>(n , 0));
    unordered_map<int,bool> isLeft;
    unordered_map<int,bool> isLeftTop;
    unordered_map<int,bool> isLeftBottom;
    solve(ans , board , n , 0 , isLeft , isLeftTop , isLeftBottom);
    return ans;
}