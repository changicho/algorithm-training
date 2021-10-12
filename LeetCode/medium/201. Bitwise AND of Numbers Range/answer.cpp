#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use find most left part

class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    int count = 0;
    while (left != right) {
      ++count;
      left >>= 1;
      right >>= 1;
    }

    int answer = left << count;
    return answer;
  }
};
