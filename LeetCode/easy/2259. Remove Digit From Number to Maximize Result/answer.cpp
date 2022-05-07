#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  string removeDigit(string number, char digit) {
    int length = number.length();

    string maximum = "";

    for (int i = 0; i < length; i++) {
      if (number[i] != digit) continue;
      string curStr = number;
      curStr.erase(i, 1);

      if (curStr > maximum) {
        maximum = curStr;
      }
    }

    return maximum;
  }
};

// use check last digit
// time : O(N)
// space : O(N)
class Solution {
 public:
  string removeDigit(string number, char digit) {
    int length = number.length();
    int target = number.rfind(digit);

    for (int i = 0; i < length - 1; i++) {
      if (number[i] != digit || number[i + 1] <= digit) continue;

      target = i;
      break;
    }

    number.erase(target, 1);
    return number;
  }
};
// number[length] : '\n'