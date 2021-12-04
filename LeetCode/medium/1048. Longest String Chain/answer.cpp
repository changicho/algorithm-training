#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use top-down dynamic programming

class Solution {
 private:
  unordered_map<string, int> memo;

  int dfs(string current, unordered_set<string> &words) {
    if (memo.find(current) != memo.end()) return memo[current];

    int maxLength = 1;

    for (int i = 0; i < current.length(); i++) {
      string newWord = current.substr(0, i) + current.substr(i + 1);

      if (words.count(newWord) == 0) continue;

      int nextLength = dfs(newWord, words) + 1;
      maxLength = max(maxLength, nextLength);
    }

    return memo[current] = maxLength;
  }

 public:
  int longestStrChain(vector<string> &words) {
    int answer = 0;
    unordered_set<string> wordSet;

    for (string &word : words) {
      wordSet.insert(word);
    }

    for (string &word : words) {
      int length = dfs(word, wordSet);
      answer = max(answer, length);
    }

    return answer;
  }
};

// use bottom-up dynamic programming

class Solution {
 public:
  int longestStrChain(vector<string> &words) {
    unordered_map<string, int> dp;

    sort(words.begin(), words.end(), [](string &word1, string &word2) {
      return word1.size() < word2.size();
    });

    int answer = 1;

    for (const string &word : words) {
      int length = word.length();
      int maximumLength = 1;

      for (int i = 0; i < length; i++) {
        string newWord = word.substr(0, i) + word.substr(i + 1, length + 1);

        if (dp.find(newWord) == dp.end()) continue;

        int previous = dp[newWord];
        maximumLength = max(maximumLength, previous + 1);
      }
      dp[word] = maximumLength;

      answer = max(answer, maximumLength);
    }

    return answer;
  }
};
