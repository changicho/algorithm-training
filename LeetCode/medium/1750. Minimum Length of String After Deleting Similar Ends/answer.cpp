#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointers
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumLength(string s) {
    int size = s.size();

    int left = 0, right = size - 1;

    while (left < right) {
      char cur = s[left];
      int leftMove = 0, rightMove = 0;

      while (left < right && s[left] == cur) {
        left++;
        leftMove++;
      }

      while (right >= left && s[right] == cur) {
        right--;
        rightMove++;
      }

      if (leftMove == 0 || rightMove == 0) {
        left -= leftMove;
        right += rightMove;
        break;
      }
    }

    return right - left + 1;
  }
};