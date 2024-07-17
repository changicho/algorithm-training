#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy stack
// time : O(N)
// space : O(N)
class Solution {
 private:
  int getPoint(string &s, int point, string target) {
    int result = 0;

    string ret = "";
    for (char &c : s) {
      ret += c;

      while (ret.size() >= 2 && ret[ret.size() - 1] == target[1] &&
             ret[ret.size() - 2] == target[0]) {
        ret.pop_back();
        ret.pop_back();
        result += point;
      }
    }
    s = ret;
    return result;
  }

 public:
  int maximumGain(string s, int x, int y) {
    int answer = 0;

    if (x > y) {
      answer += getPoint(s, x, "ab");
      answer += getPoint(s, y, "ba");
    } else {
      answer += getPoint(s, y, "ba");
      answer += getPoint(s, x, "ab");
    }
    return answer;
  }
};