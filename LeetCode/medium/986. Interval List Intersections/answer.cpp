#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointer

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    int size1 = firstList.size(), size2 = secondList.size();
    int idx1 = 0, idx2 = 0;
    vector<vector<int>> answer;

    while (idx1 < size1 && idx2 < size2) {
      vector<int> target1 = firstList[idx1];
      vector<int> target2 = secondList[idx2];

      // overlapped
      if (target1[0] <= target2[1] && target2[0] <= target1[1]) {
        int from = max(target1[0], target2[0]);
        int to = min(target1[1], target2[1]);

        answer.push_back({from, to});
      }

      if (target1[1] < target2[1]) {
        idx1++;
      } else {
        idx2++;
      }
    }

    return answer;
  }
};