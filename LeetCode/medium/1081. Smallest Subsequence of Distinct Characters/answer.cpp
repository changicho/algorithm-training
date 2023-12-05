#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  string smallestSubsequence(string s) {
    int counts[26] = {
        0,
    };
    bool choosen[26] = {
        0,
    };
    for (char &c : s) {
      counts[c - 'a']++;
    }

    string answer = "";
    for (char &c : s) {
      counts[c - 'a']--;
      if (choosen[c - 'a']) {
        continue;
      }
      choosen[c - 'a'] = true;

      while (!answer.empty() && answer.back() > c &&
             counts[answer.back() - 'a'] > 0) {
        choosen[answer.back() - 'a'] = false;
        answer.pop_back();
      }

      answer.push_back(c);
    }
    return answer;
  }
};