#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O((N + M) * log_2(N))
// space : O(N + M)
class Solution {
 public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size(), m = queries.size();

    sort(nums.begin(), nums.end());

    vector<int> subArr(n + 1, 0);
    for (int i = 0; i < n; i++) {
      subArr[i + 1] = subArr[i] + nums[i];
    }

    vector<int> answer(m);

    for (int i = 0; i < m; i++) {
      int target = queries[i];

      int idx = 0;
      int left = 0, right = subArr.size();
      while (left < right) {
        int mid = left + (right - left) / 2;

        if (subArr[mid] <= target) {
          // pick right
          idx = mid;
          left = mid + 1;
        } else {
          // pick left
          right = mid;
        }
      }

      answer[i] = idx;
    }

    return answer;
  }
};

// use binary search (STL)
// time : O((N + M) * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size(), m = queries.size();

    sort(nums.begin(), nums.end());
    vector<int> subArr(n + 1, 0);
    for (int i = 0; i < n; i++) {
      subArr[i + 1] = subArr[i] + nums[i];
    }

    vector<int> answer(m);
    for (int i = 0; i < m; i++) {
      int idx = upper_bound(subArr.begin(), subArr.end(), queries[i]) -
                subArr.begin() - 1;

      answer[i] = idx;
    }

    return answer;
  }
};