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

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int size = startTime.size();
    int answer = 0;
    vector<bool> canErase(size, false);

    for (int i = 0, maxHole = 0; i < size; i++) {
      if (endTime[i] - startTime[i] <= maxHole) {
        canErase[i] = true;
      }

      int before = (i - 1 < 0) ? 0 : endTime[i - 1];
      maxHole = max(maxHole, startTime[i] - before);
    }

    for (int i = size - 1, maxHole = 0; i >= 0; i--) {
      if (endTime[i] - startTime[i] <= maxHole) {
        canErase[i] = true;
      }

      int next = (i + 1 >= size) ? eventTime : startTime[i + 1];
      maxHole = max(maxHole, next - endTime[i]);
    }

    for (int i = 0; i < size; i++) {
      int before = (i - 1 < 0) ? 0 : endTime[i - 1];
      int next = (i + 1 >= size) ? eventTime : startTime[i + 1];

      int range = next - before;
      int diff = (endTime[i] - startTime[i]);

      if (canErase[i]) {
        answer = max(answer, range);
      } else {
        answer = max(answer, range - diff);
      }
    }
    return answer;
  }
};