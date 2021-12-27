#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use monotonic queue

class Solution {
 private:
  struct Data {
    int value, index;
  };

 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int size = nums.size();
    deque<Data> dq;

    vector<int> answer;
    for (int i = 0; i < size; i++) {
      while (!dq.empty() && dq.front().index < i - k + 1) {
        dq.pop_front();
      }

      while (!dq.empty() && dq.back().value < nums[i]) {
        dq.pop_back();
      }

      dq.push_back({nums[i], i});
      if (i >= k - 1) {
        answer.push_back(dq.front().value);
      }
    }

    return answer;
  }
};

// use BST map

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int size = nums.size();
    map<int, int> slide;

    for (int i = 0; i < k; i++) {
      slide[nums[i]] += 1;
    }

    vector<int> answer;
    int left = 0, right = k - 1;
    auto it = slide.end();
    it--;
    answer.push_back(it->first);

    for (int left = 0; left < size - k; left++) {
      int right = left + k;

      slide[nums[left]] -= 1;
      if (slide[nums[left]] == 0) {
        slide.erase(nums[left]);
      }
      slide[nums[right]] += 1;

      auto it = slide.end();
      it--;
      answer.push_back(it->first);
    }

    return answer;
  }
};