#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use square root decomposition
// time : O(N * sqrt(N))
// space: O(sqrt(N))
class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int size = baskets.size();
    int sizeSqrt = sqrt(size);
    int sections = (size + sizeSqrt - 1) / sizeSqrt;
    vector<int> maxV(sections);

    for (int i = 0; i < size; i++) {
      maxV[i / sizeSqrt] = max(maxV[i / sizeSqrt], baskets[i]);
    }

    int answer = 0;
    for (int& fruit : fruits) {
      int unset = 1;
      for (int sI = 0; sI < sections; sI++) {
        if (maxV[sI] < fruit) {
          continue;
        }
        bool isChosen = 0;
        maxV[sI] = 0;

        for (int i = 0; i < sizeSqrt; i++) {
          int pos = sI * sizeSqrt + i;
          if (pos < size && baskets[pos] >= fruit && !isChosen) {
            baskets[pos] = 0;
            isChosen = 1;
          }
          if (pos < size) {
            maxV[sI] = max(maxV[sI], baskets[pos]);
          }
        }
        unset = 0;
        break;
      }
      answer += unset;
    }
    return answer;
  }
};