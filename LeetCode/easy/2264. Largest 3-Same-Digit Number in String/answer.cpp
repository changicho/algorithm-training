#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(1)
class Solution {
 public:
  string largestGoodInteger(string num) {
    int length = num.length();

    string largest = "";

    for (int i = 0; i <= length - 3; i++) {
      string cur = {num[i]};
      for (int j = 1; j < 3; j++) {
        cur += num[i + j];
      }

      if (cur[0] == cur[1] && cur[1] == cur[2]) {
        largest = max(largest, cur);
      }
    }

    return largest;
  }
};