#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use two pointer with hash set
// time : O(N^3)
// space : O(N)
class Solution {
 private:
  struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
      std::hash<int> hasher;
      size_t seed = 0;
      for (int i : v) {
        seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
      return seed;
    }
  };

 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int size = nums.size();

    unordered_set<vector<int>, VectorHash> hashSet;

    for (int idx1 = 0; idx1 < size - 3; idx1++) {
      // check duplicate
      if (idx1 > 0 && nums[idx1] == nums[idx1 - 1]) continue;

      for (int idx2 = idx1 + 1; idx2 < size - 2; idx2++) {
        // check duplicate
        if (idx2 > idx1 + 1 && nums[idx2] == nums[idx2 - 1]) continue;
        int idx3 = idx2 + 1, idx4 = size - 1;
        long leftPart = nums[idx1] + nums[idx2];

        while (idx3 < idx4) {
          long curSum = leftPart + nums[idx3] + nums[idx4];

          if (curSum == target) {
            vector<int> cur = {nums[idx1], nums[idx2], nums[idx3], nums[idx4]};
            hashSet.insert(cur);

            idx3++, idx4--;
            while (idx3 < idx4 && nums[idx3] == nums[idx3 - 1]) idx3++;
            while (idx3 < idx4 && nums[idx4] == nums[idx4 + 1]) idx4--;
          } else if (curSum < target) {
            idx3++;
          } else {
            idx4--;
          }
        }
      }
    }

    vector<vector<int>> answers;
    for (vector<int> cur : hashSet) {
      answers.push_back(cur);
    }
    return answers;
  }
};

// use two pointer
// time : O(N^3)
// space : O(1)
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> answers;
    int size = nums.size();
    sort(nums.begin(), nums.end());

    for (int idx1 = 0; idx1 < size - 3; idx1++) {
      // check duplicate
      if (idx1 > 0 && nums[idx1] == nums[idx1 - 1]) continue;
      // backtracking
      if ((long)nums[idx1] + nums[idx1 + 1] + nums[idx1 + 2] + nums[idx1 + 3] >
          target)
        break;
      if ((long)nums[idx1] + nums[size - 1] + nums[size - 2] + nums[size - 3] <
          target)
        continue;

      for (int idx2 = idx1 + 1; idx2 < size - 2; idx2++) {
        // check duplicate
        if (idx2 > idx1 + 1 && nums[idx2] == nums[idx2 - 1]) continue;
        long leftPart = nums[idx1] + nums[idx2];
        // backtracking
        if (leftPart + nums[idx2 + 1] + nums[idx2 + 2] > target) break;
        if (leftPart + nums[size - 1] + nums[size - 2] < target) continue;

        int idx3 = idx2 + 1;
        int idx4 = size - 1;

        while (idx3 < idx4) {
          long sum = leftPart + nums[idx3] + nums[idx4];

          if (sum == target) {
            answers.push_back({nums[idx1], nums[idx2], nums[idx3], nums[idx4]});

            idx3++, idx4--;
            // check duplicate
            while (idx3 < idx4 && nums[idx3] == nums[idx3 - 1]) idx3++;
            while (idx3 < idx4 && nums[idx4] == nums[idx4 + 1]) idx4--;
          } else if (sum < target) {
            idx3++;
          } else if (sum > target) {
            idx4--;
          }
        }
      }
    }

    return answers;
  }
};

// use hash (TLE)

class Solution {
 private:
  struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
      std::hash<int> hasher;
      size_t seed = 0;
      for (int i : v) {
        seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
      return seed;
    }
  };

  unordered_set<vector<int>, VectorHash> uniqueSums;
  unordered_map<long, vector<pair<int, int>>> twoSums;

  void makePairs(vector<pair<int, int>>& arr1, vector<pair<int, int>>& arr2,
                 vector<int>& nums) {
    for (auto [idx1, idx2] : arr1) {
      for (auto [idx3, idx4] : arr2) {
        if (idx1 == idx3 || idx1 == idx4 || idx2 == idx3 || idx2 == idx4)
          continue;

        vector<int> temp = {nums[idx1], nums[idx2], nums[idx3], nums[idx4]};
        sort(temp.begin(), temp.end());

        uniqueSums.insert(temp);
      }
    }
  }

 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int size = nums.size();

    for (int idx1 = 0; idx1 < size; idx1++) {
      for (int idx2 = idx1 + 1; idx2 < size; idx2++) {
        twoSums[nums[idx1] + nums[idx2]].push_back({idx1, idx2});
      }
    }

    for (auto [key, value] : twoSums) {
      long other = target - key;

      if (twoSums.find(other) != twoSums.end()) {
        makePairs(twoSums[key], twoSums[other], nums);
      }
    }

    vector<vector<int>> answer;
    for (vector<int> sum : uniqueSums) {
      answer.push_back(sum);
    }
    return answer;
  }
};