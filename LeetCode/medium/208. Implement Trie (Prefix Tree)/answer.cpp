#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use trie

class Trie {
 private:
  struct TrieNode {
    unordered_map<char, TrieNode *> children;
    bool isEnd;

    TrieNode() { isEnd = false; }
  };

  TrieNode *root = new TrieNode;

 public:
  void insert(string word) {
    TrieNode *node = root;

    for (char c : word) {
      if (!node->children[c]) {
        node->children[c] = new TrieNode;
      }

      node = node->children[c];
    }

    node->isEnd = true;
  }

  bool search(string word) {
    TrieNode *node = root;

    for (char c : word) {
      if (!node->children[c]) {
        return false;
      }

      node = node->children[c];
    }

    return node && node->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode *node = root;

    for (char c : prefix) {
      if (!node->children[c]) {
        return false;
      }

      node = node->children[c];
    }

    return node;
  }
};

// use trie with array

class Trie {
 private:
  struct TrieNode {
    struct TrieNode *children[256] = {
        NULL,
    };

    bool isEnd = false;
  };

  TrieNode *root = new TrieNode;

 public:
  void insert(string word) {
    TrieNode *node = root;

    for (char c : word) {
      int index = c;
      if (!node->children[index]) {
        node->children[index] = new TrieNode;
      }

      node = node->children[index];
    }

    node->isEnd = true;
  }

  bool search(string word) {
    TrieNode *node = root;

    for (char c : word) {
      int index = c;
      if (!node->children[index]) return false;

      node = node->children[index];
    }

    return node && node->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode *node = root;

    for (char c : prefix) {
      int index = c;
      if (!node->children[index]) return false;

      node = node->children[index];
    }

    return node;
  }
};
