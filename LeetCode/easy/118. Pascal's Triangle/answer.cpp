#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal;

    pascal.push_back({1});

    for (int i = 1; i < numRows; i++) {
      vector<int> row = {
          1,
      };
      int size = pascal[i - 1].size();
      for (int j = 1; j < size; j++) {
        row.push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
      }
      row.push_back(1);

      pascal.push_back(row);
    }

    return pascal;
  }
};