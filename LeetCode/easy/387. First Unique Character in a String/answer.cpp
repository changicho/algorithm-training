#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map

class Solution {
 public:
  int firstUniqChar(string s) {
    // key : alphabet, value : count
    unordered_map<char, int> counts;
    int length = s.length();
    // set init value -1
    int answer = -1;

    // count all alphabet
    for (char &c : s) {
      counts[c] += 1;
    }

    // iterate all index of s
    for (int i = 0; i < length; i++) {
      // if current char's count is 1 that is First Unique Character
      if (counts[s[i]] == 1) {
        answer = i;
        break;
      }
    }

    return answer;
  }
};