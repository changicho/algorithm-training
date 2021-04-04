#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int myAtoi(string s) {
    long long ret = 0;

    long long lowerLimit = -2147483648;
    long long upperLimit = 2147483647;

    bool isNumberStart = false;
    bool isPlus = false;
    bool isMinus = false;
    for (char c : s) {
      if (c == ' ') {
        if (isNumberStart || isPlus || isMinus) break;
        continue;
      }
      if (c == '.') break;
      if (c == '-' || c == '+') {
        if (isNumberStart) break;
        if (isMinus || isPlus) {
          ret = 0;
          break;
        }

        if (c == '-') {
          isMinus = true;
        } else {
          isPlus = true;
        }
        continue;
      }

      if (c >= '0' && c <= '9') {
        ret *= 10;
        if (isMinus && ret * -1 < lowerLimit) {
          ret = lowerLimit * -1;
          break;
        }
        if (ret > upperLimit) {
          ret = upperLimit;
          break;
        }
        ret += c - '0';
        isNumberStart = true;
        continue;
      }
      break;
    }

    if (isMinus) ret *= -1;

    if (ret > 0 && ret >= upperLimit) {
      ret = upperLimit;
    }
    if (ret < 0 && ret <= lowerLimit) {
      ret = lowerLimit;
    }

    return (int)ret;
  }
};

// solution

class Solution {
 public:
  int myAtoi(string str) {
    int i = 0;
    int sign = 1;
    int result = 0;
    if (str.length() == 0) return 0;

    // find biginning
    while (i < str.length() && str[i] == ' ') {
      i++;
    }

    // Check if optional sign if it exists
    if (i < str.length() && (str[i] == '+' || str[i] == '-')) {
      sign = (str[i] == '-') ? -1 : 1;
      i++;
    }

    // find number
    while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
      int cur = str[i] - '0';
      bool isOver = result > INT_MAX / 10;
      bool isFit = (result == INT_MAX / 10 && cur > INT_MAX % 10);

      if (isOver || isFit) {
        return (sign == 1) ? INT_MAX : INT_MIN;
      }
      result *= 10;
      result += cur;
      i++;
    }
    return result * sign;
  }
};