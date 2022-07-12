#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  bool validWordSquare(vector<string> &words) {
    int length = words.size();
    for (string &w : words) {
      int cur = w.length();
      length = max(length, cur);
    }
    while (words.size() < length) {
      words.push_back(string(length, ' '));
    }
    for (string &w : words) {
      while (w.length() < length) {
        w += " ";
      }
    }

    for (int y = 0; y < length; y++) {
      for (int i = 0; i < length; i++) {
        if (words[y][i] != words[i][y]) return false;
      }
    }
    return true;
  }
};

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  bool validWordSquare(vector<string> &words) {
    for (int y = 0; y < words.size(); y++) {
      for (int x = 0; x < words[y].size(); x++) {
        if (x >= words.size() || words[x].size() <= y ||
            words[x][y] != words[y][x]) {
          return false;
        }
      }
    }
    return true;
  }
};