#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use brute force

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    vector<int> answer = {0, 0};
    vector<pair<int, int>> array;

    for (int i = 0; i < size; i++) {
      array.push_back({nums[i], i});
    }

    sort(array.begin(), array.end());

    for (int i = 0; i < size; i++) {
      pair<int, int> cur = array[i];

      int value = cur.first;

      int left = i + 1, right = size;

      while (left < right) {
        int mid = left + (right - left) / 2;

        // lower case
        if (array[mid].first < target - value) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      if (left >= size) continue;

      if (array[left].first + value == target) {
        answer = {cur.second, array[left].second};
        break;
      }
    }

    return answer;
  }
};

// use binary search

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    vector<int> answer = {0, 0};
    vector<pair<int, int>> array;

    for (int i = 0; i < size; i++) {
      array.push_back({nums[i], i});
    }

    sort(array.begin(), array.end());

    for (int i = 0; i < size; i++) {
      pair<int, int> cur = array[i];

      int value = cur.first;

      int left = i + 1, right = size;

      while (left < right) {
        int mid = left + (right - left) / 2;

        // lower case
        if (array[mid].first < target - value) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      if (left >= size) continue;

      if (array[left].first + value == target) {
        answer = {cur.second, array[left].second};
        break;
      }
    }

    return answer;
  }
};

// use hash map

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    vector<int> answer = {0, 0};
    // hash_map<int, int> key : value of nums, value : index fo value of nums
    unordered_map<int, int> valueToIndex;

    for (int i = 0; i < size; i++) {
      // int first = nums[index];
      // int second = target - first
      // first + second = target
      int first = nums[i];
      int second = target - first;

      // if there are second in hash map
      if (valueToIndex.find(second) != valueToIndex.end()) {
        // answer = { index, hash_map[second] }
        answer[0] = i;
        answer[1] = valueToIndex[second];
        return answer;
      }

      // hash_map[first] = index;
      valueToIndex[first] = i;
    }

    return answer;
  }
};