#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use counting sort
// time : O(N + M)
// space : O(M)
class Solution {
 private:
  int DIFF = 5 * 1e4;

 public:
  vector<int> sortArray(vector<int> &nums) {
    int counts[1000001] = {
        0,
    };
    for (int &num : nums) {
      counts[num + DIFF]++;
    }

    int index = 0;
    for (int num = 0; num <= 1e5; num++) {
      for (int j = 0; j < counts[num]; j++) {
        nums[index++] = num - DIFF;
      }
    }
    return nums;
  }
};

// use merge sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  vector<int> temp;

  void merge(vector<int> &arr, int left, int mid, int right) {
    int size1 = mid - left + 1, size2 = right - mid;
    int start1 = left, start2 = mid + 1;

    // Copy elements of both halves into a temporary array.
    for (int i = 0; i < size1; i++) {
      temp[start1 + i] = arr[start1 + i];
    }
    for (int i = 0; i < size2; i++) {
      temp[start2 + i] = arr[start2 + i];
    }

    int idx1 = 0, idx2 = 0, target = left;
    while (idx1 < size1 && idx2 < size2) {
      if (temp[start1 + idx1] <= temp[start2 + idx2]) {
        arr[target] = temp[start1 + idx1];
        idx1++;
      } else {
        arr[target] = temp[start2 + idx2];
        idx2++;
      }
      target++;
    }

    while (idx1 < size1) {
      arr[target] = temp[start1 + idx1];
      idx1 += 1;
      target += 1;
    }
    while (idx2 < size2) {
      arr[target] = temp[start2 + idx2];
      idx2 += 1;
      target += 1;
    }
  }

  void recursive(vector<int> &arr, int left, int right) {
    if (left >= right) {
      return;
    }
    int mid = (left + right) / 2;

    recursive(arr, left, mid);
    recursive(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }

 public:
  vector<int> sortArray(vector<int> &nums) {
    int size = nums.size();
    temp.resize(size);

    recursive(nums, 0, size - 1);

    return nums;
  }
};