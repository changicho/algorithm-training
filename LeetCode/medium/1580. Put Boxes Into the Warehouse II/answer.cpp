#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use valid height & two pointers
// time : O(N * log_2(N) + M * log_2(M))
// space : O(N + M)
class Solution {
 public:
  int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
    int bSize = boxes.size(), wSize = warehouse.size();

    vector<int> heights(wSize);

    for (int i = 0, minimum = INT_MAX; i < wSize; i++) {
      minimum = min(minimum, warehouse[i]);
      heights[i] = minimum;
    }
    for (int i = wSize - 1, minHeight = INT_MAX; i >= 0; i--) {
      minHeight = min(minHeight, warehouse[i]);
      heights[i] = max(heights[i], minHeight);
    }

    sort(heights.begin(), heights.end());
    sort(boxes.begin(), boxes.end());

    int answer = 0;
    int bI = 0;
    for (int& height : heights) {
      if (bI < bSize && boxes[bI] <= height) {
        answer++;
        bI++;
      }
    }

    return answer;
  }
};