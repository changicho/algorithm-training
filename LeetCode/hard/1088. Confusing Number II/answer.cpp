#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use DFS with backtracking
// time : O(5^(log_10(N)) * log_10(N))
// space : O(log_10(N))
class Solution {
 private:
  int answer = 0;

  unordered_map<int, int> um = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};

  bool isConfusingNumber(long n) {
    long src = n, res = 0;
    while (n > 0) {
      res = res * 10 + um[(int)n % 10];
      n /= 10;
    }
    return res != src;
  }

  void recursive(int n, long cur) {
    if (isConfusingNumber(cur)) {
      answer++;
    }
    for (auto &[key, val] : um) {
      if (cur * 10 + key == 0) continue;
      if (cur * 10 + key > n) continue;

      recursive(n, cur * 10 + key);
    }
  }

 public:
  int confusingNumberII(int N) {
    recursive(N, 0);

    return answer;
  }
};