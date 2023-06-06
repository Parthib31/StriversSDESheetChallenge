#include <bits/stdc++.h>

int expand(string s, int i, int j) {
  int n = s.size();
  while (i >= 0 && j < n && s[i] == s[j]) {
    i--;
    j++;
  }
  return j - i - 1;
}

string longestPalinSubstring(string s) {
  // Write your code here.
  int n = s.size();
  int maxLen = 1;
  int ind1 = 0, ind2 = 0;
  for (int i = 0; i < n; i++) {
    int oddP = expand(s, i, i);
    if (oddP > maxLen) {
      int dist = (oddP / 2);
      ind1 = i - dist;
      ind2 = i + dist;
      maxLen = oddP;
    }

    if (i == n - 1)
      break;
    int evenP = expand(s, i, i + 1);
    if (evenP > maxLen) {
      int dist = (evenP / 2) - 1;
      ind1 = i - dist;
      ind2 = i + 1 + dist;
      maxLen = evenP;
    }
  }

  return s.substr(ind1, ind2 - ind1 + 1);
}