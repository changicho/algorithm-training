#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & greedy

class Solution {
 public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] > b[1]; });

    int count = 0;
    int answer = 0;
    for (vector<int> &box : boxTypes) {
      if (count + box[0] < truckSize) {
        count += box[0];
        answer += box[0] * box[1];

        continue;
      }

      int diff = truckSize - count;
      count += diff;
      answer += box[1] * diff;

      if (count == truckSize) break;
    }

    return answer;
  }
};