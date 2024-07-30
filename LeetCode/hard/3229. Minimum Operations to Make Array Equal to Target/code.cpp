#include <algorithm>
#include <cmath>
#include <functional>
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

// use greedy
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long minimumOperations(vector<int>& nums, vector<int>& target) {
    int size = nums.size();
    long long increment = 0, decrement = 0;

    long long answer = 0;
    for (int i = 0; i < size; i++) {
      long long diff = target[i] - nums[i];

      if (diff > 0) {
        if (increment < diff) {
          answer += diff - increment;
        }

        increment = diff;
        decrement = 0;
      } else if (diff < 0) {
        if (diff < decrement) {
          answer += decrement - diff;
        }

        decrement = diff;
        increment = 0;
      } else {
        increment = 0;
        decrement = 0;
      }
    }

    return answer;
  }
};