#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N * L)
// space : O(1)
class Solution {
 public:
  bool makeEqual(vector<string> &words) {
    int size = words.size();

    int count[26] = {
        0,
    };
    for (string &word : words) {
      for (char &c : word) {
        count[c - 'a']++;
      }
    }

    for (int i = 0; i < 26; i++) {
      int c = count[i];

      if (c % size != 0) return false;
    }
    return true;
  }
};