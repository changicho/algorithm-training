#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use trie
// time : O(N * L)
// space : O(N * L)
class Solution {
 private:
  struct TrieNode {
    bool isEnd = false;
    TrieNode *children[26] = {NULL};
  };

  string answer = "";
  TrieNode *root = new TrieNode();

  void insert(string &s) {
    TrieNode *cur = root;

    for (char &c : s) {
      if (cur->children[c - 'a'] == NULL) {
        cur->children[c - 'a'] = new TrieNode();
      }

      cur = cur->children[c - 'a'];
    }

    cur->isEnd = true;
  }

  void isPrefix(string &s) {
    TrieNode *cur = root;
    bool isPrefix = true;

    for (char &c : s) {
      cur = cur->children[c - 'a'];
      isPrefix &= cur->isEnd;
    }

    if (isPrefix) {
      if (answer.size() < s.size()) {
        answer = s;
      } else if (answer.size() == s.size()) {
        answer = min(answer, s);
      }
    }
  }

 public:
  string longestWord(vector<string> &words) {
    int size = words.size();

    for (string &word : words) {
      insert(word);
    }

    for (string &word : words) {
      isPrefix(word);
    }

    return answer;
  }
};

// use hash set
// time : O(N * L)
// space : O(N * L)
class Solution {
 public:
  string longestWord(vector<string> &words) {
    unordered_set<string> us(words.begin(), words.end());

    int size = words.size();

    string answer = "";

    for (string &word : words) {
      bool isPrefix = true;

      string path = "";
      for (char &c : word) {
        path += c;

        isPrefix &= us.count(path) > 0;

        if (!isPrefix) break;
      }

      if (isPrefix) {
        if (answer.size() < word.size()) {
          answer = word;
        } else if (answer.size() == word.size()) {
          answer = min(answer, word);
        }
      }
    }

    return answer;
  }
};

// use hash set with sort
// time : O(N * log_2(N) * L)
// space : O(N * L)
class Solution {
 public:
  string longestWord(vector<string> &words) {
    sort(words.begin(), words.end());
    unordered_set<string> validSet;
    validSet.insert("");

    int size = words.size();

    string answer = "";

    for (string &word : words) {
      char back = word.back();
      word.pop_back();

      if (validSet.count(word)) {
        word.push_back(back);
        validSet.insert(word);
      } else {
        word.push_back(back);
      }

      if (validSet.count(word)) {
        if (answer.size() < word.size()) {
          answer = word;
        } else if (answer.size() == word.size()) {
          answer = min(answer, word);
        }
      }
    }

    return answer;
  }
};