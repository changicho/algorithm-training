#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string answer = "";
    if (a.length() > b.length()) swap(a, b);

    bool carry = false;

    for (int i = 0; i < a.length(); i++) {
      int count = (a[i] - '0') + (b[i] - '0') + carry;

      if (count >= 2) {
        count -= 2;
        carry = true;
      } else {
        carry = false;
      }

      answer += count == 0 ? '0' : '1';
    }

    for (int i = a.length(); i < b.length(); i++) {
      int count = (b[i] - '0') + carry;

      if (count >= 2) {
        count -= 2;
        carry = true;
      } else {
        carry = false;
      }

      answer += count == 0 ? '0' : '1';
    }

    if (carry) {
      answer += '1';
    }

    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// simple one iteration

class Solution {
 public:
  string addBinary(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string ret = "";
    while (i >= 0 || j >= 0 || carry != 0) {
      if (i >= 0) {
        carry += a[i] - '0';
        i--;
      }
      if (j >= 0) {
        carry += b[j] - '0';
        j--;
      }
      ret += ((carry % 2) == 0 ? "0" : "1");
      carry /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};