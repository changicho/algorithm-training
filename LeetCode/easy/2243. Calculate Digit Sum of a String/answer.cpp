#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use recursive
// time : O(L * C)
// space : O(L)
class Solution {
 private:
  vector<string> split(string &s, int k) {
    string temp = "";
    vector<string> v;
    for (char &c : s) {
      temp += c;
      if (temp.length() == k) {
        v.push_back(temp);
        temp = "";
      }
    }

    if (temp != "") v.push_back(temp);
    return v;
  }

 public:
  string digitSum(string s, int k) {
    if (s.length() <= k) return s;

    vector<string> array = split(s, k);

    string next = "";
    for (string &num : array) {
      int cur = 0;
      for (char &c : num) {
        cur += c - '0';
      }

      next += to_string(cur);
    }
    return digitSum(next, k);
  }
};