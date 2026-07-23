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

// greedy one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxActiveSectionsAfterTrade(string s) {
    int count = 0;
    int prev = 0;
    int total = 0;

    int answer = 0;
    for (char& c : s) {
      int cur = c - '0';

      if (cur == 0) {
        count++;
      } else {
        total++;
        if (count > 0) {
          prev = count;
        }
        count = 0;
      }

      if (prev > 0 && count > 0) {
        answer = max(answer, prev + count);
      }
    }

    return answer + total;
  }
};