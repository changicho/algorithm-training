#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MountainArray {
 public:
  int get(int index);
  int length();
};

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 private:
  int findPeak(MountainArray &mountainArr) {
    int size = mountainArr.length();

    int left = 1, right = size - 1;
    int ret = 0;
    while (left < right) {
      int mid = left + (right - left) / 2;

      int val = mountainArr.get(mid);
      int prev = mountainArr.get(mid - 1);
      int next = mountainArr.get(mid + 1);

      if (prev < val && val > next) {
        ret = mid;
        break;
      }
      if (prev < val) {
        // pick right
        left = mid + 1;
      } else if (val > next) {
        // pick left
        right = mid;
      }
    }
    return ret;
  }

 public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int size = mountainArr.length();

    int peak = findPeak(mountainArr);
    int answer = INT_MAX;

    int left, right;
    // leftPart
    left = 0, right = peak + 1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      int val = mountainArr.get(mid);
      if (val < target) {
        // pick right
        left = mid + 1;
      } else if (val > target) {
        // pick left
        right = mid;
      } else {
        answer = min(answer, mid);
        break;
      }
    }

    // right part
    left = peak, right = size;
    while (left < right) {
      int mid = left + (right - left) / 2;

      int val = mountainArr.get(mid);
      if (val > target) {
        // pick right
        left = mid + 1;
      } else if (val < target) {
        // pick left
        right = mid;
      } else {
        answer = min(answer, mid);
        break;
      }
    }
    if (answer == INT_MAX) return -1;
    return answer;
  }
};