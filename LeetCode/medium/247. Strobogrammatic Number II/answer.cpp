#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use half backtracking

class Solution {
 private:
  unordered_map<char, char> table = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

  bool startZero(string &num) {
    if (num.length() > 1 && num[0] == '0') return true;
    return false;
  }

  bool canRotate(string &num) {
    int length = num.length();
    string rotated = num;
    reverse(rotated.begin(), rotated.end());

    for (int i = 0; i < length; i++) {
      rotated[i] = table[rotated[i]];
    }

    return rotated == num;
  }

 public:
  vector<string> findStrobogrammatic(int n) {
    queue<string> q;

    vector<string> nums = {"0", "1", "6", "8", "9"};

    for (string num : nums) {
      q.push(num);
    }

    vector<string> answer;
    while (!q.empty()) {
      string cur = q.front();
      q.pop();

      int length = cur.length();

      if (length == n) {
        if (canRotate(cur)) {
          answer.emplace_back(cur);
        }
        continue;
      }

      if (length > n / 2) {
        string next = cur + table[cur[n - 1 - length]];
        q.push(next);
        continue;
      }

      for (string num : nums) {
        string next = cur + num;

        if (startZero(next)) continue;

        q.push(next);
      }
    }

    return answer;
  }
};

// use divide and conquer

class Solution {
 private:
  vector<string> makePart(int left, int n) {
    if (left == 0) return {""};
    if (left == 1) return {"0", "1", "8"};

    vector<string> part = makePart(left - 2, n);
    vector<string> ret;

    for (string cur : part) {
      if (left != n) ret.push_back("0" + cur + "0");
      ret.push_back("1" + cur + "1");
      ret.push_back("6" + cur + "9");
      ret.push_back("8" + cur + "8");
      ret.push_back("9" + cur + "6");
    }

    return ret;
  }

 public:
  vector<string> findStrobogrammatic(int n) {
    return makePart(n, n);
  }
};
