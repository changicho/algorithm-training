#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ArrayReader {
 public:
  // Compares the sum of arr[l..r] with the sum of arr[x..y]
  // return 1 if sum(arr[l..r]) > sum(arr[x..y])
  // return 0 if sum(arr[l..r]) == sum(arr[x..y])
  // return -1 if sum(arr[l..r]) < sum(arr[x..y])
  int compareSub(int l, int r, int x, int y);
  // Returns the length of the array
  int length();
};

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int getIndex(ArrayReader &reader) {
    int left = 0, right = reader.length() - 1;

    int answer = -1;

    while (left <= right) {
      int size = right - left + 1;

      if (size == 1) {
        answer = left;
        break;
      }
      int mid = left + (right - left) / 2;

      if (size % 2 == 0) {
        int ret = reader.compareSub(left, mid, mid + 1, right);
        if (ret == 1) {
          // pick left
          right = mid;
        } else if (ret == -1) {
          // pick right
          left = mid + 1;
        }
      } else {
        int ret = reader.compareSub(left, mid - 1, mid + 1, right);
        if (ret == 1) {
          // pick left;
          right = mid - 1;
        } else if (ret == -1) {
          // pick right
          left = mid + 1;
        } else if (ret == 0) {
          answer = mid;
          break;
        }
      }
    }
    return answer;
  }
};