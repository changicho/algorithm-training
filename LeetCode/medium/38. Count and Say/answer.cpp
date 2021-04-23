#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use vector

class Solution {
 public:
  string countAndSay(int n) {
    string number = "1";

    for (int i = 1; i < n; i++) {
      number = convert(number);
    }
    return number;
  }

  string convert(string number) {
    vector<string> v = split(number);
    string ret = "";

    for (string s : v) {
      int count = s.length();
      char target = s[0];

      ret += to_string(count) + target;
    }
    return ret;
  }

  vector<string> split(string number) {
    vector<string> v;
    string temp = "";
    char before = 'a';
    for (char c : number) {
      if (c != before) {
        if (temp != "") v.push_back(temp);
        temp = "";
        before = c;
      }
      temp += c;
    }

    v.push_back(temp);
    return v;
  }
};

// not use vector

class Solution {
 public:
  string countAndSay(int n) {
    string number = "1";
    for (int i = 1; i < n; i++) {
      string temp = "";
      number += '&';

      int count = 1;
      for (int index = 1; index < number.length(); index++) {
        if (number[index] == number[index - 1]) {
          count++;
        } else {
          temp += to_string(count);
          temp += number[index - 1];
          count = 1;
        }
      }
      number = temp;
    }
    return number;
  }
};

// use recursive

class Solution {
 public:
  string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }
    string number = countAndSay(n - 1);
    string temp = "";
    number += '&';

    int count = 1;
    for (int index = 1; index < number.length(); index++) {
      if (number[index] == number[index - 1]) {
        count++;
      } else {
        temp += to_string(count);
        temp += number[index - 1];
        count = 1;
      }
    }
    number = temp;
    return number;
  }
};