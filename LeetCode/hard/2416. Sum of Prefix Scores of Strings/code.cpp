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
    int count = 0;
    bool isEnd = false;
    TrieNode *children[26] = {NULL};
  };

  TrieNode *root = new TrieNode();

  void insert(string &word) {
    TrieNode *cur = root;
    int sum = 0;
    for (char &c : word) {
      if (cur->children[c - 'a'] == NULL) {
        cur->children[c - 'a'] = new TrieNode();
      }

      cur = cur->children[c - 'a'];
      cur->count++;
      sum += cur->count;
    }
    cur->isEnd = true;
  }

  int query(string &word) {
    TrieNode *cur = root;
    int sum = 0;
    for (char &c : word) {
      cur = cur->children[c - 'a'];

      sum += cur->count;
    }
    return sum;
  }

 public:
  vector<int> sumPrefixScores(vector<string> &words) {
    int size = words.size();
    vector<int> answer(size, 0);

    for (string &word : words) {
      insert(word);
    }
    for (int i = 0; i < size; i++) {
      answer[i] = query(words[i]);
    }
    return answer;
  }
};