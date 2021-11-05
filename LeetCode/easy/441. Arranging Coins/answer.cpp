#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation

class Solution {
 public:
  int arrangeCoins(int n) {
    int level = 1;
    int temp = n;

    while (temp >= level) {
      temp -= level;
      level++;
    }

    if (temp < level) {
      level -= 1;
    }

    return level;
  }
};

// use binary search

class Solution {
 private:
  long getSum(int n) {
    return ((long)n * ((long)n + 1) / 2);
  }

 public:
  int arrangeCoins(int n) {
    int left = 0, right = n;

    int answer = 0;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (getSum(mid) > (long)n) {
        right = mid - 1;
      } else {
        answer = mid;
        left = mid + 1;
      }
    }

    return answer;
  }
};

// use math

class Solution {
 public:
  int arrangeCoins(int n) {
    return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
  }
};