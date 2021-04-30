#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    int length1 = num1.length();
    int length2 = num2.length();
    string answer(length1 + length2, '0');

    for (int first = length1 - 1; first >= 0; first--) {
      for (int second = length2 - 1; second >= 0; second--) {
        int cur = (num1[first] - '0') * (num2[second] - '0') + (answer[first + second + 1] - '0');

        answer[first + second + 1] = cur % 10 + '0';
        answer[first + second] += cur / 10;
      }
    }
    for (int i = 0; i < length2 + length1; i++) {
      if (answer[i] != '0') return answer.substr(i);
    }
    return "0";
  }
};