#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet;
    int length = s.length();

    for (string word : wordDict) {
      wordSet.insert(word);
    }

    vector<bool> visited(length + 1, false);
    visited[0] = true;

    for (int right = 0; right < length; right++) {
      for (int left = right; left >= 0; left--) {
        int curLength = right - left + 1;
        string cur = s.substr(left, curLength);

        if (wordSet.find(cur) != wordSet.end() && visited[left]) {
          visited[right + 1] = true;
          break;
        }
      }
    }

    return visited[length];
  }
};

// use dynamic programming with memoization for key

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet;
    int length = s.length();

    int maxWordLength = 0;
    for (string word : wordDict) {
      reverse(word.begin(), word.end());
      maxWordLength = max(maxWordLength, (int)word.length());
      wordSet.insert(word);
    }

    vector<bool> visited(length + 1, false);
    visited[0] = true;

    for (int right = 0; right < length; right++) {
      string cur = "";

      int limit = max(0, right - maxWordLength);
      for (int left = right; left >= limit; left--) {
        cur += s[left];

        if (wordSet.find(cur) != wordSet.end() && visited[left]) {
          visited[right + 1] = true;
          break;
        }
      }
    }

    return visited[length];
  }
};

// use recursive, backtracking

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int length = s.length();
    unordered_set<string> wordSet;

    vector<bool> visited(length + 1, false);
    for (string word : wordDict) {
      wordSet.insert(word);
    }

    for (string word1 : wordDict) {
      for (string word2 : wordDict) {
        string target = word1 + word2;

        if (wordSet.find(target) != wordSet.end()) wordSet.erase(target);
      }
    }

    recursive(0, s, wordSet, visited);

    return visited[length];
  }

  void recursive(int index, string& s, unordered_set<string>& wordSet, vector<bool>& visited) {
    int length = s.length();
    visited[index] = true;

    string temp = "";
    for (int i = index; i < length; i++) {
      temp += s[i];

      if (wordSet.find(temp) != wordSet.end() && !visited[i + 1]) {
        recursive(i + 1, s, wordSet, visited);
      }
    }
  }
};