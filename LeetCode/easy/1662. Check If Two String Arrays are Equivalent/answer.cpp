#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use extra space
// time : O(N * L)
// space : O(N * L)
class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string line1 = "", line2 = "";
    for (string& word : word1) {
      line1 += word;
    }
    for (string& word : word2) {
      line2 += word;
    }

    return line1 == line2;
  }
};

// use two pointer
// time : O(N * L)
// space : O(1)
class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int word1Idx = 0, word2Idx = 0;
    int string1Idx = 0, string2Idx = 0;

    while (word1Idx < word1.size() && word2Idx < word2.size()) {
      if (word1[word1Idx][string1Idx] != word2[word2Idx][string2Idx]) {
        return false;
      }

      string1Idx++;
      string2Idx++;

      if (string1Idx == word1[word1Idx].size()) {
        word1Idx++;
        string1Idx = 0;
      }
      if (string2Idx == word2[word2Idx].size()) {
        word2Idx++;
        string2Idx = 0;
      }
    }

    return word1Idx == word1.size() && word2Idx == word2.size();
  }
};