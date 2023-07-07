#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  struct Range {
    int left, right;
  };

 public:
  int longestSubarray(vector<int>& nums) {
    int size = nums.size();

    Range before = {INT_MIN, INT_MIN};
    Range cur = {INT_MIN, INT_MIN};
    int answer = 0;
    int zeroCount = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] == 0) {
        zeroCount++;
        before = cur;

        cur = {INT_MIN, INT_MIN};
      } else {
        if (cur.left == INT_MIN) cur.left = i;
        cur.right = i;
      }

      if (cur.left != INT_MIN) {
        answer = max(answer, cur.right - cur.left + 1);
      }

      if (before.right + 2 == cur.left) {
        int beforeLength = before.right - before.left + 1;
        int curLength = cur.right - cur.left + 1;
        answer = max(answer, beforeLength + curLength);
      }
    }

    if (zeroCount == 0) return size - 1;
    return answer;
  }
};