#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use vowel count
// time : O(N)
// space : O(1)
class Solution {
 private:
  unordered_set<char> us = {'a', 'e', 'i', 'o', 'u'};

 public:
  bool doesAliceWin(string s) {
    int vowels = 0;

    for (int i = 0; i < s.size(); i++) {
      char c = s[i];

      if (us.count(c)) vowels++;
    }

    // alice : odd
    // bob : even
    if (vowels == 0) return false;

    return true;
  }
};