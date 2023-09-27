#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use reverse pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  string decodeAtIndex(string s, int k) {
    long length = 0;
    int size = s.size();

    for (char &c : s) {
      if (isdigit(c)) {
        length *= c - '0';
      } else {
        length++;
      }
    }

    for (int i = size - 1; i >= 0; --i) {
      char c = s[i];
      k %= length;
      if (k == 0 && isalpha(c)) return (string) "" + c;

      if (isdigit(c)) {
        length /= c - '0';
      } else {
        length--;
      }
    }
    return "";
  }
};