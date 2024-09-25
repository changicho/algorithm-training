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
// time : O(N + M)
// space : O(N)
class Solution {
 private:
  struct TrieNode {
    bool isEnd = false;
    TrieNode *children[10] = {
        0,
    };
  };
  int answer = 0;
  TrieNode *root = new TrieNode();

  void insert(int num) {
    string line = to_string(num);

    TrieNode *cur = root;
    for (char &c : line) {
      if (cur->children[c - '0'] == NULL) {
        cur->children[c - '0'] = new TrieNode();
      }
      cur = cur->children[c - '0'];
    }
    cur->isEnd = true;
  }

  void check(int num) {
    string line = to_string(num);
    int count = 0;

    TrieNode *cur = root;
    for (char &c : line) {
      if (cur->children[c - '0'] == NULL) break;
      count++;

      cur = cur->children[c - '0'];
    }

    answer = max(answer, count);
  }

 public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    if (arr1.size() > arr2.size()) swap(arr1, arr2);

    for (int &num : arr1) {
      insert(num);
    }

    for (int &num : arr2) {
      check(num);
    }
    return answer;
  }
};

// use hash set
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    unordered_set<string> us;

    if (arr1.size() > arr2.size()) swap(arr1, arr2);

    int answer = 0;
    for (int &num : arr1) {
      string temp = "";
      for (char &c : to_string(num)) {
        temp += c;
        us.insert(temp);
      }
    }

    for (int &num : arr2) {
      string temp = "";
      for (char &c : to_string(num)) {
        temp += c;

        if (us.count(temp)) {
          answer = max(answer, (int)temp.size());
        }
      }
    }
    return answer;
  }
};
