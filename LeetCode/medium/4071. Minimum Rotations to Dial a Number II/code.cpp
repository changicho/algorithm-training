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

// greedy
// time : O(N)
// space : O(1)
class Solution {
 private:
  int getCount(char a, char b) {
    int aa = min(a, b) - '0', bb = max(a, b) - '0';

    return min(bb - aa, aa + 10 - bb);
  }

 public:
  int minRotations(int n, string s) {
    int diff = INT_MAX;
    int answer = 0;

    for (int i = n - 1; i >= 0; i--) {
      char before = i == 0 ? '0' : s[i - 1];
      int beforeDiff = getCount(s[i], before);
      int curDiff = getCount(s[n - 1], before) - beforeDiff;

      answer += beforeDiff;
      if (curDiff < diff) {
        diff = curDiff;
      }
    }

    return answer + diff;
  }
};