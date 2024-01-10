#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(1)
class Solution {
 public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int area = 0;
    int diagonal = 0;

    for (vector<int>& d : dimensions) {
      int a = d[0], b = d[1];
      int cur = a * a + b * b;

      if (diagonal < cur) {
        area = a * b;
        diagonal = cur;
      } else if (diagonal == cur) {
        area = max(area, a * b);
      }
    }

    return area;
  }
};