#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash map (count)
// time : O(N)
// space : O(N)
class Solution {
 public:
  int mostFrequent(vector<int>& nums, int key) {
    int size = nums.size();
    unordered_map<int, int> count;

    for (int i = 0; i < size; i++) {
      if (nums[i] == key && i + 1 < size) {
        count[nums[i + 1]]++;
      }
    }

    int answer = nums.front();
    for (auto it : count) {
      if (count[it.first] > count[answer]) {
        answer = it.first;
      }
    }

    return answer;
  }
};