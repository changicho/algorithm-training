#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  string removeStars(string s) {
    string answer = "";

    for (char &c : s) {
      if (c == '*') {
        if (answer.size() == 0) continue;

        answer.pop_back();
        continue;
      }
      answer.push_back(c);
    }

    return answer;
  }
};