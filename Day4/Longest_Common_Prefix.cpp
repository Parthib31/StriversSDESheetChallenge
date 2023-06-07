string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    if(n == 1) return arr[0];
    string prefix = "";

    for(int i = 0 ; i < arr[0].size() ; i++)
    {
        bool mismatched = false;
        for(int j = 1 ; j < n ; j++)
        {
          if (i == arr[j].size() || arr[j][i] != arr[0][i]) {
            mismatched = true;
            break;
          }
        }
        if(mismatched) break;
        prefix += arr[0][i];
    }
    return prefix;
}


