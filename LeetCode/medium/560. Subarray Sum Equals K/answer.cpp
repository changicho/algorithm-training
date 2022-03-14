#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use prefix sum (TLE)
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
    int size = nums.size();
    vector<int> prefixSums(size + 1,
                           0);  // prefixSums[index + 1], 0 ~ index sum
    for (int i = 0; i < size; i++) {
      prefixSums[i + 1] = prefixSums[i] + nums[i];
    }

    int answer = 0;

    for (int left = 0; left < size; left++) {
      for (int right = left; right < size; right++) {
        int curSum = prefixSums[right + 1] - prefixSums[left];

        if (curSum == k) {
          answer++;
        }
      }
    }

    return answer;
  }
};

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    m[0] = 1;

    int answer = 0;
    int sum = 0;

    for (int &num : nums) {
      sum += num;
      if (m.count(sum - k)) {
        answer += m[sum - k];
      }
      m[sum] += 1;
    }

    return answer;
  }
};