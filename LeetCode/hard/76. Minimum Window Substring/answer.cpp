#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use sliding window

class Solution {
 public:
  string minWindow(string s, string t) {
    int length = s.length();
    if (t.length() > length) return "";
    int left = 0, right = 0;
    int answerLeft = 0, answerRight = length - 1;

    unordered_map<char, int> needs;
    for (char &c : t) {
      needs[c]++;
    }
    int remainCount = t.length();

    bool findAnswer = false;

    while (right < length) {
      if (needs[s[right]] > 0) remainCount--;
      needs[s[right]]--;

      while (left <= right && remainCount == 0) {
        if (answerRight - answerLeft + 1 >= right - left + 1) {
          findAnswer = true;
          answerLeft = left;
          answerRight = right;
        }

        if (needs[s[left]] == 0) {
          remainCount++;
        }
        needs[s[left]]++;
        left++;
      }

      right++;
    }

    if (!findAnswer) return "";
    return s.substr(answerLeft, answerRight - answerLeft + 1);
  }
};
