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
  double averageWaitingTime(vector<vector<int>>& customers) {
    int endTime = 0;
    long long sum = 0;
    for (vector<int>& c : customers) {
      int a = c[0], t = c[1];

      endTime = max(endTime, a);
      endTime += t;

      sum += endTime - a;
    }

    return (double)sum / customers.size();
  }
};