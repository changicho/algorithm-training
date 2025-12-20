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

// use one pass
// time ; O(N)
// space : O(1)
class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    long long answer = 0;

    long long count = 0;
    int before = INT_MAX;
    for (int& p : prices) {
      if (before - 1 == p) {
        count++;
      } else {
        answer += (count + 1) * (count) / 2;
        count = 1;
      }
      before = p;
    }
    answer += (count + 1) * (count) / 2;
    return answer;
  }
};