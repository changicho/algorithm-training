#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use binary search

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() && nums2.empty()) return 0;
    // to make nums1.size() < nums2.size()
    if (nums1.size() > nums2.size()) swap(nums1, nums2);

    int size1 = nums1.size(), size2 = nums2.size();
    int half = (size1 + size2 + 1) / 2;

    // binary search of range of nums1
    int left = 0, right = size1;
    while (left <= right) {
      int from = (left + right) / 2;
      int to = half - from;

      if (from > 0 && nums1[from - 1] > nums2[to]) {
        // move range to left
        right = from - 1;
      } else if (from < size1 && nums2[to - 1] > nums1[from]) {
        // move range to right
        left = from + 1;
      } else {
        // find leftMax, rightMin
        int leftMax, rightMin;
        if (from == 0) {
          leftMax = nums2[to - 1];
        } else if (to == 0) {
          leftMax = nums1[from - 1];
        } else {
          leftMax = max(nums1[from - 1], nums2[to - 1]);
        }

        if ((size1 + size2) % 2 == 1) return leftMax;

        if (from == size1) {
          rightMin = nums2[to];
        } else if (to == size2) {
          rightMin = nums1[from];
        } else {
          rightMin = min(nums1[from], nums2[to]);
        }

        return (double)(leftMax + rightMin) / 2;
      }
    }

    return 0.0;
  }
};

// use sort

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    for (int& num : nums2) {
      nums1.push_back(num);
    }

    sort(nums1.begin(), nums1.end());

    int size = nums1.size();
    if (size == 0) return 0;
    if (size % 2 == 1) return (double)nums1[size / 2];
    return (double)(nums1[size / 2 - 1] + nums1[size / 2]) / 2;
  }
};

// use deque (same with two pointer)

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size(), size2 = nums2.size(),
        size = nums1.size() + nums2.size();

    deque<int> dq1, dq2;

    for (int& num : nums1) {
      dq1.push_back(num);
    }
    for (int& num : nums2) {
      dq2.push_back(num);
    }

    for (int i = 0; i < (size + 1) / 2 - 1; i++) {
      if (dq1.empty()) {
        dq2.pop_front();
        continue;
      }
      if (dq2.empty()) {
        dq1.pop_front();
        continue;
      }

      if (dq1.front() < dq2.front()) {
        dq1.pop_front();
      } else {
        dq2.pop_front();
      }
    }

    for (int i = 0; i < (size + 1) / 2 - 1; i++) {
      if (dq1.empty()) {
        dq2.pop_back();
        continue;
      }
      if (dq2.empty()) {
        dq1.pop_back();
        continue;
      }

      if (dq1.back() > dq2.back()) {
        dq1.pop_back();
      } else {
        dq2.pop_back();
      }
    }

    vector<int> ret;
    while (!dq1.empty()) {
      ret.push_back(dq1.front());
      dq1.pop_front();
    }
    while (!dq2.empty()) {
      ret.push_back(dq2.front());
      dq2.pop_front();
    }

    if (ret.size() == 1) return (double)ret.front();
    return (double)(ret.front() + ret.back()) / 2;
  }
};
