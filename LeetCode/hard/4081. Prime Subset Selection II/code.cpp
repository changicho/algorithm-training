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

// sieve of eratosthenes & knapsack
// time : O(N * log_2(log_2(N)) + SP)
// space : O(P * (N + S))
class Solution {
 private:
  vector<int> primes;

  void init(int n) {
    vector<bool> isNotPrime(n + 1);

    for (int i = 2; i <= n; i++) {
      if (isNotPrime[i]) continue;
      primes.push_back(i);

      for (int j = i * i; j <= n; j += i) {
        isNotPrime[j] = true;
      }
    }
  }

  int dp[1001][1001] = {
      0,
  };

  int calc(int i, int sum) {
    if (sum == 0) return 0;
    if (i >= primes.size() || sum < 0) return INT_MAX;
    if (dp[i][sum] != -1) return dp[i][sum];

    // not choose
    int& ret = dp[i][sum];
    ret = calc(i + 1, sum);
    if (primes[i] <= sum) {
      // choose
      int take = calc(i + 1, sum - primes[i]);

      if (take != INT_MAX) {
        ret = min(ret, take + 1);
      }
    }
    return ret;
  }

  void build(int i, int sum, vector<int>& arr) {
    if (sum == 0 || i >= primes.size()) return;

    int need = calc(i, sum);

    if (primes[i] <= sum) {
      // choose
      int take = calc(i + 1, sum - primes[i]);

      if (take != INT_MAX && take + 1 == need) {
        arr.push_back(primes[i]);
        build(i + 1, sum - primes[i], arr);
        return;
      }
    }
    // not choose
    build(i + 1, sum, arr);
  }

 public:
  vector<int> maxPrimeSubset(int n, int s) {
    // prime
    init(n);

    memset(dp, -1, sizeof(dp));

    for (int sum = s; sum >= 0; sum--) {
      int cur = calc(0, sum);
      if (cur == INT_MAX) {
        continue;
      }

      vector<int> answer;
      build(0, sum, answer);

      return answer;
    }
    return {};
  }
};