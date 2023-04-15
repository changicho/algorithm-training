#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int findTheLongestBalancedSubstring(string s) {
    int ones = 0, zeros = 0;

    int answer = 0;
    for (char c : s) {
      if (c == '0') {
        if (ones > 0) {
          ones = 0;
          zeros = 0;
        }
        zeros++;
      } else {
        ones++;

        answer = max(answer, min(zeros, ones) * 2);
      }
    }

    return answer;
  }
};