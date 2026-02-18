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

// brute force
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> answer;

    for (int h = 0; h < 12; ++h) {
      for (int m = 0; m < 60; ++m) {
        if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
          string cur = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
          answer.push_back(cur);
        }
      }
    }

    return answer;
  }
};