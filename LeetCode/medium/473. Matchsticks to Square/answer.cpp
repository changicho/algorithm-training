#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use backtracking dfs
// time : O(4^N)
// space : O(4^N)
class Solution {
 private:
  bool answer = false;
  unordered_set<string> visited;

  string convert(vector<int> cur) {
    sort(cur.begin(), cur.end());
    string ret = "";
    for (int &c : cur) {
      ret += to_string(c) + '/';
    }
    return ret;
  }

  void recursive(int index, vector<int> matches, int length, vector<int> cur) {
    if (answer) return;
    string key = convert(cur);
    if (visited.count(key) > 0) return;
    visited.insert(key);

    int size = matches.size();
    if (index == size) {
      answer = true;
      return;
    }

    for (int i = 0; i < 4; i++) {
      cur[i] += matches[index];
      if (cur[i] <= length) {
        recursive(index + 1, matches, length, cur);
      }
      cur[i] -= matches[index];
    }
  }

 public:
  bool makesquare(vector<int> &matchsticks) {
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

    if (sum % 4 != 0) return false;
    int length = sum / 4;

    for (int &m : matchsticks) {
      if (m > length) return false;
    }

    sort(matchsticks.begin(), matchsticks.end(), greater<int>());

    vector<int> cur(4, 0);
    recursive(0, matchsticks, length, cur);

    return answer;
  }
};

// use bitmask
// time : O(2^N)
// space : O(2^N)
class Solution {
 public:
  bool makesquare(vector<int> &nums) {
    int size = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0l);
    if (sum % 4) return false;

    int allOnBits = (1 << size) - 1;
    int length = sum / 4;

    vector<int> sideCombinations, doubleSideCombinations(1 << size, false);
    for (int i = 0; i <= allOnBits; i++) {
      int sideSum = 0;
      for (int j = 0; j <= 15; j++) {
        if (i >> j & 1) sideSum += nums[j];
      }

      if (sideSum == length) {
        for (int k : sideCombinations) {
          if ((k & i) == 0) {
            int t = k | i;
            doubleSideCombinations[t] = true;
            if (doubleSideCombinations[allOnBits ^ t]) return true;
          }
        }
        sideCombinations.push_back(i);
      }
    }
    return false;
  }
};