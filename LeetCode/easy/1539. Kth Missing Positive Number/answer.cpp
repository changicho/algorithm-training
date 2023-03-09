#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointer
// time : O(N + K)
// space : O(1)
class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int num = 1;

    int index = 0;
    while (k > 0) {
      if (index < arr.size() && arr[index] == num) {
        num++;
        index++;

        continue;
      }
      num++;
      k--;
    }
    return num - 1;
  }
};

// use iteration
// time : O(N)
// space : O(1)
class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int size = arr.size();
    if (k < arr[0]) {
      return k;
    }

    k -= arr[0] - 1;
    for (int i = 0; i < size - 1; ++i) {
      int diff = arr[i + 1] - arr[i] - 1;

      if (k <= diff) {
        return arr[i] + k;
      }
      k -= diff;
    }

    return arr[size - 1] + k;
  }
};

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int size = arr.size();
    int left = 0, right = size - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] - mid - 1 < k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return left + k;
  }
};