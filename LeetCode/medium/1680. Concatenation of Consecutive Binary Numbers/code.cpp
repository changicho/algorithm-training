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

// use binary convert
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int concatenatedBinary(int n) {
    const int MOD = 1e9 + 7;

    int answer = 0;
    int digit = 1;

    for (int i = n; i >= 1; i--) {
      int num = i;
      while (num > 0) {
        if ((num % 2) == 1) {
          answer += digit;
          answer %= MOD;
        }

        num /= 2;
        digit *= 2;
        digit %= MOD;
      }
    }

    return answer;
  }
};
