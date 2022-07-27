#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O((N + M)log_2(K))
// space : O(1)
class Solution {
 private:
  bool isPossible(vector<int>& houses, vector<int>& heaters, int radius) {
    int n = houses.size(), m = heaters.size();
    int i = 0, j = 0;
    // use two pointer
    while (i < n && j < m) {
      int left = heaters[j] - radius, right = heaters[j] + radius;

      if (left <= houses[i] && houses[i] <= right) {
        i++;
      } else {
        j++;
      }
    }

    if (j == m) return false;
    return true;
  }

 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int answer = max(houses.back(), heaters.back()) + 1;
    int left = 0, right = max(houses.back(), heaters.back()) + 1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (isPossible(houses, heaters, mid)) {
        // pick left part
        answer = mid;
        right = mid;
      } else {
        // pick right part
        left = mid + 1;
      }
    }

    return answer;
  }
};