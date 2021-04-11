#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use two pointer

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int size = nums.size();

    set<vector<int>> s;

    for (int first = 0; first < size - 3; first++) {
      for (int second = first + 1; second < size - 2; second++) {
        int third = second + 1;
        int fourth = size - 1;

        int sum = nums[first] + nums[second];

        while (third < fourth) {
          int curSum = sum + nums[third] + nums[fourth];

          if (curSum == target) {
            s.insert({nums[first], nums[second], nums[third], nums[fourth]});

            third++;
            fourth--;
          } else if (curSum < target) {
            third++;
          } else {
            fourth--;
          }
        }
      }
    }

    vector<vector<int>> answers;
    for (vector<int> cur : s) {
      answers.push_back(cur);
    }
    return answers;
  }
};

// use two pointer not use set

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> answers;
    int size = nums.size();
    sort(nums.begin(), nums.end());

    for (int first = 0; first < size - 3; first++) {
      // check duplicate
      if (first > 0 && nums[first] == nums[first - 1]) continue;
      // backtracking
      if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target) break;
      if (nums[first] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target) continue;

      for (int second = first + 1; second < size - 2; second++) {
        // check duplicate
        if (second > first + 1 && nums[second] == nums[second - 1]) continue;
        // backtracking
        if (nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target) break;
        if (nums[first] + nums[second] + nums[size - 1] + nums[size - 2] < target) continue;

        int third = second + 1;
        int fourth = size - 1;

        while (third < fourth) {
          int sum = nums[first] + nums[second] + nums[third] + nums[fourth];

          if (sum == target) {
            answers.push_back({nums[first], nums[second], nums[third], nums[fourth]});

            third++;
            fourth--;
            // check duplicate
            while (third < fourth && nums[third] == nums[third - 1]) third++;
            while (third < fourth && nums[fourth] == nums[fourth + 1]) fourth--;
          } else if (sum < target) {
            third++;
          } else if (sum > target) {
            fourth--;
          }
        }
      }
    }

    return answers;
  }
};

// use hash

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> s;
    map<int, vector<pair<int, int>>> m;

    for (int first = 0; first < nums.size() - 1; first++) {
      for (int second = first + 1; second < nums.size(); second++) {
        m[nums[first] + nums[second]].push_back({first, second});
      }
    }

    for (int third = 0; third < nums.size() - 1; third++) {
      for (int fourth = third + 1; fourth < nums.size(); fourth++) {
        int sum = nums[third] + nums[fourth];

        if (m.find(target - sum) == m.end()) {
          continue;
        }

        vector<pair<int, int>> parts = m[target - sum];

        for (pair<int, int> cur : parts) {
          if (isSame({third, fourth}, cur)) break;

          if (!isSame({third, fourth}, cur)) {
            vector<int> v = {nums[cur.first], nums[cur.second], nums[third], nums[fourth]};
            sort(v.begin(), v.end());
            s.insert(v);
          }
        }
      }
    }

    vector<vector<int>> answers;
    for (vector<int> cur : s) {
      answers.push_back(cur);
    }
    return answers;
  }
  bool isSame(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first || p1.second == p2.second) {
      return true;
    }
    if (p1.first == p2.second || p2.first == p1.second) {
      return true;
    }
    return false;
  }
};
