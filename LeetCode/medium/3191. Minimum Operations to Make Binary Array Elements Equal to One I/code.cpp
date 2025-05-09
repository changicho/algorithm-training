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

// use one pass & greedy
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int size = nums.size();
    int answer = 0;
    for (int i = 0; i < size - 2; i++) {
      if (nums[i] == 0) {
        answer++;
        for (int j = 0; j < 3; j++) {
          nums[i + j] = !nums[i + j];
        }
      }
    }

    if (nums[size - 1] == 0 || nums[size - 2] == 0) return -1;
    return answer;
  }
};