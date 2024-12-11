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

// use hash set
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_set<int> us(banned.begin(), banned.end());
    int sum = 0;
    int answer = 0;

    for (int num = 1; num <= n; num++) {
      if (us.count(num)) continue;
      if (sum + num > maxSum) break;
      sum += num;
      answer++;
    }

    return answer;
  }
};