#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use trie & recursive
// time :
// - insert : O(L)
// - search : O(L * min(26^3, N))
// space : O(L + 26^L)
class WordDictionary {
  struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
  };

  TrieNode* root = new TrieNode();

  bool recursive(int index, string& word, TrieNode* node) {
    int size = word.size();

    if (index == size) {
      return node->isEnd;
    }

    if (word[index] != '.') {
      char c = word[index];
      if (node->children[c - 'a'] == NULL) return false;
      bool ret = recursive(index + 1, word, node->children[c - 'a']);

      return ret;
    }

    for (char c = 'a'; c <= 'z'; c++) {
      if (node->children[c - 'a'] == NULL) continue;

      bool ret = recursive(index + 1, word, node->children[c - 'a']);

      if (ret) return true;
    }
    return false;
  }

 public:
  WordDictionary() {}

  void addWord(string word) {
    TrieNode* cur = root;
    for (char& c : word) {
      if (cur->children[c - 'a'] == NULL)
        cur->children[c - 'a'] = new TrieNode();

      cur = cur->children[c - 'a'];
    }
    cur->isEnd = true;
  }

  bool search(string word) {
    TrieNode* cur = root;
    return recursive(0, word, cur);
  }
};
