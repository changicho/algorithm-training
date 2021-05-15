#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> dirs = split(path, '/');
    stack<string> st;

    for (string dir : dirs) {
      if (dir == "") continue;
      if (dir == "..") {
        if (!st.empty()) st.pop();
        continue;
      } else if (dir == ".") {
        continue;
      }

      st.push(dir);
    }

    vector<string> paths;
    while (!st.empty()) {
      string s = st.top();
      st.pop();
      paths.push_back(s);
    }
    reverse(paths.begin(), paths.end());

    string ret = "/";
    for (string p : paths) {
      ret += p + "/";
    }

    if (ret.length() > 1) ret.erase(ret.length() - 1, 1);
    return ret;
  }

  vector<string> split(string s, char t) {
    vector<string> ret;
    string temp = "";

    for (char c : s) {
      if (c == t) {
        ret.push_back(temp);
        temp = "";
      } else {
        temp += c;
      }
    }

    if (temp.length() > 0) ret.push_back(temp);
    return ret;
  }
};

// use stringstream

class Solution {
 public:
  string simplifyPath(string path) {
    string res = "";
    string dir;
    vector<string> st;
    stringstream ss(path);

    while (getline(ss, dir, '/')) {
      if (dir == "" || dir == ".") {
        continue;
      } else if (dir == ".." && !st.empty()) {
        st.pop_back();
      } else if (dir != "..") {
        st.push_back(dir);
      }
    }

    for (string dir : st) {
      res += "/" + dir;
    }

    return res.empty() ? "/" : res;
  }
};