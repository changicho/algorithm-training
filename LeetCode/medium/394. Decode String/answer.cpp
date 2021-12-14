#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use O(K * N) recursive

class Solution {
 private:
  string decodeString(const string& s, int& index) {
    int length = s.length();
    string result = "";

    while (index < length) {
      if (s[index] == ']') break;

      if (!isdigit(s[index])) {
        result += s[index++];
      } else {
        int number = 0;
        // build k while next character is a digit
        while (index < length && isdigit(s[index])) {
          number = number * 10 + s[index] - '0';
          index++;
        }

        // ignore the opening bracket '['
        index++;

        string converted = decodeString(s, index);
        // ignore the closing bracket ']'
        index++;

        while (number--) {
          result += converted;
        }
      }
    }

    return result;
  }

 public:
  string decodeString(string s) {
    int index = 0;
    return decodeString(s, index);
  }
};

// use two stack

class Solution {
 public:
  string decodeString(string s) {
    stack<int> numberStk;
    stack<string> stringStk;
    string ret = "";
    int number = 0;

    for (char c : s) {
      if (isdigit(c)) {
        number = number * 10 + c - '0';
      } else if (c == '[') {
        // push the number k to numberStk
        numberStk.push(number);
        stringStk.push(ret);

        // initialize
        ret = "";
        number = 0;
      } else if (c == ']') {
        string before = stringStk.top();
        stringStk.pop();

        int count = numberStk.top();
        numberStk.pop();
        while (count--) {
          before += ret;
        }

        ret = before;
      } else {
        ret += c;
      }
    }
    return ret;
  }
};

// use recursive

class Solution {
 private:
  string getNumber(string& s, int start) {
    string temp = "";
    int index = start;
    while (isdigit(s[index])) {
      temp += s[index];
      index++;
    }
    return temp;
  }

  string getInnerStr(string& s, int start) {
    string temp = "";
    int openCount = 1;
    // skip first '['
    int index = start + 1;

    while (openCount > 0) {
      if (s[index] == '[') {
        openCount += 1;
      } else if (s[index] == ']') {
        openCount -= 1;
      }

      temp += s[index];
      index++;
    }
    // remove last ']'
    temp.erase(temp.length() - 1, 1);

    return temp;
  }

 public:
  string decodeString(string s) {
    int length = s.length();
    if (length == 0) return "";
    string ret = "";

    for (int i = 0; i < length; i++) {
      if (isalpha(s[i])) {
        ret += s[i];
        continue;
      }

      string countStr = getNumber(s, i);
      int count = stoi(countStr);
      i += countStr.length();

      string inner = getInnerStr(s, i);
      i += inner.length() + 1;

      string innerString = decodeString(inner);
      while (count--) {
        ret += innerString;
      }
    }

    return ret;
  }
};

// use one stack

class Solution {
 public:
  string decodeString(string s) {
    string ret = "";
    int length = s.length();
    int index = 0;

    while (index < length) {
      char cur = s[index];

      // normal char case
      if (!isdigit(cur)) {
        ret += cur;
        index++;
        continue;
      }

      // find number part
      string numberPart = "";
      while (index < length && isdigit(s[index])) {
        numberPart += s[index];
        index++;
      }
      // catch it from '['
      stack<char> st;

      string innerString = {
          s[index],
      };
      st.push(s[index]);

      index++;

      while (index < length && !st.empty()) {
        char c = s[index];
        index++;
        innerString += c;
        if (c == '[') {
          st.push(c);
        } else if (c == ']') {
          st.pop();
        }
      }

      // innerString like this "[...]"
      innerString.erase(0, 1);
      innerString.erase(innerString.length() - 1);

      string converted = decodeString(innerString);

      int count = stoi(numberPart);
      for (int i = 0; i < count; i++) {
        ret += converted;
      }
    }

    return ret;
  }
};