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

// use prefix sum
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    const int MOD = 1e9 + 7;

    int count = 0, prefixSum = 0;
    int oddCount = 0, evenCount = 1;

    for (int num : arr) {
      prefixSum += num;

      if (prefixSum % 2 == 0) {
        count += oddCount;
        evenCount++;
      } else {
        count += evenCount;
        oddCount++;
      }

      count %= MOD;
    }

    return count;
  }
};