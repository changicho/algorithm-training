#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 private:
  struct Data {
    int tabs;
    string name;
  };

  vector<string> parsing(string &input) {
    vector<string> ret;
    string temp = "";

    for (char c : input) {
      if (c == '\n') {
        ret.push_back(temp);
        temp = "";
        continue;
      }
      temp += c;
    }

    if (temp != "") {
      ret.push_back(temp);
    }
    return ret;
  }

  vector<Data> convert(vector<string> vs) {
    vector<Data> ret;

    for (string &line : vs) {
      int tabs = 0;
      string name = "";

      for (char &c : line) {
        if (c == '\t') {
          tabs += 1;
          continue;
        }
        name += c;
      }

      ret.push_back({tabs, name});
    }

    return ret;
  }

  bool isFile(string name) {
    int dotCount = 0;
    for (char &c : name) {
      if (c == '.') dotCount++;
    }
    return dotCount >= 1 && name.front() != '.' && name.back() != '.';
  }

 public:
  int lengthLongestPath(string input) {
    int answer = 0;
    vector<Data> datum = convert(parsing(input));

    vector<Data> dirs;
    for (Data &data : datum) {
      // trim tabs
      while (!dirs.empty() && data.tabs <= dirs.back().tabs) {
        dirs.pop_back();
      }

      if (isFile(data.name)) {
        int length = data.name.length();
        length += dirs.size();
        for (Data &dir : dirs) {
          length += dir.name.length();
        }

        answer = max(answer, length);
      } else {
        dirs.push_back(data);
      }
    }

    return answer;
  }
};