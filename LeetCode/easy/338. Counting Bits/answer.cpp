#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force

class Solution {
 private:
  int counting(int n) {
    int count = 0;
    while (n != 0) {
      count += n % 2;
      n /= 2;
    }
    return count;
  }

 public:
  vector<int> countBits(int n) {
    vector<int> bits(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      bits[i] = counting(i);
    }

    return bits;
  }
};

// use memoization

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> bits(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      bits[i] = bits[i / 2] + i % 2;
    }

    return bits;
  }
};