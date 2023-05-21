#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    vector<int> colors(n, 0);

    int count = 0;
    vector<int> answer;
    for (vector<int>& q : queries) {
      int index = q[0], color = q[1];

      int left = (index - 1 >= 0) ? colors[index - 1] : 0;
      int right = (index + 1 < n) ? colors[index + 1] : 0;

      if (left != 0 && left == colors[index]) count--;
      if (right != 0 && right == colors[index]) count--;
      colors[index] = color;
      if (left != 0 && left == colors[index]) count++;
      if (right != 0 && right == colors[index]) count++;

      answer.emplace_back(count);
    }
    return answer;
  }
};