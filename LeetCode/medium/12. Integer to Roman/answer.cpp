#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    string answer = "";
    char table[1001];

    table[1] = 'I';
    table[5] = 'V';
    table[10] = 'X';
    table[50] = 'L';
    table[100] = 'C';
    table[500] = 'D';
    table[1000] = 'M';

    for (int digit = 1000; digit > 0; digit /= 10) {
      if (num >= digit) {
        int count = num / digit;
        num %= digit;

        if (count > 8) {
          for (int i = 0; i < 10 - count; i++) {
            answer += table[digit];
          }
          answer += table[digit * 10];
        } else if (count > 5) {
          answer += table[digit * 5];
          for (int i = 0; i < count - 5; i++) {
            answer += table[digit];
          }
        } else if (count > 3) {
          for (int i = 0; i < 5 - count; i++) {
            answer += table[digit];
          }
          answer += table[digit * 5];
        } else if (count > 0) {
          for (int i = 0; i < count; i++) {
            answer += table[digit];
          }
        }
      }
    }

    return answer;
  }
};

// use checking all available case

class Solution {
 public:
  string intToRoman(int num) {
    string romans[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int numerals[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    string answer = "";
    for (int i = 12; i >= 0; i--) {
      int count = num / numerals[i];

      if (count > 0) {
        while (count--) {
          answer += romans[i];
        }

        num %= numerals[i];
      }
    }
    return answer;
  }
};