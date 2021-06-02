#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use struct and sort

class Solution {
 public:
  struct Number {
    int index, value;

    bool operator<(const Number& b) const {
      if (value != b.value) {
        return value < b.value;
      }
      return index < b.index;
    }
  };
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    vector<Number> numbers;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      numbers.push_back({i, nums[i]});
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < size - 1; i++) {
      if (numbers[i].value != numbers[i + 1].value) continue;
      if (numbers[i + 1].index - numbers[i].index <= k) return true;
    }
    return false;
  }
};

// use set

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if (k == 0) return false;
    unordered_set<int> s;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
      if (s.find(nums[i]) != s.end()) return true;
      if (i >= k) {
        s.erase(nums[i - k]);
      }
      s.insert(nums[i]);
    }
    return false;
  }
};

// use map

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
      if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
        return true;
      }
      m[nums[i]] = i;
    }
    return false;
  }
};