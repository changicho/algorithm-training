#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// brute force
// time : O(N * M * L)
// space : O(N * L)
class Solution {
 private:
  bool check(string& a, string& b) {
    int diff = 0;

    if (a.size() != b.size()) return false;
    int size = a.size();
    for (int i = 0; i < size; i++) {
      if (a[i] != b[i]) diff++;
    }
    return diff <= 2;
  }

 public:
  vector<string> twoEditWords(vector<string>& queries,
                              vector<string>& dictionary) {
    vector<string> answer;

    for (string& q : queries) {
      for (string& dic : dictionary) {
        if (check(q, dic)) {
          answer.push_back(q);
          break;
        }
      }
    }
    return answer;
  }
};

// use trie
// time : O((N * L) + M * N^2 * 26^2)
// space : O(N * L)
class Solution {
 private:
  struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;
  };

  struct Trie {
    TrieNode* root = new TrieNode();

    void insert(string& s) {
      TrieNode* cur = root;
      for (char& c : s) {
        if (cur->children[c - 'a'] == NULL) {
          cur->children[c - 'a'] = new TrieNode();
        }

        cur = cur->children[c - 'a'];
      }

      cur->isEnd = true;
    }

    bool recursive(TrieNode* cur, string& s, int index, int count) {
      if (s.size() == index) return true;
      if (cur == NULL) return false;
      bool ret = false;
      for (int i = 0; i < 26; i++) {
        if (cur->children[i] == NULL) continue;
        int nextCount = count - (i != s[index] - 'a');
        if (nextCount < 0) continue;

        ret |= recursive(cur->children[i], s, index + 1, nextCount);
      }
      return ret;
    }

    bool find(string& s) { return recursive(root, s, 0, 2); }
  };

 public:
  vector<string> twoEditWords(vector<string>& queries,
                              vector<string>& dictionary) {
    vector<string> answer;

    Trie trie;

    for (string& dic : dictionary) {
      trie.insert(dic);
    }

    for (string& q : queries) {
      if (trie.find(q)) answer.push_back(q);
    }
    return answer;
  }
};