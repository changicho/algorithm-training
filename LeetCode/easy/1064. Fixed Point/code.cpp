#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int fixedPoint(vector<int>& arr) {
    int size = arr.size();

    int left = 0, right = size;
    int answer = INT_MAX;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] == mid) {
        answer = min(answer, mid);
      }
      if (arr[mid] < mid) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return answer == INT_MAX ? -1 : answer;
  }
};