#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use recursive & backtracking

class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> answers;
    vector<string> array;

    recursive(answers, array, 0, s);

    return answers;
  }

  void recursive(vector<string> &answer, vector<string> &array, int index, string &s) {
    int length = s.length();
    if (array.size() == 4 && index == length) {
      answer.push_back(convertToIp(array));
      return;
    }
    if (length - index > (4 - array.size()) * 3) return;

    int limit = min(index + 3, length);
    string temp = "";
    int cur = 0;
    for (int i = index; i < limit; i++) {
      temp += s[i];
      cur = cur * 10 + s[i] - '0';

      if (i - index > 0 && temp.front() == '0') {
        break;
      }

      if (0 <= cur && cur <= 255) {
        array.push_back(temp);
        recursive(answer, array, i + 1, s);
        array.pop_back();
      }
    }
  }

  string convertToIp(vector<string> &v) {
    string ret = "";
    for (string s : v) {
      ret += s + ".";
    }
    ret.erase(ret.length() - 1, 1);
    return ret;
  }
};

// use 4th iteration

class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> answers;

    for (int a = 1; a <= 3; a++) {
      for (int b = 1; b <= 3; b++) {
        for (int c = 1; c <= 3; c++) {
          for (int d = 1; d <= 3; d++) {
            if (a + b + c + d != s.length()) continue;

            int first = stoi(s.substr(0, a));
            int second = stoi(s.substr(a, b));
            int third = stoi(s.substr(a + b, c));
            int fourth = stoi(s.substr(a + b + c, d));

            if (first <= 255 && second <= 255 && third <= 255 && fourth <= 255) {
              string ans = to_string(first) + "." + to_string(second) + "." + to_string(third) + "." + to_string(fourth);

              if (ans.length() == s.length() + 3) {
                answers.push_back(ans);
              }
            }
          }
        }
      }
    }

    return answers;
  }
};