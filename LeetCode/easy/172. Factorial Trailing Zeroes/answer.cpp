#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use count fives

class Solution {
 public:
  int trailingZeroes(int n) {
    int answer = 0;

    vector<int> fives;
    for (int five = 5; five <= 10000; five *= 5) {
      fives.push_back(five);
    }

    for (int num = 1; num <= n; num++) {
      for (int five : fives) {
        if (num % five == 0) answer += 1;
      }
    }

    return answer;
  }
};

// use five counts more compact

class Solution {
 public:
  int trailingZeroes(int n) {
    int answer = 0;
    for (long long five = 5; n / five > 0; five *= 5) {
      answer += (n / five);
    }
    return answer;
  }
};

// use while

class Solution {
 public:
  int trailingZeroes(int n) {
    int answer = 0;
    while (n / 5 > 0) {
      int tmp = n / 5;
      answer += tmp;
      n = tmp;
    }
    return answer;
  }
};