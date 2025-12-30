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

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    int size = calories.size();
    int sum = 0;

    for (int i = 0; i < k - 1; i++) {
      sum += calories[i];
    }

    int answer = 0;
    for (int i = k - 1; i < size; i++) {
      sum += calories[i];

      if (i - k >= 0) {
        sum -= calories[i - k];
      }

      if (sum < lower) {
        answer--;
      } else if (sum > upper) {
        answer++;
      }
    }
    return answer;
  }
};