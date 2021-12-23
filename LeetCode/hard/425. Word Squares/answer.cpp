#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map (prefix map)

class Solution {
 private:
  unordered_map<string, vector<string>> prefixMap;
  vector<vector<string>> answer;

  void recursive(vector<string> &square, int &limit) {
    int size = square.size();

    if (size == limit) {
      answer.push_back(square);
      return;
    }

    string target = "";
    for (int i = 0; i < size; i++) {
      target += square[i][size];
    }

    for (string &word : prefixMap[target]) {
      square.push_back(word);
      recursive(square, limit);
      square.pop_back();
    }
  }

 public:
  vector<vector<string>> wordSquares(vector<string> &words) {
    for (string &word : words) {
      string temp = "";
      prefixMap[temp].push_back(word);
      for (char &c : word) {
        temp += c;
        prefixMap[temp].push_back(word);
      }
    }
    int limit = words.front().length();

    vector<string> square;
    recursive(square, limit);

    return answer;
  }
};

// use trie

class Trie {
 private:
  struct TrieNode {
    TrieNode *children[26] = {
        NULL,
    };
    bool isEnd;
    vector<string> words;

    TrieNode() { isEnd = false; }
  };

  TrieNode *root = new TrieNode;

 public:
  void insert(string word) {
    TrieNode *node = root;
    node->words.push_back(word);

    for (char &c : word) {
      if (!node->children[c - 'a']) {
        node->children[c - 'a'] = new TrieNode;
      }

      node = node->children[c - 'a'];
      node->words.push_back(word);
    }

    node->isEnd = true;
  }

  vector<string> startsWith(string prefix) {
    TrieNode *node = root;

    for (char &c : prefix) {
      if (!node->children[c - 'a']) {
        return {};
      }

      node = node->children[c - 'a'];
    }

    return node->words;
  }
};

class Solution {
 private:
  unordered_map<string, vector<string>> prefixMap;
  vector<vector<string>> answer;
  Trie trie;

  void recursive(vector<string> &square, int &limit) {
    int size = square.size();

    if (size == limit) {
      answer.push_back(square);
      return;
    }

    string target = "";
    for (int i = 0; i < size; i++) {
      target += square[i][size];
    }

    vector<string> words = trie.startsWith(target);
    for (string &word : words) {
      square.push_back(word);
      recursive(square, limit);
      square.pop_back();
    }
  }

 public:
  vector<vector<string>> wordSquares(vector<string> &words) {
    for (string &word : words) {
      trie.insert(word);
    }
    int limit = words.front().length();

    vector<string> square;
    recursive(square, limit);

    return answer;
  }
};