#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use index moving with count

class Codec {
 public:
  string encode(vector<string>& strs) {
    string ret = "";
    for (string str : strs) {
      ret += to_string(str.length()) + ":";
      ret += str;
    }
    return ret;
  }

  vector<string> decode(string s) {
    vector<string> ret;

    int length = s.length();
    int i = 0;
    string temp = "";

    while (i < length) {
      if (s[i] != ':') {
        temp += s[i];
        i++;
        continue;
      }

      int count = stoi(temp);
      temp = "";
      i++;

      string cur = "";
      for (int j = i; j < i + count; j++) {
        cur += s[j];
      }
      ret.emplace_back(cur);
      i += count;
    }

    return ret;
  }
};

// use ASCII 257

class Codec {
 public:
  string encode(vector<string>& strs) {
    string ret = "";
    for (string str : strs) {
      char divide = (char)257;
      ret += str + divide;
    }
    return ret;
  }

  vector<string> decode(string s) {
    vector<string> ret;

    string temp = "";
    for (char c : s) {
      if (c != (char)257) {
        temp += c;
      } else {
        ret.emplace_back(temp);
        temp = "";
      }
    }

    return ret;
  }
};
