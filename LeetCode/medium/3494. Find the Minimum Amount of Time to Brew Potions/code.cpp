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

// use dynamic programming
// time : O(N * M)
// space : O(N)
class Solution {
 public:
  long long minTime(vector<int>& skill, vector<int>& mana) {
    int size = skill.size();
    int mSize = mana.size();
    vector<long long> endTimes(size, 0);

    endTimes[0] = mana[0] * skill[0];
    for (int i = 1; i < size; i++) {
      endTimes[i] = endTimes[i - 1] + skill[i] * mana[0];
    }

    for (int i = 1; i < mSize; i++) {
      endTimes[0] = endTimes[0] + skill[0] * mana[i];

      for (int j = 1; j < size; j++) {
        endTimes[j] = max(endTimes[j - 1], endTimes[j]) + skill[j] * mana[i];
      }

      // update real endTimes by last
      for (int j = size - 2; j >= 0; j--) {
        endTimes[j] = endTimes[j + 1] - skill[j + 1] * mana[i];
      }
    }

    return endTimes.back();
  }
};