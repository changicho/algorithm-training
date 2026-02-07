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

// in place
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> constructTransformedArray(vector<int>& nums) {
    int size = nums.size();

    for (int i = 0; i < size; i++) {
      nums[i] += 100;
    }

    for (int i = 0; i < size; i++) {
      int cur = nums[i] % 1000;

      int next = (i + (cur - 100) % size + size) % size;
      nums[i] += (nums[next] % 1000) * 1000;
    }

    for (int i = 0; i < size; i++) {
      nums[i] /= 1000;
      nums[i] -= 100;
    }
    return nums;
  }
};

// one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> constructTransformedArray(vector<int>& nums) {
    int size = nums.size();

    vector<int> answer(size);

    for (int i = 0; i < size; i++) {
      int cur = nums[i];

      int next = (i + cur % size + size) % size;
      answer[i] = nums[next];
    }
    return answer;
  }
};