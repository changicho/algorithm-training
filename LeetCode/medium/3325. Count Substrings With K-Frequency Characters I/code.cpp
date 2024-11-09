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

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int numberOfSubstrings(string s, int k) {
    int size = s.size();
    int answer = 0;
    for (int i = 0; i < size; i++) {
      int counts[26] = {
          0,
      };
      bool isFine = false;
      for (int j = i; j < size; j++) {
        counts[s[j] - 'a']++;

        if (counts[s[j] - 'a'] >= k) isFine = true;

        if (isFine) answer++;
      }
    }

    return answer;
  }
};

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numberOfSubstrings(string s, int k) {
    int size = s.size();
    int answer = size * (size + 1) / 2;

    int counts[26] = {
        0,
    };

    for (int left = 0, right = 0; right < size; right++) {
      counts[s[right] - 'a']++;

      while (counts[s[right] - 'a'] >= k) {
        counts[s[left] - 'a']--;
        left++;
      }

      answer -= (right - left) + 1;
    }

    return answer;
  }
};