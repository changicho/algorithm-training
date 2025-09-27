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

// use linear scan
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    int answer = 0;
    for (int i = 0; i < size - 2; i++) {
      if (nums[i] == 0) continue;

      int k = i + 2;
      for (int j = i + 1; j < size - 1; j++) {
        while (k < size && nums[i] + nums[j] > nums[k]) {
          k++;
        }

        answer += (k - 1) - j;
      }
    }

    return answer;
  }
};

// use binary search
// time : O(N^2 * log_2(N))
// space : O(N)
class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    int answer = 0;
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        int right = nums[i] + nums[j];

        int k = lower_bound(nums.begin(), nums.end(), right) - nums.begin() - 1;

        // j+1 ~ k
        int count = k - (j + 1) + 1;
        if (count > 0) {
          answer += count;
        }
      }
    }

    return answer;
  }
};