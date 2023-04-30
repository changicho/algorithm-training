#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use union find
// time : O(N^2 * L)
// space : O(N^2 * L)
class Solution {
 private:
  bool isSimilar(string &a, string &b) {
    if (a.size() != b.size()) return false;

    int diffCount = 0;
    int size = a.size();
    for (int i = 0; i < size; i++) {
      if (a[i] != b[i]) diffCount++;
    }
    return diffCount == 2;
  }

  unordered_map<string, string> parents;
  int groupCount = 0;
  string find(string &node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(string a, string b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) swap(a, b);

    parents[b] = a;
    groupCount--;
  }

 public:
  int numSimilarGroups(vector<string> &strs) {
    unordered_set<string> words(strs.begin(), strs.end());

    int size = words.size();
    unordered_map<string, vector<string>> graph;

    for (string from : words) {
      for (string to : words) {
        if (from == to) continue;
        if (!isSimilar(from, to)) continue;

        graph[from].push_back(to);
        graph[to].push_back(from);
      }
    }

    for (string word : words) {
      parents[word] = word;
    }
    groupCount = size;

    for (string word : words) {
      for (string next : graph[word]) {
        merge(word, next);
      }
    }

    return groupCount;
  }
};