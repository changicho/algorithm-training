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

// use greedy
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int minimizeXor(int num1, int num2) {
    int count1 = __builtin_popcount(num1);
    int count2 = __builtin_popcount(num2);

    int diff = count2 - count1;

    int answer = 0;
    for (int i = 31; i >= 0; i--) {
      if (num1 & (1 << i) && count2 > 0) {
        answer |= (1 << i);
        count2--;
      }
    }
    for (int i = 0; i < 32 && diff > 0; i++) {
      if (answer & (1 << i)) continue;
      answer |= (1 << i);
      diff--;
    }

    return answer;
  }
};