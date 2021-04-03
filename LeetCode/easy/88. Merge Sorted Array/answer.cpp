#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp;

    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < m || idx2 < n) {
      if (idx1 >= m) {
        temp.push_back(nums2[idx2]);
        idx2++;
        continue;
      }
      if (idx2 >= n) {
        temp.push_back(nums1[idx1]);
        idx1++;
        continue;
      }

      if (nums1[idx1] < nums2[idx2]) {
        temp.push_back(nums1[idx1]);
        idx1++;
        continue;
      }
      temp.push_back(nums2[idx2]);
      idx2++;
      continue;
    }

    nums1 = temp;
  }
};

// use STL

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    nums1.resize(m);

    vector<int> res(m + n);

    std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), res.begin());

    nums1 = res;
  }
};

// order from back

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1;
    // order from back
    while (i >= 0 && j >= 0) {
      int k = i + j + 1;

      if (nums1[i] > nums2[j]) {
        nums1[k] = nums1[i];
        i -= 1;
      } else {
        nums1[k] = nums2[j];
        j -= 1;
      }
    }

    if (i == -1) {
      for (int k = 0; k <= j; k++) {
        nums1[k] = nums2[k];
      }
    }
  }
};