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

// hash map
// time : O(N)
// space : O(N)
class Solution {
 private:
  int reverse(int num) {
    int ret = 0;
    while (num > 0) {
      ret = ret * 10 + num % 10;
      num /= 10;
    }
    return ret;
  }

 public:
  int minMirrorPairDistance(vector<int>& nums) {
    int size = nums.size();

    unordered_map<int, int> befores;

    int answer = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
      int cur = nums[i];
      int r = reverse(cur);

      if (befores.count(cur)) {
        int diff = i - befores[cur];
        answer = min(answer, diff);
      }

      befores[r] = i;
    }

    if (answer == INT_MAX) return -1;

    return answer;
  }
};