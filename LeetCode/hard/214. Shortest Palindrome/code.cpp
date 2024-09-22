#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use KMP
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> getPatternIndexes(const string& s) {
    int size = s.size();

    vector<int> pIndexes(size, 0);
    int index = 0;

    for (int i = 1; i < size; i++) {
      while (index > 0 && s[i] != s[index]) {
        index = pIndexes[index - 1];
      }
      if (s[i] == s[index]) {
        index++;
      }
      pIndexes[i] = index;
    }
    return pIndexes;
  }

 public:
  string shortestPalindrome(string s) {
    int size = s.size();

    string reversed = string(s.rbegin(), s.rend());

    string line = s + "#" + reversed;

    vector<int> pIndexes = getPatternIndexes(line);

    int palindromeLength = pIndexes.back();

    string prefix = reversed.substr(0, size - palindromeLength);
    return prefix + s;
  }
};