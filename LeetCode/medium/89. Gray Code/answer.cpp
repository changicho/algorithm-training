#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use convert to grayCode

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> answer;
    int limit = 1 << n;
    for (int number = 0; number < limit; number++) {
      answer.push_back(number ^ (number >> 1));
    }
    return answer;
  }
};

// use recursive

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> answer;
    recursive(answer, 0, n, 0, 0);
    return answer;
  }

  void recursive(vector<int> &array, int number, int n, int index, int reverse) {
    if (index == n) {
      array.push_back(number);
      return;
    }

    if (reverse == 1)
      number |= 1 << index;
    else
      number &= ~(1 << index);
    recursive(array, number, n, index + 1, 0);

    if (reverse == 1)
      number &= ~(1 << index);
    else
      number |= 1 << index;
    recursive(array, number, n, index + 1, 1);
  }
};

// use recursive to reverse

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> answer;
    grayCode(answer, 0, n, 0);
    return answer;
  }

  void grayCode(vector<int> &array, int number, int n, int index) {
    if (index == n) {
      array.push_back(number);
      return;
    }

    number &= ~(1 << index);
    grayCode(array, number, n, index + 1);

    number |= 1 << index;
    reverseGrayCode(array, number, n, index + 1);
  }

  void reverseGrayCode(vector<int> &array, int number, int n, int index) {
    if (index == n) {
      array.push_back(number);
      return;
    }

    number |= 1 << index;
    grayCode(array, number, n, index + 1);

    number &= ~(1 << index);
    reverseGrayCode(array, number, n, index + 1);
  }
};