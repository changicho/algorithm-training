#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use part reverse with total reverse

class Solution {
 public:
  void reverseWords(vector<char>& s) {
    int left = 0, right = 0;

    for (char c : s) {
      if (c == ' ') {
        reverse(s.begin() + left, s.begin() + right);

        left = right + 1;
      }
      right += 1;
    }
    reverse(s.begin() + left, s.begin() + right);

    reverse(s.begin(), s.end());
  }
};