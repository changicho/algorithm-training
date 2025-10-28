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

// use brute force
// time : O(M * log_10(M))
// space : O(N)
class Solution {
 private:
  bool check(int num) {
    int count[10] = {
        0,
    };
    while (num > 0) {
      count[num % 10]++;
      num /= 10;
    }

    if (count[0] > 0) return false;
    for (int i = 1; i <= 9; i++) {
      if (count[i] == 0) continue;
      if (count[i] != i) return false;
    }
    return true;
  }

 public:
  int nextBeautifulNumber(int n) {
    for (int i = n + 1; i <= 1e7; i++) {
      if (check(i)) return i;
    }
    return -1;
  }
};