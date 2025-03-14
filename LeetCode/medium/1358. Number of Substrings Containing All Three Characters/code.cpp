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

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numberOfSubstrings(string s) {
    int size = s.size();

    int count[3] = {
        0,
    };

    function<bool()> check = [&]() {
      return count[0] > 0 && count[1] > 0 && count[2] > 0;
    };

    int answer = 0;
    for (int left = 0, right = 0; right < size; right++) {
      char c = s[right];
      count[c - 'a']++;

      while (check()) {
        answer += size - right;

        char leftChar = s[left];
        count[leftChar - 'a']--;
        left++;
      }
    }

    return answer;
  }
};