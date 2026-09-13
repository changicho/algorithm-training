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

// brute force & prefix
// time : O(N^2 * log_2(M))
// space : O(N)
class Solution {
 public:
  int maxValidSplits(vector<int>& nums) {
    int size = nums.size();
    int answer = 0;

    for (int target = -1; target < size; target++) {
      vector<int> arr;
      for (int i = 0; i < size; i++) {
        if (i == target) continue;
        arr.push_back(nums[i]);
      }

      int aSize = arr.size();
      vector<int> prefix(aSize);
      vector<int> suffix(aSize);

      prefix[0] = arr[0];
      suffix[aSize - 1] = arr[aSize - 1];

      for (int i = 1; i < aSize; i++) {
        prefix[i] = gcd(arr[i], prefix[i - 1]);
        suffix[aSize - 1 - i] =
            gcd(arr[aSize - 1 - i], suffix[aSize - 1 - i + 1]);
      }

      int score = 0;
      for (int i = 0; i < aSize - 1; i++) {
        if (prefix[i] == suffix[i + 1]) score++;
      }

      answer = max(score, answer);
    }
    return answer;
  }
};