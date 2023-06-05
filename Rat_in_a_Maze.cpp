#include <bits/stdc++.h>

void solve(vector<vector<int>> &maze, int n, vector<vector<int>> &ans,
           vector<vector<int>> pathMatrix, int row, int col) {
  if (row == n - 1 && col == n - 1 && maze[row][col] == 1) {
    pathMatrix[row][col] = 1;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        temp.push_back(pathMatrix[i][j]);
      }
    }
    ans.push_back(temp);
  }

  pathMatrix[row][col] = 1;
  // Top
  if (row - 1 >= 0 && pathMatrix[row - 1][col] == 0 &&
      maze[row - 1][col] == 1) {
    solve(maze, n, ans, pathMatrix, row - 1, col);
    //pathMatrix[row][col] = 0;
  }
  // Down
  if (row + 1 < n && pathMatrix[row + 1][col] == 0 && maze[row + 1][col] == 1) {
    pathMatrix[row][col] = 1;
    solve(maze, n, ans, pathMatrix, row + 1, col);
    //pathMatrix[row][col] = 0;
  }
  // Left
  if (col - 1 >= 0 && pathMatrix[row][col - 1] == 0 &&
      maze[row][col - 1] == 1) {
    pathMatrix[row][col] = 1;
    solve(maze, n, ans, pathMatrix, row, col - 1);
    //pathMatrix[row][col] = 0;
  }
  // Right
  if (col + 1 < n && pathMatrix[row][col + 1] == 0 && maze[row][col + 1] == 1) {
    pathMatrix[row][col] = 1;
    solve(maze, n, ans, pathMatrix, row, col + 1);
    //pathMatrix[row][col] = 0;
  }
  pathMatrix[row][col] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n) {
  // Write your code here.
  vector<vector<int>> ans;
  vector<vector<int>> pathMatrix(n, vector<int>(n, 0));
  solve(maze, n, ans, pathMatrix, 0, 0);
  return ans;
}