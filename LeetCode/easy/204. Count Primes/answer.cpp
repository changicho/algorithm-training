#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sieve of eratosthenes

class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> isNotPrime(n + 1, false);
    isNotPrime[0] = isNotPrime[1] = true;

    for (int cur = 2; cur <= sqrt(n); cur++) {
      if (isNotPrime[cur]) continue;

      for (int next = cur * cur; next <= n; next += cur) {
        isNotPrime[next] = true;
      }
    }

    int answer = 0;
    for (int number = 0; number < n; number++) {
      if (isNotPrime[number] == false) answer += 1;
    }

    return answer;
  }
};