#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * L^3)
// space : O(N * L)
class Solution {
 private:
  bool wordBreak(string s, unordered_set<string>& wordSet) {
    int length = s.length();

    vector<bool> visited(length + 1, false);
    visited[0] = true;

    for (int right = 0; right < length; right++) {
      for (int left = right; left >= 0; left--) {
        int curLength = right - left + 1;
        if (curLength == length) break;
        string cur = s.substr(left, curLength);

        if (wordSet.count(cur) > 0 && visited[left]) {
          visited[right + 1] = true;
          break;
        }
      }
    }

    return visited[length];
  }

 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> wordSet(words.begin(), words.end());

    vector<string> answer;
    for (string& w : words) {
      if (wordBreak(w, wordSet)) {
        answer.push_back(w);
      }
    }
    return answer;
  }
};

// use DFS
// time : O(N * L^3)
// space : O(N * L)
class Solution {
 private:
  bool isConcatenate(string word, unordered_set<string>& wordSet) {
    for (int i = 1; i < word.length(); i++) {
      string prefix = word.substr(0, i);
      string suffix = word.substr(i, word.length() - i);

      if (wordSet.count(prefix) == 0) continue;
      if (wordSet.count(suffix) > 0 || isConcatenate(suffix, wordSet)) {
        return true;
      }
    }
    return false;
  }

 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> wordSet(words.begin(), words.end());
    vector<string> ret;

    for (string& w : words) {
      if (isConcatenate(w, wordSet)) {
        ret.push_back(w);
      }
    }
    return ret;
  }
};
