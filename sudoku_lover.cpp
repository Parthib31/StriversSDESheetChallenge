bool check(int matrix[9][9] , int row , int col , int num)
{
    for(int i = 0 ; i< 9 ; i++)
    {
        //Same row check
        if(matrix[row][i] == num)
            return false;

        //Same col check
        if(matrix[i][col] == num)
            return false;

        //Same sub-matrices check
        if(matrix[3*(row/3) + i/3][3*(col/3) + i%3] == num)
            return false;
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            if(matrix[i][j] == 0)
            {
                for(int k = 1 ; k <=9 ; k++)
                {
                    if(check(matrix , i , j , k))
                    {
                        matrix[i][j] = k;
                        bool next = isItSudoku(matrix);
                        if(next)
                            return true;

                        matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
}
