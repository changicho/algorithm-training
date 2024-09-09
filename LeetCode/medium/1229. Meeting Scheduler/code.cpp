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

// use sort & two pointer
// time : O(N * log_2(N) + M * log_2(M))
// space : O(N + M)
class Solution {
 private:
  int getIntersect(vector<int>& a, vector<int>& b) {
    if (a[1] < b[0] || b[1] < a[0]) return 0;

    return min(a[1], b[1]) - max(a[0], b[0]);
  }

 public:
  vector<int> minAvailableDuration(vector<vector<int>>& slots1,
                                   vector<vector<int>>& slots2, int duration) {
    int size1 = slots1.size(), size2 = slots2.size();
    int i1 = 0, i2 = 0;

    sort(slots1.begin(), slots1.end());
    sort(slots2.begin(), slots2.end());

    while (i1 < size1 && i2 < size2) {
      int intersect = getIntersect(slots1[i1], slots2[i2]);

      if (intersect >= duration) {
        int left = max(slots1[i1][0], slots2[i2][0]);
        return {left, left + duration};
        break;
      }

      if (slots1[i1][1] < slots2[i2][1]) {
        i1++;
      } else if (slots2[i2][1] < slots1[i1][1]) {
        i2++;
      } else {
        i1++;
        i2++;
      }
    }
    return {};
  }
};