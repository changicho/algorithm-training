#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use convert and count
// time : O(log_2(N))
// space : O(log_2(N))
class Solution {
 private:
  string convert(int n) {
    string ret = "";
    while (n > 0) {
      ret += (n % 2) + '0';
      n /= 2;
    }
    return ret;
  }

 public:
  vector<int> evenOddBit(int n) {
    string bits = convert(n);
    int size = bits.size();
    // even, odd
    vector<int> ans = {0, 0};

    for (int i = 0; i < size; i++) {
      if (bits[i] == '1') {
        ans[i % 2]++;
      }
    }
    return ans;
  }
};

// use convert and count (space optimized)
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  vector<int> evenOddBit(int n) {
    // even, odd
    vector<int> ans = {0, 0};

    int idx = 0;

    while (n > 0) {
      if (n % 2 == 1) {
        ans[idx % 2]++;
      }
      n /= 2;
      idx++;
    }
    return ans;
  }
};