#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use store index (hash map)
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    int size = nums.size();
    unordered_map<int, int> idxTable;

    for (int i = 0; i < size; i++) {
      idxTable[nums[i]] = i;
    }

    for (vector<int>& o : operations) {
      int first = o[0], second = o[1];
      int idx1 = idxTable[first];

      nums[idx1] = second;
      idxTable.erase(first);
      idxTable[second] = idx1;
    }

    return nums;
  }
};

// use store index (array)
// time : O(N + M)
// space : O(1)
class Solution {
 private:
  int idxs[1000001] = {
      0,
  };

 public:
  vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    int size = nums.size();

    for (int i = 0; i < size; i++) {
      idxs[nums[i]] = i;
    }

    for (vector<int>& o : operations) {
      int first = o[0], second = o[1];
      int idx1 = idxs[first];

      nums[idx1] = second;
      idxs[first] = 0;
      idxs[second] = idx1;
    }

    return nums;
  }
};