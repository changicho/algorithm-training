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

// use sieve of eratosthenes
// time : O(N * log_2(log_2(N)))
// space : O(N)
class Solution {
 public:
  vector<int> closestPrimes(int left, int right) {
    bool isNotPrime[1000001] = {
        false,
    };
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i * i <= right; i++) {
      if (!isNotPrime[i]) {
        for (int next = i * i; next <= right; next += i) {
          isNotPrime[next] = true;
        }
      }
    }

    vector<int> primes;
    for (int num = left; num <= right; num++) {
      if (!isNotPrime[num]) {
        primes.push_back(num);
      }
    }

    int diff = INT_MAX;
    vector<int> answer = {-1, -1};

    for (int i = 1; i < primes.size(); i++) {
      int curDiff = primes[i] - primes[i - 1];

      if (curDiff < diff) {
        diff = curDiff;
        answer[0] = primes[i - 1];
        answer[1] = primes[i];
      }
    }

    return answer;
  }
};