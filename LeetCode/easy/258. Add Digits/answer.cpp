#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use mod

class Solution {
 public:
  int addDigits(int num) {
    while (num >= 10) {
      int newNum = 0;
      while (num > 0) {
        newNum += num % 10;
        num /= 10;
      }
      num = newNum;
    }
    return num;
  }
};

// use math

class Solution {
 public:
  int addDigits(int num) {
    if (num == 0) return 0;
    if (num % 9 == 0) return 9;

    return num % 9;
  }
};