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

// sieve of eratosthenes
// time : O(N * log_2(log_2(N)))
// space : O(N)
class Solution {
 public:
  vector<int> maxPrimes(int n, int s) {
    bool isNotPrime[1000001] = {
        false,
    };
    isNotPrime[1] = true;
    for (int i = 2; i * i <= n; i++) {
      for (int j = i * i; j <= n; j += i) {
        isNotPrime[j] = true;
      }
    }

    vector<int> answer;
    long long sum = 0;
    for (int p = 2; p <= n; p++) {
      if (isNotPrime[p]) continue;

      if (sum + p > s) break;
      answer.push_back(p);
      sum += p;
    }

    return answer;
  }
};