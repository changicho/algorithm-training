#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use binary search
// time : O(N^2 * log_2(N))
// space : O(N^2)
class Solution {
 public:
  long long countQuadruplets(vector<int>& nums) {
    int size = nums.size();

    vector<int> lefts[4001], rights[4001];

    for (int i = 0; i < size; i++) {
      if (i - 1 >= 0) lefts[i] = lefts[i - 1];

      auto target = lower_bound(lefts[i].begin(), lefts[i].end(), nums[i]);
      lefts[i].insert(target, nums[i]);
    }
    for (int i = size - 1; i >= 0; i--) {
      if (i + 1 < size) rights[i] = rights[i + 1];
      auto target = lower_bound(rights[i].begin(), rights[i].end(), nums[i]);
      rights[i].insert(target, nums[i]);
    }

    long long answer = 0;
    for (int j = 1; j < size - 1; j++) {
      for (int k = j + 1; k < size - 1; k++) {
        if (nums[j] <= nums[k]) continue;

        int leftCounts =
            (lower_bound(lefts[j - 1].begin(), lefts[j - 1].end(), nums[k]) -
             lefts[j - 1].begin());
        int rightCounts =
            rights[k + 1].size() -
            (upper_bound(rights[k + 1].begin(), rights[k + 1].end(), nums[j]) -
             rights[k + 1].begin());

        // valid case
        answer += leftCounts * rightCounts;
      }
    }

    return answer;
  }
};

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  long long countQuadruplets(vector<int>& nums) {
    int size = nums.size();

    // lessThan[num][i]; the number of elements less than `num` in the first i
    // elements of nums.
    vector<vector<int>> lessThan(size + 1, vector<int>(size + 2, 0));
    vector<vector<int>> greaterThan(size + 1, vector<int>(size + 2, 0));

    for (int num = 1; num <= size; num++) {
      for (int i = 1; i <= size; i++) {
        lessThan[num][i] = lessThan[num][i - 1] + (nums[i - 1] < num);
      }
    }
    for (int num = size; num >= 1; num--) {
      for (int i = size - 1; i >= 1; i--) {
        greaterThan[num][i] = greaterThan[num][i + 1] + (nums[i] > num);
      }
    }

    long long answer = 0;
    for (int j = 1; j < size - 2; j++) {
      for (int k = j + 1; k < size - 1; k++) {
        if (nums[j] > nums[k]) {
          int right = greaterThan[nums[j]][k];
          int left = lessThan[nums[k]][j];

          answer += right * left;
        }
      }
    }
    return answer;
  }
};

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  long long countQuadruplets(vector<int>& nums) {
    int size = nums.size();

    // lessThan[num][i]; the number of elements less than `num` in the first i
    // elements of nums.
    vector<vector<int>> lessThan(size + 1, vector<int>(size + 2, 0));

    for (int num = 1; num <= size; num++) {
      for (int i = 1; i <= size; i++) {
        lessThan[num][i] = lessThan[num][i - 1] + (nums[i - 1] < num);
      }
    }

    long long answer = 0;
    for (int j = 1; j < size - 2; j++) {
      for (int k = j + 1; k < size - 1; k++) {
        if (nums[j] > nums[k]) {
          int right = (size - nums[j]) - (k - lessThan[nums[j]][k + 1]);
          int left = lessThan[nums[k]][j];

          answer += right * left;
        }
      }
    }
    return answer;
  }
};