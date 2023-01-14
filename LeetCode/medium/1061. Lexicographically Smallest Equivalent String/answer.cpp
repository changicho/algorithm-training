#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use union find
// time : O(N + M)
// space : O(M)
class Solution {
 private:
  unordered_map<char, char> parents;

  char find(char c) {
    if (parents[c] == c) return c;

    return parents[c] = find(parents[c]);
  }

  void merge(char a, char b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (a > b) swap(a, b);

    parents[b] = a;
  }

 public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    for (char c = 'a'; c <= 'z'; c++) {
      parents[c] = c;
    }

    int size = s1.size();
    for (int i = 0; i < size; i++) {
      merge(s1[i], s2[i]);
    }

    string ret = "";
    for (char &c : baseStr) {
      ret += find(c);
    }
    return ret;
  }
};