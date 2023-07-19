#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(2^N)
// space : O(N)
class Solution {
 private:
  int answer = INT_MAX;
  string s;
  int size;

  int convert(string s) {
    int num = 0;
    reverse(s.begin(), s.end());
    int digit = 1;
    for (char &c : s) {
      if (c == '1') {
        num += digit;
      }
      digit *= 2;
    }
    return num;
  }

  bool checkFivePow(int num) {
    while (num > 1) {
      if (num % 5 != 0) return false;
      num /= 5;
    }
    return true;
  }

  bool isValid(string s) {
    if (s[0] == '0') return false;
    int num = convert(s);

    return checkFivePow(num);
  }

  void recursive(int index, int count, string cur) {
    if (index == size) {
      if (cur == "") {
        answer = min(answer, count);
      }
      return;
    }

    cur += s[index];

    if (cur[0] == '0') return;
    // cut case
    if (isValid(cur)) {
      recursive(index + 1, count + 1, "");
    }

    // not cut case
    recursive(index + 1, count, cur);
  }

 public:
  int minimumBeautifulSubstrings(string s) {
    this->s = s;
    this->size = s.size();

    recursive(0, 0, "");

    if (answer == INT_MAX) return -1;
    return answer;
  }
};

// use dynamic programming
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  const int MAX = 10000;

 public:
  int minimumBeautifulSubstrings(string s) {
    int size = s.size();

    vector<int> dp(size + 1, MAX);
    dp[0] = 0;

    for (int i = 0; i < size; i++) {
      if (s[i] == '0') continue;

      for (int j = i, cur = 0; j < size; j++) {
        cur = cur * 2 + s[j] - '0';

        // 15625 is the biggest pow of 5 with 15 bits.
        if (15625 % cur == 0) {
          dp[j + 1] = min(dp[j + 1], dp[i] + 1);
        }
      }
    }
    return dp[size] == MAX ? -1 : dp[size];
  }
};