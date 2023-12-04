#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use count
// time : O(N * L)
// space : O(1)
class Solution {
 private:
  bool check(string &word, int counts[26]) {
    int curCount[26] = {
        0,
    };
    for (char &c : word) {
      curCount[c - 'a']++;
      if (curCount[c - 'a'] > counts[c - 'a']) return false;
    }
    return true;
  }

 public:
  int countCharacters(vector<string> &words, string chars) {
    int answer = 0;

    int counts[26] = {
        0,
    };
    for (char &c : chars) {
      counts[c - 'a']++;
    }

    for (string &word : words) {
      if (check(word, counts)) {
        answer += word.size();
      }
    }
    return answer;
  }
};