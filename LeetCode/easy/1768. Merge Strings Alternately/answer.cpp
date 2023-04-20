#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointer
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    string ret = "";
    int idx1 = 0, idx2 = 0;
    int size1 = word1.size(), size2 = word2.size();

    while (idx1 < size1 || idx2 < size2) {
      if (idx1 < size1) {
        ret += word1[idx1];
        idx1++;
      }
      if (idx2 < size2) {
        ret += word2[idx2];
        idx2++;
      }
    }
    return ret;
  }
};