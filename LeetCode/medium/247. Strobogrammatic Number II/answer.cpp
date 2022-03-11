#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use half backtracking (refactor)
// time : O(N * 5^(N/2))
// space : O(N * 5^(N/2))
class Solution {
 private:
  unordered_map<char, char> table = {
      {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
  vector<char> digits = {'0', '1', '6', '8', '9'};

  // O(N)
  string getReverse(string half, int n) {
    int length = half.length(), center = n / 2;

    for (int i = 0; i < center; i++) {
      char c = half[center - 1 - i];
      half += table[c];
    }
    return half;
  }

 public:
  vector<string> findStrobogrammatic(int n) {
    queue<string> q;
    q.push("");

    // O(N)
    for (int i = 0; i < n / 2; i++) {
      int size = q.size();
      // O(N^(N / 2))
      while (size--) {
        string before = q.front();
        q.pop();

        for (char &digit : digits) {
          string num = before + digit;

          if (num[0] == '0') continue;
          q.push(num);
        }
      }
    }

    vector<string> answer;
    while (!q.empty()) {
      string num = q.front();
      q.pop();

      if (n % 2 == 1) {
        for (char c : {'0', '1', '8'}) {
          answer.emplace_back(getReverse(num + c, n));
        }
      } else {
        answer.emplace_back(getReverse(num, n));
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
  vector<string> findStrobogrammatic(int n) { return makePart(n, n); }
};
