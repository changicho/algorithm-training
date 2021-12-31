#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use math

class Solution {
 public:
  int countDigitOne(int n) {
    int answer = 0;

    for (long long digit = 1; digit <= n; digit *= 10) {
      long long divider = digit * 10;

      int curPartCount = (n / divider) * digit;
      int leftPartCount =
          min(max(n % divider - digit + 1, (long long)0), digit);

      answer += curPartCount + leftPartCount;
    }

    return answer;
  }
};

// use recursion

class Solution {
 private:
  // count of 9, 99, 999, 999, ... fill only 9 number's length
  vector<int> memoization = {
      0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000,
  };

 public:
  int countDigitOne(int n) {
    if (n < 1) return 0;
    if (n >= 1 && n < 10) return 1;

    int divider = 1, firstDigit = n;
    int length = 0;
    while (firstDigit >= 10) {
      firstDigit /= 10;
      divider *= 10;
      length++;
    }

    // count of 0 <= ~ < divider count. (0 ~ 999...)
    int dividerCount = firstDigit * memoization[length];
    // most left 1 count
    int firstCount = firstDigit == 1 ? n - divider + 1 : divider;
    // last part count
    int lastCount = countDigitOne(n % divider);

    return firstCount + dividerCount + lastCount;
  }
};