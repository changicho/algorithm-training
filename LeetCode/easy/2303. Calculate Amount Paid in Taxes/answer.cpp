#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  double calculateTax(vector<vector<int>>& brackets, int income) {
    int size = brackets.size();

    double tax = 0, before = 0;
    for (int i = 0; i < size; i++) {
      double curTax =
          (min(brackets[i][0], income) - before) * brackets[i][1] / 100.0;

      tax += max(0.0, curTax);
      before = brackets[i][0];
    }

    return tax;
  }
};