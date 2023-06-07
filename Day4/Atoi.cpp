#include <bits/stdc++.h>
int atoi(string s) {
  // Write your code here.
  int n = s.size();
    int ans = 0;
    int dcount = 1;
  for (int i = n - 1; i >= 0; i--)
  {
      if(s[i] >= '0' && s[i] <= '9')
      {
          ans = (s[i]-'0')*dcount + ans;
          dcount *= 10;
      }
  }

  if(s[0] == '-') return -ans;
  else return ans;
}