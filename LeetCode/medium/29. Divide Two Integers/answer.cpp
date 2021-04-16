#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use recursion

class Solution {
 public:
  long long answer = 0;
  int divide(int dividend, int divisor) {
    bool isMinus = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? false : true;
    long long de = abs((long long)dividend);
    long long ds = abs((long long)divisor);

    recursive(de, ds, 1, ds);

    if (isMinus) answer *= -1;
    if (answer > 2147483647) answer = 2147483647;

    return answer;
  }

  void recursive(long long num, long long div, long long count, long long divisor) {
    if (num <= 0) return;
    if (num < div) return;
    if (num > div * 2) {
      recursive(num, div * 2, count * 2, divisor);
      return;
    }

    answer += count;

    recursive(num - div, divisor, 1, divisor);
  }
};

// use iterator

class Solution {
 public:
  int divide(int dividend, int divisor) {
    bool isMinus = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? false : true;
    long long answer = 0;
    long long de = abs((long long)dividend);
    long long ds = abs((long long)divisor);

    while (de >= ds) {
      long long div = ds;
      long long count = 1;
      while ((div * 2) <= de) {
        div *= 2;
        count *= 2;
      }
      answer += count;
      de -= div;
    }

    if (isMinus) answer *= -1;
    return answer > INT_MAX ? INT_MAX : answer;
  }
};