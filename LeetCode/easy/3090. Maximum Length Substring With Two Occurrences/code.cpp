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

// sling window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maximumLengthSubstring(string s) {
    int size = s.size();

    int count[26] = {
        0,
    };

    int answer = 0;
    for (int left = 0, right = 0; right < size; right++) {
      count[s[right] - 'a']++;

      while (count[s[right] - 'a'] > 2 && left < right) {
        count[s[left] - 'a']--;
        left++;
      }

      answer = max(answer, right - left + 1);
    }
    return answer;
  }
};