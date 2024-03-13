#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  int pivotInteger(int n) {
    vector<int> suffixArray(n + 1);
    for (int i = 1; i <= n; i++) {
      suffixArray[i] = suffixArray[i - 1] + i;
    }

    for (int i = 1; i <= n; i++) {
      if (suffixArray[i] == (suffixArray[n] - suffixArray[i - 1])) {
        return i;
      }
    }
    return -1;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int pivotInteger(int n) {
    int leftSum = 0, rightSum = (n + 1) * n / 2;

    for (int i = 1; i <= n; i++) {
      leftSum += i;
      if (leftSum == rightSum - leftSum + i) {
        return i;
      }
    }
    return -1;
  }
};

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int pivotInteger(int n) {
    int left = 1, right = n;
    int sum = n * (n + 1) / 2;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (mid * mid - sum < 0) {
        // pick right part
        left = mid + 1;
      } else {
        // pick left part
        right = mid;
      }
    }

    if (left * left == sum) {
      return left;
    }

    return -1;
  }
};