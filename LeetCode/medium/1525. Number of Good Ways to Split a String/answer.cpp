#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use sliding window

class Solution {
 public:
  int numSplits(string s) {
    int answer = 0;
    // make 2 hash map. first (dp[0]), second (dp[length])
    unordered_map<char, int> first, second;
    // fill all char counting to second hash map
    for (char &c : s) {
      second[c] += 1;
    }

    // iterate all char c in string s
    for (char &c : s) {
      // 1. insert c to first (first[c] += 1)
      first[c] += 1;
      // 2. erase c in second (second[c] -= 1)
      second[c] -= 1;
      if (second[c] == 0) second.erase(c);

      // compare different letters of first, second
      if (first.size() == second.size()) {
        answer += 1;
      }
    }
    return answer;
  }
};