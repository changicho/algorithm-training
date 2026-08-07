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

using ll = long long;

// brute force
// time : O(N * log_10(N))
// space : O(1)
class Solution {
 private:
  int convert(int num) {
    int ret = 1;
    while (num > 0 && ret > 0) {
      ret *= num % 10;
      num /= 10;
    }
    return ret;
  }

 public:
  int smallestNumber(int n, int t) {
    int num = n;
    while (true) {
      int c = convert(num);

      if (c % t == 0) break;

      num++;
    }
    return num;
  }
};