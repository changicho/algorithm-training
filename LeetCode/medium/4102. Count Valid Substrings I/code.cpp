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

using ll = long long;

// sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long countValidSubstrings(string s) {
    int size = s.size();
    long long answer = 0;

    for (int left = 0, right = 0; right < size; right++) {
      if (right >= 2) {
        if (s[right] == 'c' && s[right - 1] == 'b' && s[right - 2] == 'a') {
          left = right - 1;
        }
      }

      answer += right - left + 1;
    }
    return answer;
  }
};