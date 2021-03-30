#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    int start = 0;
    int end = 46341;

    while (start + 1 < end) {
      int mid = (start + end) / 2;
      int cur = mid * mid;

      if (cur > x) {
        end = mid;
      } else {
        start = mid;
      }
    }

    return start;
  }
};

// use STL

class Solution {
 public:
  int mySqrt(int x) {
    int answer = (int)sqrt(x);

    return answer;
  }
};