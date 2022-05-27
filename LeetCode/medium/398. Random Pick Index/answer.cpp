#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map with rand
// time(init) : O(N)
// time(pick) : O(1)
// space : O(N)
class Solution {
 private:
  unordered_map<int, vector<int>> val2index;

 public:
  Solution(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      val2index[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    int size = val2index[target].size();

    int idx = rand() % size;

    return val2index[target][idx];
  }
};

// use hash map with queue
// time(init) : O(N)
// time(pick) : O(1)
// space : O(N)
class Solution {
 private:
  unordered_map<int, queue<int>> val2index;

 public:
  Solution(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      val2index[nums[i]].push(i);
    }
  }

  int pick(int target) {
    int idx = val2index[target].front();
    val2index[target].pop();
    val2index[target].push(idx);

    return idx;
  }
};

// use reservoir sampling (TLE)
// time(init) : O(N)
// time(pick) : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> nums;

  Solution(vector<int>& nums) { this->nums.swap(nums); }

  int pick(int target) {
    int size = nums.size();

    int count = 0;
    int index = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] == target) {
        count++;

        if (rand() % count == 0) {
          index = i;
        }
      }
    }
    return index;
  }
};