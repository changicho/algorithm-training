#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(1)
class Solution {
 private:
  bool isPossible(int counts[26], int k) {
    for (int i = 0; i < 26; i++) {
      if (counts[i] == 0) continue;
      if (counts[i] < k) return false;
    }
    return true;
  }

 public:
  int longestSubstring(string s, int k) {
    int length = s.length();

    int maximum = 0;
    for (int start = 0; start < length; start++) {
      int counts[26] = {
          0,
      };

      for (int i = start; i < length; i++) {
        counts[s[i] - 'a']++;

        if (isPossible(counts, k)) {
          maximum = max(maximum, i - start + 1);
        }
      }
    }

    return maximum;
  }
};

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  int longestSubstring(string s, int k) {
    int length = s.length();

    int maximum = 0;
    for (int target = 1; target <= 26; target++) {
      unordered_map<char, int> counts;

      int left = 0, right = 0;
      int leastK = 0;
      while (right < length) {
        if (counts.size() <= target) {
          // expand the sliding window
          counts[s[right]]++;
          if (counts[s[right]] == k) leastK++;

          right++;
        } else {
          // shrink the sliding window
          if (counts[s[left]] == k) leastK--;

          counts[s[left]]--;
          if (counts[s[left]] == 0) counts.erase(s[left]);

          left++;
        }

        // update answer
        if (counts.size() == target && counts.size() == leastK) {
          maximum = max(right - left, maximum);
        }
      }
    }

    return maximum;
  }
};

// use divide and conquer
// time : O(N) (worst case)
// space : O(N)
class Solution {
 public:
  int longestSubstring(string s, int k) {
    int n = s.size();
    return longestSubstringUtil(s, 0, n, k);
  }
  int longestSubstringUtil(string &s, int start, int end, int k) {
    if (end < k) return 0;
    int countMap[26] = {0};
    // update the countMap with the count of each character
    for (int i = start; i < end; i++) countMap[s[i] - 'a']++;
    for (int mid = start; mid < end; mid++) {
      if (countMap[s[mid] - 'a'] >= k) continue;
      int midNext = mid + 1;
      while (midNext < end && countMap[s[midNext] - 'a'] < k) midNext++;
      return max(longestSubstringUtil(s, start, mid, k),
                 longestSubstringUtil(s, midNext, end, k));
    }
    return (end - start);
  }
};