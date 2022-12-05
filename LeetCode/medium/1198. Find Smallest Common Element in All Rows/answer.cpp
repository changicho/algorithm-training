#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use counting
// time : O(R * C)
// space : O(1)
class Solution {
 public:
  int smallestCommonElement(vector<vector<int>> &mat) {
    int rows = mat.size(), cols = mat.front().size();

    int counts[10001] = {
        0,
    };
    int answer = INT_MAX;
    for (vector<int> &row : mat) {
      for (int &num : row) {
        counts[num]++;

        if (counts[num] == rows) {
          answer = min(num, answer);
        }
      }
    }

    if (answer == INT_MAX) return -1;
    return answer;
  }
};