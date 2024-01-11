#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use bit operation
// time : O(N)
// space : O(1)
class Solution {
 private:
  string convert(int num) {
    string ret(32, '0');

    for (int i = 0; i < 32; i++) {
      if (num % 2 > 0) {
        ret[i] = '1';
      }
      num /= 2;
    }
    return ret;
  }

  int getDiff(string &a, string &b) {
    int size = a.size();
    int count = 0;
    for (int i = 0; i < size; i++) {
      if (a[i] != b[i]) {
        count++;
      }
    }
    return count;
  }

 public:
  int minOperations(vector<int> &nums, int k) {
    int bit = 0;
    for (int &num : nums) {
      bit ^= num;
    }

    string a = convert(bit), b = convert(k);

    return getDiff(a, b);
  }
};

// use bit operation
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minOperations(vector<int> &nums, int k) {
    int bit = k;
    for (int &num : nums) {
      bit ^= num;
    }

    return __builtin_popcount(bit);
  }
};