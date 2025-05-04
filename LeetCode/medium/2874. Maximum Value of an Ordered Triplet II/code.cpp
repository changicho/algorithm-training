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

// use right max array
// time : O(N)
// space : O(N)
class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    int size = nums.size();
    vector<int> rightMaxs(size, 0);
    rightMaxs[size - 1] = nums[size - 1];

    for (int i = size - 2; i >= 0; i--) {
      rightMaxs[i] = max(rightMaxs[i + 1], nums[i]);
    }
    long long answer = 0;
    long long beforeMax = nums[0];
    for (int i = 1; i < size - 1; i++) {
      long long cur = beforeMax - nums[i];

      answer = max(answer, cur * rightMaxs[i + 1]);

      beforeMax = max(beforeMax, (long long)nums[i]);
    }
    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    int size = nums.size();
    long long answer = 0;

    long long maximum = 0, diffMax = 0;

    for (int k = 0; k < size; k++) {
      answer = max(answer, diffMax * nums[k]);

      diffMax = max(diffMax, maximum - nums[k]);
      maximum = max(maximum, (long long)nums[k]);
    }
    return answer;
  }
};