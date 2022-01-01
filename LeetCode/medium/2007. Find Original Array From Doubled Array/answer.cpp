#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use sotring

class Solution {
 public:
  vector<int> findOriginalArray(vector<int> &changed) {
    int size = changed.size();
    if (size % 2 == 1) return {};

    map<int, int> counts;
    for (int &num : changed) {
      counts[num] += 1;
    }

    vector<int> answer;
    // iterate by small one
    for (auto &it : counts) {
      int num = it.first;
      if (counts[num] > counts[num * 2]) return {};
      if (counts[num] == 0) continue;

      int count = counts[num];
      if (num == num * 2) count /= 2;
      counts[num] -= count;
      counts[num * 2] -= count;

      while (count--) {
        answer.push_back(num);
      }
    }

    return answer;
  }
};

// use sorting and compare unique

class Solution {
 public:
  vector<int> findOriginalArray(vector<int> &changed) {
    int size = changed.size();
    if (size % 2 == 1) return {};

    unordered_map<int, int> counts;
    vector<int> nums;

    for (int &num : changed) {
      counts[num] += 1;
    }

    // to search from smallest, do sort
    for (auto &it : counts) {
      nums.push_back(it.first);
    }
    sort(nums.begin(), nums.end());

    vector<int> answer;
    for (auto &num : nums) {
      if (counts[num] > counts[num * 2]) return {};
      if (counts[num] == 0) continue;

      int count = counts[num];
      if (num == num * 2) count /= 2;
      counts[num] -= count;
      counts[num * 2] -= count;

      while (count--) {
        answer.push_back(num);
      }
    }

    return answer;
  }
};