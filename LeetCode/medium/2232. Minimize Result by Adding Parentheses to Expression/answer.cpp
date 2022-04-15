#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(L^3)
// space : O(L)
class Solution {
 public:
  string minimizeResult(string expression) {
    int target = expression.find('+');
    string num1 = expression.substr(0, target),
           num2 = expression.substr(target + 1);

    int len1 = num1.length(), len2 = num2.length();
    // O(L)
    string answer = "(" + expression + ")";
    int answerVal = stoi(num1) + stoi(num2);

    // O(L^2)
    for (int left = 0; left < len1; left++) {
      for (int right = 1; right <= len2; right++) {
        // O(L)
        string firstNum = num1.substr(0, left);
        string secondNum = num1.substr(left);
        string thirdNum = num2.substr(0, right);
        string fourthNum = num2.substr(right);

        int cur = 0;
        cur += stoi(secondNum) + stoi(thirdNum);
        if (firstNum != "") cur *= stoi(firstNum);
        if (fourthNum != "") cur *= stoi(fourthNum);

        if (cur < answerVal) {
          answerVal = cur;
          answer =
              firstNum + "(" + secondNum + "+" + thirdNum + ")" + fourthNum;
        }
      }
    }

    return answer;
  }
};