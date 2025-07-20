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

// use two pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int specialTriplets(vector<int> &nums) {
    int MOD = 1e9 + 7;

    int size = nums.size();

    unordered_map<int, int> rightCount;
    unordered_map<int, int> leftCount;
    for (int &num : nums) {
      rightCount[num]++;
    }
    int answer = 0;
    for (int &num : nums) {
      rightCount[num]--;

      int target = num * 2;

      if (leftCount.count(target) != 0 && rightCount.count(target) != 0) {
        long long cur = 1;
        cur *= leftCount[target];
        cur %= MOD;
        cur *= rightCount[target];
        cur %= MOD;

        answer += cur;
        answer %= MOD;
      }

      leftCount[num]++;
    }
    return answer;
  }
};