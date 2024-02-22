#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N * M)
// space : O(1)
class Solution {
 private:
  bool check(int cur, int before, int p) {
    if (p == 1 && cur > before) return true;
    if (p == 0 && cur == before) return true;
    if (p == -1 && cur < before) return true;

    return false;
  }

 public:
  int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
    int size = nums.size();
    int pSize = pattern.size();

    int answer = 0;
    for (int i = 0; i < size - pSize; i++) {
      int before = nums[i];
      bool isFine = true;

      for (int pI = 0; pI < pSize; pI++) {
        int cur = nums[i + pI + 1];
        if (!check(cur, before, pattern[pI])) {
          isFine = false;
          break;
        }
        before = cur;
      }

      if (isFine) answer++;
    }
    return answer;
  }
};

// use KMP
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  int kmp(vector<int>& nums, vector<int>& pattern) {
    int answer = 0;
    int size = nums.size(), pSize = pattern.size();
    vector<int> pIndexes(pSize, 0);

    for (int curIdx = 1, patternIdx = 0; curIdx < pSize; curIdx++) {
      while (patternIdx > 0 && pattern[curIdx] != pattern[patternIdx]) {
        patternIdx = pIndexes[patternIdx - 1];
      }
      if (pattern[curIdx] == pattern[patternIdx]) {
        patternIdx++;
        pIndexes[curIdx] = patternIdx;
      }
    }

    for (int lineIdx = 0, patternIdx = 0; lineIdx < size; lineIdx++) {
      while (patternIdx > 0 && nums[lineIdx] != pattern[patternIdx]) {
        patternIdx = pIndexes[patternIdx - 1];
      }

      if (nums[lineIdx] == pattern[patternIdx]) {
        if (patternIdx == pSize - 1) {
          answer++;

          patternIdx = pIndexes[patternIdx];
        } else {
          patternIdx++;
        }
      }
    }

    return answer;
  }

 public:
  int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
    int size = nums.size();
    int pSize = pattern.size();

    int answer = 0;

    vector<int> pI;
    for (int i = 0; i < size - 1; i++) {
      int cur = 0;
      if (nums[i + 1] > nums[i]) {
        cur = 1;
      } else if (nums[i + 1] == nums[i]) {
        cur = 0;
      } else {
        cur = -1;
      }

      pI.emplace_back(cur);
    }

    return kmp(pI, pattern);
  }
};