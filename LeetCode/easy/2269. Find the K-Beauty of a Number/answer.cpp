#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N * K)
// space : O(1)
class Solution {
 public:
  int divisorSubstrings(int num, int k) {
    string numStr = to_string(num);

    int count = 0;
    int length = numStr.length();
    for (int i = 0; i <= length - k; i++) {
      string cur = numStr.substr(i, k);

      int curNum = stoi(cur);
      if (curNum == 0) continue;
      if (num % curNum == 0) count++;
    }
    return count;
  }
};