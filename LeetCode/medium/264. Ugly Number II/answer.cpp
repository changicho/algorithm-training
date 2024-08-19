#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use heap
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int nthUglyNumber(int n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    unordered_set<long long> us;
    vector<long long> factors = {2, 3, 5};

    pq.push(1);
    us.insert(1);

    int answer = 0;
    while (n--) {
      int cur = pq.top();
      pq.pop();

      answer = cur;

      for (long long &f : factors) {
        long long next = cur * f;
        if (us.count(next)) continue;
        us.insert(next);
        pq.push(cur * f);
      }
    }
    return answer;
  }
};

// use greedy algorithm
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int nthUglyNumber(int n) {
    set<long long> s;

    s.insert(1);
    int count = 0;
    int answer = 0;

    while (!s.empty()) {
      long long cur = *s.begin();
      s.erase(cur);

      answer = cur;
      count += 1;
      if (count == n) break;

      s.insert(cur * 2);
      s.insert(cur * 3);
      s.insert(cur * 5);
    }

    return answer;
  }
};

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int nthUglyNumber(int n) {
    int twoIdx = 0, threeIdx = 0, fiveIdx = 0;  // pointers for 2, 3, 5
    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
      dp[i] = min({dp[twoIdx] * 2, dp[threeIdx] * 3, dp[fiveIdx] * 5});

      if (dp[i] == dp[twoIdx] * 2) twoIdx++;
      if (dp[i] == dp[threeIdx] * 3) threeIdx++;
      if (dp[i] == dp[fiveIdx] * 5) fiveIdx++;
    }

    return dp.back();
  }
};
