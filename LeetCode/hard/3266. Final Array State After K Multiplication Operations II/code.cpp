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

// use greedy & min heap
// time : O(N * log_2(K))
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

  struct Number {
    long long val;
    int index;

    bool operator<(const Number& b) const {
      if (val == b.val) return index > b.index;
      return val > b.val;
    }
  };

  int powMod(long long num, int exp, int mod) {
    long long res = 1;
    for (long long base = num; exp > 0; exp /= 2) {
      if (exp % 2 == 1) {
        res = (res * base) % mod;
      }

      base = (base * base) % mod;
    }

    return res;
  }

 public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    int size = nums.size();

    if (multiplier == 1) return nums;

    priority_queue<Number> pq;

    unordered_set<int> visited;
    for (int i = 0; i < size; i++) {
      pq.push({nums[i], i});
    }

    while (k-- && visited.size() < size) {
      auto [num, index] = pq.top();

      pq.pop();
      pq.push({num * multiplier, index});
      visited.insert(index);
    }

    int quotient = k / size, remainder = k % size;

    vector<int> answer(size);
    while (!pq.empty()) {
      auto [num, index] = pq.top();
      pq.pop();

      answer[index] =
          ((num % MOD) *
           powMod(multiplier, quotient + (remainder >= 0 ? 1 : 0), MOD)) %
          MOD;
      remainder--;
    }

    return answer;
  }
};