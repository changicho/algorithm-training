#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map with two pointer

class WordDistance {
 private:
  unordered_map<string, vector<int>> um;

 public:
  WordDistance(vector<string>& wordsDict) {
    int size = wordsDict.size();
    for (int i = 0; i < size; i++) {
      string word = wordsDict[i];

      um[word].emplace_back(i);
    }
  }

  int shortest(string word1, string word2) {
    vector<int>& v1 = um[word1];
    vector<int>& v2 = um[word2];

    int diff = abs(v1.front() - v2.back());
    int idx1 = 0, idx2 = 0;
    int size1 = v1.size(), size2 = v2.size();

    while (idx1 < size1 && idx2 < size2) {
      int temp = abs(v1[idx1] - v2[idx2]);
      diff = min(diff, temp);

      if (v1[idx1] < v2[idx2]) {
        idx1++;
      } else {
        idx2++;
      }
    }

    return diff;
  }
};
