#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N * M)
// space : O(N * M)
class Solution {
 public:
  vector<string> cellsInRange(string s) {
    int charFrom = s[0], charTo = s[3];
    int numFrom = s[1], numTo = s[4];

    vector<string> answer;
    for (char c = charFrom; c <= charTo; c++) {
      for (char num = numFrom; num <= numTo; num++) {
        answer.push_back({c, num});
      }
    }

    return answer;
  }
};