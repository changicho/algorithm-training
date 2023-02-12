#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use custom pow
// time : O(log_2(N))
// space : O(log_2(N))
class Solution {
 private:
  long long MOD = 1e9 + 7;

  long long myPow(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;

    long long ret = 1;
    if (n % 2 == 1) {
      ret *= 2;
      ret %= MOD;
    }
    int temp = myPow(n / 2);
    ret *= temp;
    ret %= MOD;
    ret *= temp;
    ret %= MOD;
    return ret;
  }

 public:
  int monkeyMove(int n) {
    int answer = myPow(n);

    answer -= 2;
    if (answer < 0) answer += MOD;

    return answer;
  }
};