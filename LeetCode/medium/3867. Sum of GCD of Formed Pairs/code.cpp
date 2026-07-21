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

// sort & gcd
// time : O(N * log_2(N) + N * log_2(M))
// space : O(N)
class Solution {
 public:
  long long gcdSum(vector<int>& nums) {
    int minimum = INT_MAX, maximum = INT_MIN;

    int curMax = nums[0];

    vector<int> gcds;
    for (int& num : nums) {
      curMax = max(curMax, num);
      int curGcd = gcd(curMax, num);

      gcds.push_back(curGcd);
    }

    sort(gcds.begin(), gcds.end());

    int size = gcds.size();

    long long answer = 0;
    for (int i = 0; i < size / 2; i++) {
      answer += gcd(gcds[i], gcds[size - 1 - i]);
    }
    return answer;
    ;
  }
};