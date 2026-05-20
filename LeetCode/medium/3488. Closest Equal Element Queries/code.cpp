#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// two pass
// time : O(N + Q)
// space : O(N + Q)
class Solution {
 public:
  vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int size = nums.size();

    vector<int> nexts(size, -1);
    vector<int> prevs(size, -1);

    unordered_map<int, int> last;

    for (int i = 0; i < size; i++) {
      int num = nums[i];

      if (last.count(num)) {
        int diff = i - last[num];
        nexts[last[num]] = diff;
        prevs[i] = diff;
      }

      last[num] = i;
    }

    for (int i = 0; i < size; i++) {
      int num = nums[i];
      if (last.count(num) && last[num] != i && prevs[i] == -1) {
        int diff = abs(size - last[num] + i);
        nexts[last[num]] = diff;
        prevs[i] = diff;
      }
    }

    vector<int> answer;
    for (int& q : queries) {
      int target = nums[q];

      if (nexts[q] == -1) {
        answer.push_back(-1);
        continue;
      }

      int minimum = min(nexts[q], prevs[q]);

      answer.push_back(minimum);
    }
    return answer;
  }
};

// one pass
// time : O(N + Q)
// space : O(N + Q + M)
class Solution {
 public:
  vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int size = nums.size();

    vector<int> nexts(size, INT_MAX);
    vector<int> prevs(size, INT_MAX);

    int first[1000001] = {
        0,
    };
    int last[1000001] = {
        0,
    };

    for (int i = 0; i < size; i++) {
      int num = nums[i];

      if (first[num] == 0) {
        first[num] = i + 1;
      } else {
        // circular
        int diff = size - (i + 1) + first[num];

        nexts[i] = min(diff, nexts[i]);
        prevs[first[num] - 1] = min(diff, prevs[first[num] - 1]);
      }

      if (last[num] != 0) {
        int diff = (i + 1) - last[num];
        nexts[last[num] - 1] = diff;
        prevs[i] = diff;
      }

      last[num] = i + 1;
    }

    vector<int> answer;
    for (int& q : queries) {
      int target = nums[q];

      if (nexts[q] == INT_MAX) {
        answer.push_back(-1);
        continue;
      }

      int minimum = min(nexts[q], prevs[q]);

      answer.push_back(minimum);
    }
    return answer;
  }
};