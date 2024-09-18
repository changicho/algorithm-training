#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int answer = 0;
    int maximum = -1;

    int before = -1;
    int count = 0;
    for (int& cur : nums) {
      if (before == cur) {
        count++;
      } else {
        before = cur;
        count = 1;
      }

      if (before > maximum) {
        answer = count;
        maximum = before;
      } else if (cur == maximum) {
        answer = max(answer, count);
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
  int longestSubarray(vector<int>& nums) {
    int answer = 0;
    int maximum = 0;
    int count = 0;
    for (int& cur : nums) {
      if (maximum < cur) {
        maximum = cur;
        answer = 0;
        count = 0;
      }

      if (maximum == cur) {
        count++;
      } else {
        count = 0;
      }

      answer = max(answer, count);
    }
    return answer;
  }
};