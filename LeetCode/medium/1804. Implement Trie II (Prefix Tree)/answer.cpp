#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use trie
// time : O(L)
// space : O(N * L)
class Trie {
 private:
  struct TrieNode {
    TrieNode *children[26] = {
        NULL,
    };
    int count = 0;
    int endCount = 0;
  };

  TrieNode *root = new TrieNode();

 public:
  Trie() {}

  void insert(string word) {
    TrieNode *cur = root;
    for (char &c : word) {
      if (!cur->children[c - 'a']) {
        cur->children[c - 'a'] = new TrieNode();
      }
      cur = cur->children[c - 'a'];
      cur->count++;
    }
    cur->endCount++;
  }

  int countWordsEqualTo(string word) {
    TrieNode *cur = root;
    for (char &c : word) {
      if (!cur->children[c - 'a']) {
        return 0;
      }
      cur = cur->children[c - 'a'];
    }
    return cur->endCount;
  }

  int countWordsStartingWith(string prefix) {
    TrieNode *cur = root;
    for (char &c : prefix) {
      if (!cur->children[c - 'a']) {
        return 0;
      }
      cur = cur->children[c - 'a'];
    }
    return cur->count;
  }

  void erase(string word) {
    TrieNode *cur = root;
    for (char &c : word) {
      cur = cur->children[c - 'a'];
      cur->count--;
    }
    cur->endCount--;
  }
};
