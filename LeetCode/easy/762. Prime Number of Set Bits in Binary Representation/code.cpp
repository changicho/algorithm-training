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

// brute force
// time : O(N)
// space : O(1)
class Solution {
 private:
  bool isNotPrime[32] = {false};

  void init() {
    isNotPrime[0] = true;
    isNotPrime[1] = true;

    for (int i = 2; i < 32; i++) {
      if (isNotPrime[i]) continue;

      for (int j = i + i; j < 32; j += i) {
        isNotPrime[j] = true;
      }
    }
  }

 public:
  int countPrimeSetBits(int left, int right) {
    init();

    int answer = 0;
    for (int i = left; i <= right; i++) {
      int count = __builtin_popcount(i);

      if (!isNotPrime[count]) answer++;
    }
    return answer;
  }
};

// brute force
// time : O(N)
// space : O(1)
class Solution {
 private:
  bool check(int x) {
    return (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 ||
            x == 17 || x == 19);
  }

 public:
  int countPrimeSetBits(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
      int count = __builtin_popcount(i);

      if (check(count)) answer++;
    }
    return answer;
  }
};