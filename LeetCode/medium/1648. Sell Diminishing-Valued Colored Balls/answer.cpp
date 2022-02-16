#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & greedy

class Solution {
 private:
  const long MOD = 1e9 + 7;

  long sumZeroToN(long n) { return n * (n + 1) / 2; }

 public:
  int maxProfit(vector<int>& inventory, int orders) {
    int size = inventory.size();
    // O(N * log_2(N))
    sort(begin(inventory), end(inventory), greater<int>());
    inventory.push_back(0);  // push end value

    long answer = 0, colors = 1;

    // O(N)
    for (int i = 0; i < size && orders > 0; i++, colors++) {
      long cur = inventory[i];
      long next = inventory[i + 1];

      bool isLast = (orders / colors) < (cur - next);
      long count = isLast ? (orders / colors) : (cur - next);

      orders -= count * colors;

      long rightPart = sumZeroToN(cur);
      long leftPart = sumZeroToN(cur - count);

      answer += (rightPart - leftPart) * colors;
      answer %= MOD;

      if (isLast) {
        answer += orders * (cur - count);
        answer %= MOD;
        break;
      }
    }
    return answer;
  }
};