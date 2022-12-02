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