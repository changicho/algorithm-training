#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use mod
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumNumbers(int num, int k) {
    int temp = num % 10;

    if (num == 0) return 0;
    if (k == 0) {
      if (num >= 10 && num % 10 == 0) return 1;
      return -1;
    }

    while (temp <= num) {
      if (temp != 0 && temp % k == 0) {
        return temp / k;
      }

      temp += 10;
    }

    return -1;
  }
};

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  int minimumNumbers(int num, int k) {
    if (num == 0) return 0;

    int digit = num % 10;
    for (int n = 1; n <= 10; n++) {
      if ((n * k) % 10 == digit && n * k <= num) return n;
    }

    return -1;
  }
};