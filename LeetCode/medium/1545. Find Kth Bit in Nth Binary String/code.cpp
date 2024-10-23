#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use simulation
// time : O(N * K)
// space : O(K)
class Solution {
 private:
  string convert(string &cur, int leftSize) {
    int size = cur.size();
    string ret = "";
    for (int i = size - 1; i >= 0; i--) {
      ret += cur[i] == '1' ? '0' : '1';
      if (ret.size() == leftSize) break;
    }
    return ret;
  }

  string getNext(string &cur, int k) {
    if (cur.size() > k) {
      return cur;
    }

    string ret = "1";
    int leftSize = k - ret.size();

    return ret + convert(cur, leftSize);
  }

 public:
  char findKthBit(int n, int k) {
    char ret = '0';

    string cur = "0";

    for (int i = 0; i < n; i++) {
      cur += getNext(cur, k);
    }
    return cur[k - 1];
  }
};

// use divide and conquer
// time : O(N)
// space : O(1)
class Solution {
 public:
  char findKthBit(int n, int k) {
    bool isInverted = false;
    int length = (1 << n) - 1;

    while (k > 1) {
      if (k == length / 2 + 1) {
        return isInverted ? '0' : '1';
      }

      if (k > length / 2) {
        k = length + 1 - k;
        isInverted = !isInverted;
      }

      length /= 2;
    }
    return isInverted ? '1' : '0';
  }
};