#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// split 이용

class Solution {
 public:
  int lengthOfLastWord(string s) {
    vector<string> vs = split(s);

    if (vs.size() == 0) return 0;
    return vs.back().length();
  }

 private:
  vector<string> split(string s) {
    vector<string> ret;
    string temp = "";

    for (char c : s) {
      if (c == ' ') {
        if (temp == "") continue;
        ret.push_back(temp);
        temp = "";
      } else {
        temp += c;
      }
    }

    if (temp != "") ret.push_back(temp);

    return ret;
  }
};

// 역순으로 탐색

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int length = 0;
    for (int index = s.length() - 1; index >= 0; index -= 1) {
      if (length != 0 && s[index] == ' ') {
        break;
      }
      if (s[index] != ' ') {
        length += 1;
      }
    }

    return length;
  }
};