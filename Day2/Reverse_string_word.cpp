#include <bits/stdc++.h>

string reverseString(string &str) {
  // Write your code here.
  int n = str.size();
  if (n == 0)
    return "";

  stack<string> helperStack;
  string ans = "";
  string temp = "";
  int i = 0;
  while (i < n) {
    while (i < n && str[i] == ' ')
      i++;

    if (i == n)
      break;

    while (i < n && str[i] != ' ') {
      temp += str[i];
      i++;
    }

    helperStack.push(temp);
    temp = "";
  }

  if (!helperStack.empty()) {
    ans += helperStack.top();
    helperStack.pop();
  }
  
  while(!helperStack.empty())
  {
	  ans = ans + " " + helperStack.top();
	  helperStack.pop();
  }
  return ans;
}