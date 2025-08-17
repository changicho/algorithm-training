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

// use hash map
// time : O(N * L)
// space : O(N * L)
class FileSystem {
 private:
  unordered_map<string, int> um;

  vector<string> split(string &path) {
    vector<string> ret;
    string temp = "";
    for (char &c : path) {
      if (c == '/') {
        if (temp == "") continue;
        ret.push_back(temp);
        temp = "";
      } else {
        temp += c;
      }
    }
    ret.push_back(temp);
    return ret;
  }

 public:
  FileSystem() { um["/"] = 0; }

  bool createPath(string path, int value) {
    if (um.count(path) > 0) return false;

    vector<string> token = split(path);

    string temp = "/";
    int size = token.size();

    for (int i = 0; i < size - 1; i++) {
      string p = token[i];
      temp += p;
      if (um.count(temp) == 0) return false;
      temp += "/";
    }

    temp += token.back();

    um[temp] = value;
    return true;
  }

  int get(string path) {
    if (um.count(path) == 0) return -1;
    return um[path];
  }
};

// use trie
// time : O(T)
// space : O(T)
class FileSystem {
 private:
  struct TrieNode {
    int val;
    unordered_map<string, TrieNode *> children;
  };

  struct Trie {
    TrieNode *root = new TrieNode();

    vector<string> split(string &path) {
      vector<string> ret;
      string temp = "";
      for (char &c : path) {
        if (c == '/') {
          if (temp == "") continue;
          ret.push_back(temp);
          temp = "";
        } else {
          temp += c;
        }
      }
      ret.push_back(temp);
      return ret;
    }

    int find(string &path) {
      vector<string> token = split(path);

      TrieNode *cur = root;

      for (string &p : token) {
        if (cur->children.count(p) == 0) return -1;
        cur = cur->children[p];
      }

      return cur->val;
    }

    bool insert(string &path, int val) {
      vector<string> token = split(path);

      TrieNode *cur = root;

      for (int i = 0; i < token.size() - 1; i++) {
        string p = token[i];
        if (cur->children.count(p) == 0) return false;
        cur = cur->children[p];
      }
      cur->children[token.back()] = new TrieNode();
      cur->children[token.back()]->val = val;

      return true;
    }
  };

  Trie *trie = new Trie();

 public:
  FileSystem() {}

  bool createPath(string path, int value) {
    if (trie->find(path) != -1) return false;

    return trie->insert(path, value);
  }

  int get(string path) { return trie->find(path); }
};
