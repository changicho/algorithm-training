#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use stack
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool isBad(string &str) {
    int length = str.size();
    char a = str[length - 1], b = str[length - 2];
    if (a != b && (tolower(a) == tolower(b))) return true;
    return false;
  }

 public:
  string makeGood(string s) {
    string answer = "";

    for (char &c : s) {
      answer += c;

      while (answer.size() >= 2 && isBad(answer)) {
        answer.pop_back();
        answer.pop_back();
      }
    }

    return answer;
  }
};