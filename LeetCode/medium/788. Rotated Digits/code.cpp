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
// time : O(N * log_10(N))
// space : O(1)
class Solution {
 private:
  int moveTo[10] = {
      0,
  };

  int rotate(int num) {
    int ret = 0;
    for (int d = 1; d <= num; d *= 10) {
      int cur = num % (d * 10) / d;
      if (moveTo[cur] == -1) return -1;

      ret += moveTo[cur] * d;
    }
    return ret;
  }

 public:
  int rotatedDigits(int n) {
    for (int i = 0; i <= 9; i++) {
      moveTo[i] = -1;
    }
    moveTo[0] = 0;
    moveTo[1] = 1;
    moveTo[2] = 5;
    moveTo[5] = 2;
    moveTo[6] = 9;
    moveTo[8] = 8;
    moveTo[9] = 6;

    int answer = 0;
    for (int i = 1; i <= n; i++) {
      int converted = rotate(i);

      if (converted == -1) continue;
      if (converted != i) {
        answer++;
      }
    }
    return answer;
  }
};