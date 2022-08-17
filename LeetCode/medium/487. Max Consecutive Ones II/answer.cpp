#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use make pair
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int size = nums.size();
    int left = -1, right = -1;
    vector<pair<int, int>> ranges;
    for (int i = 0; i < size; i++) {
      if (nums[i] == 0) {
        if (left != -1 && right != -1) {
          ranges.push_back({left, right});
        }

        left = -1, right = -1;
        continue;
      }

      if (left == -1) left = i;
      right = i;
    }
    if (left != -1 && right != -1) {
      ranges.push_back({left, right});
    }

    int answer = 1;
    for (int i = 0; i < ranges.size(); i++) {
      pair<int, int> range = ranges[i];
      int curLength = range.second - range.first + 1;
      answer = max(answer, curLength);

      if (curLength < size) {
        answer = max(answer, curLength + 1);
      }

      if (i == 0) continue;
      pair<int, int> before = ranges[i - 1];
      if (before.second + 2 == range.first) {
        int beforeLength = before.second - before.first + 1;
        answer = max(answer, curLength + beforeLength + 1);
      }
    }
    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int size = nums.size();

    int count = 0, before = 0;
    int answer = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] == 1) {
        count++;
      } else {
        before = count;
        count = 0;
      }

      answer = max(answer, min(count + 1, size));

      if (0 <= i - count - 1 && nums[i - count - 1] == 1) {
        answer = max(answer, count + before + 1);
      }
    }

    return answer;
  }
};