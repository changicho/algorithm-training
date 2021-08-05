#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hashmap

class Solution {
 public:
  int shortestWordDistance(vector<string> &wordsDict, string word1, string word2) {
    int size = wordsDict.size();
    vector<int> arr1, arr2;

    for (int i = 0; i < size; i++) {
      string &word = wordsDict[i];

      if (word == word1) {
        arr1.emplace_back(i);
      }
      if (word == word2) {
        arr2.emplace_back(i);
      }
    }

    int diff = 10001;
    int idx1 = 0, idx2 = 0;
    int size1 = arr1.size(), size2 = arr2.size();

    while (idx1 < size1 && idx2 < size2) {
      if (arr1[idx1] != arr2[idx2]) {
        diff = min(abs(arr1[idx1] - arr2[idx2]), diff);
      }

      if (arr1[idx1] < arr2[idx2]) {
        idx1 += 1;
      } else {
        idx2 += 1;
      }
    }

    return diff;
  }
};

// use iterate

class Solution {
 public:
  int shortestWordDistance(vector<string> &wordsDict, string word1, string word2) {
    int dist = 10001;
    int i1 = dist, i2 = -dist;
    bool isSame = word1 == word2;

    for (int i = 0; i < wordsDict.size(); i++) {
      if (wordsDict[i] == word1) {
        i1 = i;

        if (isSame) swap(i1, i2);
      } else if (wordsDict[i] == word2) {
        i2 = i;
      }

      dist = min(dist, abs(i1 - i2));
    }

    return dist;
  }
};