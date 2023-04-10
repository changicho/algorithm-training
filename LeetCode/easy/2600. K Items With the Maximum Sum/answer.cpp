#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(1)
// space : O(1)
class Solution {
 public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int sum = 0;
    if (numOnes >= k) {
      return k;
    }
    sum += numOnes;
    k -= numOnes;
    if (numZeros >= k) {
      return sum;
    }
    k -= numZeros;
    return sum - k;
  }
};