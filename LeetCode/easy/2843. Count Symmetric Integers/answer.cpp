#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N * log_10(N))
// space : O(log_10(N))
class Solution {
 private:
  bool isSymmetric(int number) {
    string num = to_string(number);
    int size = num.size();
    if (size % 2 == 1) return false;

    int left = 0, right = 0;
    for (int i = 0; i < size / 2; i++) {
      left += num[i];
      right += num[size / 2 + i];
    }
    return left == right;
  }

 public:
  int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for (int i = low; i <= high; i++) {
      if (isSymmetric(i)) count++;
    }
    return count;
  }
};