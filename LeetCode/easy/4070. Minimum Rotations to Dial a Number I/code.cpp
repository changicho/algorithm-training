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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minRotations(string s) {
    int answer = 0;

    int cur = 0;
    for (char& c : s) {
      int to = c - '0';

      int a = min(cur, to), b = max(cur, to);
      int count = min(abs(a - b), (10 - b) + a);
      answer += count;

      cur = to;
    }
    return answer;
  }
};