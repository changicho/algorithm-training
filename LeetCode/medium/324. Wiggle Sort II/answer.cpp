#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort

class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());
    vector<int> answer(size);

    int cur = size - 1;
    // odd
    for (int i = 1; i < size; i += 2) {
      answer[i] = nums[cur];
      cur--;
    }
    // even
    for (int i = 0; i < size; i += 2) {
      answer[i] = nums[cur];
      cur--;
    }

    nums = answer;
  }
};

// use three-way partitioning

class Solution {
 private:
  int getNextIdx(int index, int size) { return (2 * index + 1) % (size | 1); }

 public:
  void wiggleSort(vector<int>& nums) {
    int size = nums.size();

    // sort 0 ~ mid
    nth_element(nums.begin(), nums.begin() + size / 2, nums.end());

    int median = nums[size / 2];
    int left = 0, right = size - 1;
    int mid = 0;

    while (mid <= right) {
      int leftIdx = getNextIdx(left, size);
      int midIdx = getNextIdx(mid, size);
      int rightIdx = getNextIdx(right, size);

      if (nums[midIdx] > median) {
        swap(nums[leftIdx], nums[midIdx]);

        ++left;
        ++mid;
      } else if (nums[midIdx] < median) {
        swap(nums[midIdx], nums[rightIdx]);

        --right;
      } else {
        ++mid;
      }
    }
  }
};