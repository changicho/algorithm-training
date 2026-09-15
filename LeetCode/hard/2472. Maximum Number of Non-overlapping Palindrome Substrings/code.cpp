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

// dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int maxPalindromes(string s, int k) {
    int size = s.size();

    vector<vector<bool>> isPalin(size, vector<bool>(size, false));
    for (int i = 0; i < size; i++) {
      isPalin[i][i] = true;
      if (i + 1 < size && s[i] == s[i + 1]) {
        isPalin[i][i + 1] = true;
      }
    }

    for (int l = 3; l <= size; l++) {
      for (int i = 0; i <= size - l; i++) {
        isPalin[i][i + l - 1] =
            isPalin[i + 1][i + l - 2] && (s[i] == s[i + l - 1]);
      }
    }

    vector<int> dp(size, 0);
    for (int i = 0; i < size; i++) {
      for (int before = i - 1; before >= -1; before--) {
        int beforeDp = before >= 0 ? dp[before] : 0;

        bool canAdd = (i - (before + 1) + 1) >= k && isPalin[before + 1][i];
        dp[i] = max(dp[i], beforeDp + canAdd);
      }
    }

    return dp[size - 1];
  }
};

// greedy
// time : O(NK)
// space : O(1)
class Solution {
 public:
  int maxPalindromes(string s, int k) {
    int size = s.size();
    int answer = 0;

    function<bool(int, int)> check = [&](int l, int r) {
      while (l < r) {
        if (s[l++] != s[r--]) {
          return false;
        }
      }
      return true;
    };

    int start = 0;
    for (int r = k - 1; r < size; ++r) {
      int l = r - k + 1;
      if (l >= start && check(l, r)) {
        answer++;
        start = r + 1;
        continue;
      }

      l = r - k;
      if (l >= start && check(l, r)) {
        answer++;
        start = r + 1;
      }
    }

    return answer;
  }
};