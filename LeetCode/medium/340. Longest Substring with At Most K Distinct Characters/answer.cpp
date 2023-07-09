#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int size = s.size();

    unordered_map<char, int> counts;

    int answer = 0;
    for (int left = 0, right = 0; right < size; right++) {
      counts[s[right]]++;

      while (left <= right && counts.size() > k) {
        char target = s[left];
        counts[target]--;
        left++;

        if (counts[target] == 0) {
          counts.erase(target);
        }
      }

      answer = max(answer, right - left + 1);
    }
    return answer;
  }
};

// use sliding window (not hash map)
// time : O(N)
// space : O(1)
class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int counts[256] = {
        0,
    };
    int notZeroCount = 0;

    int size = s.size();

    int answer = 0;
    for (int left = 0, right = 0; right < size; right++) {
      counts[s[right]]++;
      if (counts[s[right]] == 1) {
        notZeroCount++;
      }

      while (left <= right && notZeroCount > k) {
        char target = s[left];
        counts[target]--;
        left++;

        if (counts[target] == 0) {
          notZeroCount--;
        }
      }

      answer = max(answer, right - left + 1);
    }
    return answer;
  }
};