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

using ll = long long;

// one pass
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  int largestInteger(vector<int>& nums, int k) {
    int size = nums.size();
    int maximum = nums[0];
    int count[51] = {0};
    for (int& num : nums) {
      count[num]++;
      maximum = max(maximum, num);
    }

    if (k == size) {
      return maximum;
    }
    if (k == 1) {
      for (int num = 50; num >= 0; num--) {
        if (count[num] == 1) {
          return num;
        }
      }
      return -1;
    }
    int answer = -1;
    if (count[nums[0]] == 1) {
      answer = max(answer, nums[0]);
    }
    if (count[nums.back()] == 1) {
      answer = max(answer, nums.back());
    }
    return answer;
  }
};

// brute force
// time : O(N * K + M)
// space : O(K)
class Solution {
 public:
  int largestInteger(vector<int>& nums, int k) {
    int count[51] = {
        0,
    };

    int size = nums.size();

    for (int i = 0; i <= size - k; i++) {
      unordered_set<int> us;
      for (int j = 0; j < k; j++) {
        us.insert(nums[i + j]);
      }
      for (int num : us) {
        count[num]++;
      }
    }

    int answer = -1;
    for (int num = 0; num <= 50; num++) {
      if (count[num] == 1) {
        answer = max(answer, num);
      }
    }
    return answer;
  }
};