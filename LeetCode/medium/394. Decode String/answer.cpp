#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use recursive

class Solution {
 public:
  string decodeString(string s) {
    int length = s.length();
    if (length == 0) return "";
    string ret = "";

    for (int i = 0; i < length; i++) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        ret += s[i];
        continue;
      }

      string countStr = getNumber(s, i);
      int count = stoi(countStr);
      i += countStr.length();

      string temp = getInnerStr(s, i);
      i += temp.length() + 1;

      string innerString = decodeString(temp);
      while (count--) {
        ret += innerString;
      }
    }

    return ret;
  }

  string getNumber(string &s, int start) {
    string temp = "";
    while (s[start] >= '0' && s[start] <= '9') {
      temp += s[start];
      start++;
    }
    return temp;
  }

  string getInnerStr(string &s, int start) {
    string temp = "";
    int openCount = 1;
    start++;
    while (openCount > 0) {
      if (s[start] == '[') {
        openCount += 1;
      } else if (s[start] == ']') {
        openCount -= 1;
      }
      temp += s[start];
      start++;
    }
    temp.erase(temp.length() - 1, 1);

    return temp;
  }
};

// use stack

class Solution {
 public:
  string decodeString(string s) {
    stack<string> chars;
    stack<int> nums;

    string answer = "";
    int num = 0;

    for (char c : s) {
      if (isdigit(c)) {
        num = num * 10 + (c - '0');
        continue;
      }
      if (isalpha(c)) {
        answer += c;
        continue;
      }
      if (c == '[') {
        chars.push(answer);
        nums.push(num);

        answer = "";
        num = 0;
        continue;
      }
      if (c == ']') {
        string pattern = answer;
        int count = nums.top() - 1;

        while (count--) {
          answer += pattern;
        }
        answer = chars.top() + answer;
        chars.pop();
        nums.pop();
        continue;
      }
    }

    return answer;
  }
};