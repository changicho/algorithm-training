#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use KMP, binary search
// time : O(N + M + N * log_2(N))
// space : O(N + M)
class Solution {
 private:
  vector<int> kmp(string &s, string &pattern) {
    int size = s.size(), patternSize = pattern.size();
    vector<int> patternArr(patternSize, 0);
    vector<int> ret;

    for (int i = 1, pI = 0; i < patternSize; i++) {
      while (pI > 0 && pattern[i] != pattern[pI]) {
        pI = patternArr[pI - 1];
      }
      if (pattern[i] == pattern[pI]) {
        pI++;
        patternArr[i] = pI;
      }
    }

    for (int i = 0, pI = 0; i < size; i++) {
      while (pI > 0 && s[i] != pattern[pI]) {
        pI = patternArr[pI - 1];
      }

      if (s[i] == pattern[pI]) {
        if (pI == patternSize - 1) {
          ret.push_back(i - patternSize + 1);

          pI = patternArr[pI];
        } else {
          pI++;
        }
      }
    }
    return ret;
  }

 public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> aIndexes = kmp(s, a);
    vector<int> bIndexes = kmp(s, b);

    if (aIndexes.empty() || bIndexes.empty()) return {};

    vector<int> answer;
    for (int &idx : aIndexes) {
      int first = lower_bound(bIndexes.begin(), bIndexes.end(), idx - k) -
                  bIndexes.begin();
      int second =
          lower_bound(bIndexes.begin(), bIndexes.end(), idx) - bIndexes.begin();

      bool isFine = false;
      if (first < bIndexes.size() && abs(idx - bIndexes[first]) <= k) {
        isFine = true;
      }
      if (second < bIndexes.size() && abs(idx - bIndexes[second]) <= k) {
        isFine = true;
      }
      if (isFine) {
        answer.push_back(idx);
      }
    }
    return answer;
  }
};

// use KMP, two pointer
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  vector<int> kmp(string &s, string &pattern) {
    int size = s.size(), patternSize = pattern.size();
    vector<int> patternArr(patternSize, 0);
    vector<int> ret;

    for (int i = 1, pI = 0; i < patternSize; i++) {
      while (pI > 0 && pattern[i] != pattern[pI]) {
        pI = patternArr[pI - 1];
      }
      if (pattern[i] == pattern[pI]) {
        pI++;
        patternArr[i] = pI;
      }
    }

    for (int i = 0, pI = 0; i < size; i++) {
      while (pI > 0 && s[i] != pattern[pI]) {
        pI = patternArr[pI - 1];
      }

      if (s[i] == pattern[pI]) {
        if (pI == patternSize - 1) {
          ret.push_back(i - patternSize + 1);

          pI = patternArr[pI];
        } else {
          pI++;
        }
      }
    }
    return ret;
  }

 public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> aIndexes = kmp(s, a);
    vector<int> bIndexes = kmp(s, b);

    if (aIndexes.empty() || bIndexes.empty()) return {};

    vector<int> answer;
    for (int i = 0, j = 0; i < aIndexes.size(); i++) {
      while (j < bIndexes.size() && aIndexes[i] > bIndexes[j] &&
             abs(aIndexes[i] - bIndexes[j]) > k) {
        j++;
      }

      if (j == bIndexes.size()) break;

      if (abs(aIndexes[i] - bIndexes[j]) <= k) {
        answer.push_back(aIndexes[i]);
      }
    }
    return answer;
  }
};