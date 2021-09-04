#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS

class Solution {
 private:
  void recursive(vector<string> &answer, string &s, int index) {
    int length = s.length();
    if (length == index) {
      answer.push_back(s);
      return;
    }

    recursive(answer, s, index + 1);
    if (isdigit(s[index])) return;

    char origin = s[index];
    if (islower(s[index])) {
      s[index] = toupper(s[index]);
    } else if (isupper(s[index])) {
      s[index] = tolower(s[index]);
    }
    recursive(answer, s, index + 1);
    s[index] = origin;
  }

 public:
  vector<string> letterCasePermutation(string s) {
    vector<string> answer;

    recursive(answer, s, 0);

    return answer;
  }
};