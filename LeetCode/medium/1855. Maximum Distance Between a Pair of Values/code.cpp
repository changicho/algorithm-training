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

// binary search
// time : O(N * log_2(M))
// space : O(1)
class Solution {
 public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size(), size2 = nums2.size();

    int answer = 0;
    for (int i = 0; i < size1; i++) {
      int left = i, right = size2;
      int cur = -1;
      while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums1[i] <= nums2[mid]) {
          // pick right
          cur = mid;
          left = mid + 1;
        } else {
          // pick left
          right = mid;
        }
      }

      if (cur == -1) continue;

      answer = max(answer, cur - i);
    }
    return answer;
  }
};