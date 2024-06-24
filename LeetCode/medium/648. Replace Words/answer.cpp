#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// use trie
// time : O(N * L + M)
// space : O(26^L + M)
class Solution {
 private:
  struct TrieNode {
    TrieNode *children[26] = {NULL};
    bool isEnd = false;
  };

  struct Trie {
    TrieNode *root = new TrieNode();

    void insert(string &word) {
      TrieNode *cur = root;

      for (char &c : word) {
        if (cur->children[c - 'a'] == NULL) {
          cur->children[c - 'a'] = new TrieNode();
        }
        cur = cur->children[c - 'a'];
      }
      cur->isEnd = true;
    }

    string getPrefix(string &word) {
      string prefix = "";
      TrieNode *cur = root;
      for (char &c : word) {
        if (cur->isEnd) {
          return prefix;
        }
        prefix += c;

        if (cur->children[c - 'a'] == NULL) {
          return word;
        }
        cur = cur->children[c - 'a'];
      }
      return prefix;
    }
  };

 public:
  string replaceWords(vector<string> &dictionary, string sentence) {
    Trie trie;

    for (string &word : dictionary) {
      trie.insert(word);
    }

    string ret = "";
    istringstream ss(sentence);
    string word;
    while (getline(ss, word, ' ')) {
      ret += trie.getPrefix(word);

      ret += ' ';
    }

    ret.pop_back();
    return ret;
  }
};