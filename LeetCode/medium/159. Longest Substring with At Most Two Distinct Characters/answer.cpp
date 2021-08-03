#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use sliding window & hash map

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int length = s.length();
    int left = 0, right = 0;
    int answer = 0;
    unordered_map<char, int> counts;

    while (left < length) {
      counts[s[right]] += 1;

      if (right < length && counts.size() <= 2) {
        right += 1;

        answer = max(answer, right - left);
      } else {
        counts[s[right]] -= 1;
        if (counts[s[right]] == 0) counts.erase(s[right]);
        counts[s[left]] -= 1;
        if (counts[s[left]] == 0) counts.erase(s[left]);
        left += 1;
      }
    }

    return answer;
  }
};

// use sliding window

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int length = s.length();
    int left = 0, right = 0;
    int size = 0;
    int counts[256] = {
        0,
    };

    int answer = 0;

    while (left < length) {
      if (counts[s[right]] == 0) size += 1;
      counts[s[right]] += 1;

      if (right < length && size <= 2) {
        right += 1;

        answer = max(answer, right - left);
      } else {
        counts[s[right]] -= 1;
        if (counts[s[right]] == 0) size -= 1;
        counts[s[left]] -= 1;
        if (counts[s[left]] == 0) size -= 1;
        left += 1;
      }
    }

    return answer;
  }
};