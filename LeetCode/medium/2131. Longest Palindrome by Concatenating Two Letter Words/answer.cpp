#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map
// time : O(N)
// space : O(1)
class Solution {
 public:
  int longestPalindrome(vector<string> &words) {
    unordered_map<string, int> counts;
    int answer = 0;
    for (string &word : words) {
      string reversed = {word.back(), word.front()};

      if (counts.count(reversed) > 0) {
        counts[reversed]--;
        if (counts[reversed] == 0) counts.erase(reversed);
        answer += 4;
      } else {
        counts[word]++;
      }
    }

    for (auto &it : counts) {
      string word = it.first;
      if (word.front() == word.back()) {
        answer += 2;
        break;
      }
    }
    return answer;
  }
};