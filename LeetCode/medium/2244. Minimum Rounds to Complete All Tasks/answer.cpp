#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map & math & mod
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minimumRounds(vector<int> &tasks) {
    unordered_map<int, int> counts;
    for (int &task : tasks) {
      counts[task]++;
    }

    int round = 0;
    for (auto &[key, val] : counts) {
      if (val == 1) return -1;
      // round += val / 3;
      // if (val % 3 != 0) round++;
      round += (val + 2) / 3;
    }
    return round;
  }
};