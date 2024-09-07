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

// use mod
// time : O(N + M)
// space : O(N)
class Solution {
 public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int size = m + n;

    int diff = size * mean - accumulate(rolls.begin(), rolls.end(), 0);

    // invalid diff check
    if (diff > 6 * n || n > diff) return {};

    int q = diff / n, r = diff % n;

    vector<int> answer(n, q);
    for (int i = 0; i < r; i++) {
      answer[i]++;
    }
    return answer;
  }
};
