#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set
// time : O(N)
// space : O(N)
class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    int answer = -1;

    unordered_set<long> s;

    for (int& num : nums) {
      s.insert(num);
    }

    for (int num : s) {
      long sq = num;
      int length = 1;
      while (s.count(sq * sq) > 0) {
        sq *= sq;
        length++;
      }

      if (length > 1) {
        answer = max(answer, length);
      }
    }

    return answer;
  }
};