#include <algorithm>
#include <iostream>
#include <numeric>  // for accumulate
#include <string>
#include <vector>

using namespace std;

// use kadane algorithm
// time : O(N)
// space : O(1)
class Solution {
 private:
  int kadane(vector<int>& n1, vector<int>& n2) {
    int size = n1.size();
    int sum = 0, res = 0;

    for (int i = 0; i < size; i++) {
      sum = max(n2[i] - n1[i], sum + n2[i] - n1[i]);
      res = max(res, sum);
    }

    return res;
  }

 public:
  int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
    int sum1 = accumulate(begin(n1), end(n1), 0);
    int sum2 = accumulate(begin(n2), end(n2), 0);

    return max(sum1 + kadane(n1, n2), sum2 + kadane(n2, n1));
  }
};