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

// sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> answer;

    for (int i = 0; i < size; i++) {
      if (nums[i] == target) {
        answer.push_back(i);
      }
    }
    return answer;
  }
};

// count
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    int size = nums.size();

    int count[101] = {
        0,
    };
    for (int& num : nums) {
      count[num]++;
    }
    vector<int> answer;

    int lowerCount = 0;
    for (int i = 0; i <= target; i++) {
      if (i < target) {
        lowerCount += count[i];
        continue;
      }

      for (int j = 0; j < count[target]; j++) {
        answer.push_back(lowerCount + j);
      }
    }
    return answer;
  }
};

// count
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    int size = nums.size();

    int lowerCount = 0;
    int sameCount = 0;
    for (int& num : nums) {
      if (num < target) {
        lowerCount++;
      } else if (num == target) {
        sameCount++;
      }
    }

    vector<int> answer;
    for (int i = 0; i < sameCount; i++) {
      answer.push_back(lowerCount + i);
    }

    return answer;
  }
};