#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use math
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> divisibilityArray(string word, int m) {
    string num = "";

    long long temp = 0;

    vector<int> answer;
    for (char &c : word) {
      temp = (temp * 10 + (int)c - '0') % m;

      if (temp == 0) {
        answer.push_back(1);
      } else {
        answer.push_back(0);
      }
    }
    return answer;
  }
};