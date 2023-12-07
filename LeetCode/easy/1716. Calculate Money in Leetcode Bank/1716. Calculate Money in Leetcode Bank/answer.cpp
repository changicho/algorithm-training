#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(log_7(n))
// space : O(1)
class Solution {
 public:
  int totalMoney(int n) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
      answer += (i % 7) + 1;
      answer += i / 7;
    }
    return answer;
  }
};

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  int totalMoney(int n) {
    int k = n / 7;
    int F = 28;
    int L = 28 + (k - 1) * 7;
    int arithmeticSum = k * (F + L) / 2;

    int monday = 1 + k;
    int finalWeek = 0;
    for (int day = 0; day < n % 7; day++) {
      finalWeek += monday + day;
    }

    return arithmeticSum + finalWeek;
  }
};