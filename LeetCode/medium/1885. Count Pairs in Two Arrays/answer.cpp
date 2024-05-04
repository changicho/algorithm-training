#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use math & two pointer
// time: O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long countPairs(vector<int>& nums1, vector<int>& nums2) {
    // i < j
    // nums1[i] - nums2[i] > nums2[j] - nums1[j]
    // nums2[i] - nums1[i] < nums1[j] - nums2[j]

    int size = nums1.size();
    vector<int> diffs;

    for (int i = 0; i < size; i++) {
      diffs.push_back(nums1[i] - nums2[i]);
    }

    sort(diffs.begin(), diffs.end());

    long long answer = 0;
    int left = 0, right = size - 1;
    while (left < right) {
      if (diffs[left] + diffs[right] > 0) {
        answer += right - left;
        right--;
      } else {
        left++;
      }
    }
    return answer;
  }
};

// use math & binary search
// time: O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long countPairs(vector<int>& nums1, vector<int>& nums2) {
    int size = nums1.size();
    vector<int> diff;

    for (int i = 0; i < size; i++) {
      diff.push_back(nums1[i] - nums2[i]);
    }

    sort(diff.begin(), diff.end());

    long long answer = 0;
    for (int i = 0; i < size; i++) {
      int cur = diff[i];

      int count =
          diff.end() - upper_bound(diff.begin() + i + 1, diff.end(), -cur);
      answer += count;
    }
    return answer;
  }
};