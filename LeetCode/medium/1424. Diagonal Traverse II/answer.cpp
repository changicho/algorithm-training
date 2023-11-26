#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use grouping diagonal
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int rows = nums.size();

    unordered_map<int, vector<int>> um;
    for (int y = rows - 1; y >= 0; y--) {
      int cols = nums[y].size();

      for (int x = 0; x < cols; x++) {
        int diagonal = y + x;

        um[diagonal].push_back(nums[y][x]);
      }
    }

    vector<int> answer;
    int d = 0;

    while (um.find(d) != um.end()) {
      for (int& num : um[d]) {
        answer.push_back(num);
      }

      d++;
    }

    return answer;
  }
};
