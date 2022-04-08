#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy
// time : O(L^2)
// space : O(L)
class Solution {
 public:
  int minMovesToMakePalindrome(string s) {
    int moves = 0;

    while (!s.empty()) {
      int index = s.find(s.back());
      // move to center
      if (index == s.size() - 1) {
        moves += index / 2;
      } else {
        moves += index;
        s.erase(index, 1);
      }

      s.pop_back();
    }

    return moves;
  }
};