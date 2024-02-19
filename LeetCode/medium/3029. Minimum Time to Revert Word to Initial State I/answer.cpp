#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2 / K)
// space : O(N)
class Solution {
 public:
  int minimumTimeToInitialState(string word, int k) {
    int size = word.size();

    for (int i = 1; i <= size / k; i++) {
      if (word.substr(k * i) == word.substr(0, word.length() - k * i)) {
        return i;
      }
    }

    return ceil(size / (double)k);  // (size - pI + k - 1) / k;
  }
};

// use KMP
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minimumTimeToInitialState(string word, int k) {
    int size = word.size();
    vector<int> patternIndexes(size, 0);

    int pI = 0;
    for (int i = 1; i < size; i++) {
      while (pI > 0 && word[i] != word[pI]) {
        pI = patternIndexes[pI - 1];
      }

      if (word[i] == word[pI]) {
        pI++;
        patternIndexes[i] = pI;
      }
    }

    while (pI > 0 && (size - pI) % k > 0) {
      pI = patternIndexes[pI - 1];
    }

    return ceil((size - pI) / (double)k);  // (size - pI + k - 1) / k;
  }
};