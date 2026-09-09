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
// time : O(N)
// space : O(1)
class Solution {
 public:
  int countCommas(int n) {
    int answer = 0;
    for (int num = 1; num <= n; ++num) {
      if (num >= 1000) {
        answer++;
      }
    }
    return answer;
  }
};

// math
// time : O(1)
// space : O(1)
class Solution {
 public:
  int countCommas(int n) { return max(0, n - 1000 + 1); }
};