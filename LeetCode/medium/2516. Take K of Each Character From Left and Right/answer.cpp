#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use binary search
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 private:
  bool isPossible(int count[3], int k) {
    return count[0] >= k && count[1] >= k && count[2] >= k;
  }

  bool canMakeIt(string &s, int length, int k) {
    int count[3] = {0, 0, 0};
    for (int i = 0; i < length; i++) {
      count[s[i] - 'a']++;
    }
    if (isPossible(count, k)) return true;

    for (int i = 0; i < length; i++) {
      int rI = s.size() - 1 - i;

      count[s[(length - 1) - i] - 'a']--;
      count[s[rI] - 'a']++;

      if (isPossible(count, k)) return true;
    }
    return false;
  }

 public:
  int takeCharacters(string s, int k) {
    int length = s.size();
    int left = 0, right = length + 1;

    int answer = -1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (canMakeIt(s, mid, k)) {
        // pick left part
        answer = mid;
        right = mid;
      } else {
        // pick right part
        left = mid + 1;
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
  int takeCharacters(string s, int k) {
    int length = s.length();
    unordered_map<char, int> count;

    for (char &c : s) {
      count[c]++;
    }

    if (count['a'] < k || count['b'] < k || count['c'] < k) return -1;

    int answer = INT_MAX;
    for (int i = length - 1, j = length - 1; i >= 0; i--) {
      count[s[i]]--;
      while (count[s[i]] < k) {
        count[s[j]]++;
        j--;
      }
      answer = min(answer, i - 1 + length - j);
    }
    return answer;
  }
};