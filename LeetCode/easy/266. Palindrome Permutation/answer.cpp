#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use odd count

class Solution {
 public:
  bool canPermutePalindrome(string s) {
    unordered_map<char, int> um;

    for (char c : s) {
      um[c] += 1;
    }

    int oddCount = 0;
    for (auto &it : um) {
      if (it.second % 2 == 1) {
        oddCount += 1;
      }
    }

    return oddCount < 2;
  }
};

// use odd count (array)

class Solution {
 public:
  bool canPermutePalindrome(string s) {
    int count[256] = {
        0,
    };

    for (char c : s) {
      count[c] += 1;
    }

    int oddCount = 0;
    for (int cur : count) {
      if (cur % 2 == 1) {
        oddCount += 1;
      }
    }

    return oddCount < 2;
  }
};