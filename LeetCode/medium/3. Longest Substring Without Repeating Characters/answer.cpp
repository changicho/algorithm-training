#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use sliding window with hash set
// time : O(N)
// space : O(M)
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int length = s.length();
    // O(M)
    unordered_set<char> hashSet;

    int answer = 0;
    // O(N)
    for (int left = 0, right = 0; right < length; right++) {
      char c = s[right];
      // total : O(N)
      while (left < right && hashSet.find(c) != hashSet.end()) {
        hashSet.erase(s[left]);
        left++;
      }

      hashSet.insert(c);
      int length = right - left + 1;
      answer = max(length, answer);
    }

    return answer;
  }
};

// use sliding window with char array
// time : O(N)
// space : O(M)
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int length = s.length();
    int answer = 0;
    int tempLength = 0;
    // english letters, digits, symbols and spaces
    // O(M)
    bool visited[256] = {
        false,
    };

    // O(N)
    for (int left = 0, right = 0; right < length; right++) {
      char c = s[right];
      // total O(N)
      while (left < right && visited[c]) {
        char target = s[left];
        left += 1;

        if (visited[target]) tempLength--;
        visited[target] = false;
      }

      visited[c] = true;
      tempLength++;
      answer = max(answer, tempLength);
    }

    return answer;
  }
};

// use sliding window with end index
// time : O(N)
// space : O(M)
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int length = s.length();
    unordered_map<char, int> lastApearIdx;

    int answer = 0;
    for (int left = 0, right = 0; right < length; right++) {
      char c = s[right];

      if (lastApearIdx.count(c) > 0) {
        left = max(left, lastApearIdx[c] + 1);
      }
      // update lastIdx of cur
      lastApearIdx[c] = right;
      answer = max(answer, right - left + 1);
    }

    return answer;
  }
};

// use sliding window with end index (array)
// time : O(N)
// space : O(M)
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int length = s.length();
    int lastApearIdx[128] = {
        0,
    };

    int answer = 0;
    for (int left = 0, right = 0; right < length; right++) {
      char c = s[right];

      if (lastApearIdx[c] != 0) {
        left = max(left, lastApearIdx[c]);
      }
      lastApearIdx[c] = right + 1;

      answer = max(answer, right - left + 1);
    }

    return answer;
  }
};