#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming & DFS & backtracking

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    int length = s.length();
    vector<vector<string>> answers;
    vector<vector<bool>> isPalindrome(length, vector<bool>(length, false));
    vector<vector<string>> subStrings(length, vector<string>(length, ""));

    for (int i = 0; i < length; i++) {
      isPalindrome[i][i] = true;
      subStrings[i][i] += s[i];

      if (i + 1 < length && s[i] == s[i + 1]) {
        isPalindrome[i][i + 1] = true;
        subStrings[i][i + 1] += s[i];
        subStrings[i][i + 1] += s[i + 1];
      }
    }

    for (int size = 0; size < length; size++) {
      for (int left = 1; left < length - size - 1; left++) {
        int right = left + size;

        if (isPalindrome[left][right] && s[left - 1] == s[right + 1]) {
          isPalindrome[left - 1][right + 1] = true;
          subStrings[left - 1][right + 1] = s[left - 1] + subStrings[left][right] + s[right + 1];
        }
      }
    }

    vector<string> currentList;

    recursive(answers, s, 0, currentList, isPalindrome, subStrings);
    return answers;
  }

  void recursive(vector<vector<string>> &answers, string &s, int left, vector<string> &array, vector<vector<bool>> &isPalindrome, vector<vector<string>> &subStrings) {
    if (left >= s.length()) {
      answers.push_back(array);
      return;
    }

    for (int right = left; right < s.length(); right++) {
      if (isPalindrome[left][right]) {
        array.push_back(subStrings[left][right]);
        recursive(answers, s, right + 1, array, isPalindrome, subStrings);
        array.pop_back();
      }
    }
  }
};