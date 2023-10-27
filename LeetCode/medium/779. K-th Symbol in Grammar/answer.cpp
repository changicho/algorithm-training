#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use divide and conquer
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool recursive(int left, int right, int target, bool flag) {
    if (left == right) return flag;

    int center = left + (right - left) / 2;

    // left ~ center, center+1 ~ right
    if (target <= center) {
      return recursive(left, center, target, flag);
    }
    return recursive(center + 1, right, target, !flag);
  }

 public:
  int kthGrammar(int n, int k) {
    int length = pow(2, n - 1);

    return recursive(0, length - 1, k - 1, false);
  }
};

// use divide and conquer (iteration)
// time : O(N)
// space : O(1)
class Solution {
 public:
  int kthGrammar(int n, int k) {
    int length = pow(2, n - 1);
    bool flag = false;

    int left = 0, right = length - 1;
    k--;

    while (left != right) {
      int center = left + (right - left) / 2;

      if (k <= center) {
        right = center;
        flag = flag;
      } else {
        left = center + 1;
        flag = !flag;
      }
    }

    return flag;
  }
};