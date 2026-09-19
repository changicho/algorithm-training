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

vector<long long> targets[2];

void dfs(long long num, int length) {
  if (length >= 10) return;

  int digit = (num > 0 ? log10(num) : 0) + 1;
  if (digit == length) {
    targets[num % 2].push_back(num);
  }

  for (int i = 0; i <= 9; i++) {
    long long next = i * pow(10, length + 1) + num * 10 + i;
    dfs(next, length + 2);
  }
};

int init = []() {
  dfs(0, 0);
  for (int i = 0; i <= 9; i++) {
    dfs(i, 1);
  }

  sort(targets[0].begin(), targets[0].end());
  sort(targets[1].begin(), targets[1].end());
  return 0;
}();

// binary search & DFS
// time : O(M * log_2(M) + N * log_2(M))
// space : O(M)
class Solution {
 public:
  long long minOperations(vector<int>& nums) {
    int size = nums.size();
    long long answer = 0;

    for (int& num : nums) {
      int d = num % 2;
      int upperI = upper_bound(targets[d].begin(), targets[d].end(), num) -
                   targets[d].begin();

      long long lower = targets[d][upperI - 1];
      long long upper = targets[d][upperI];

      long long diff = min(abs(lower - num) / 2, abs(upper - num) / 2);
      answer += diff;
    }

    return answer;
  }
};