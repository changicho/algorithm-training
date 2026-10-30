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

// bit count
// time : O(1)
// space : O(1)
class Solution {
 public:
  int calculateScore(int a, int b) {
    int d1 = __builtin_popcount(a);
    int d2 = __builtin_popcount(b);
    if (d1 >= d2) return d1 * d2;
    return d2 / d1;
  }
};
