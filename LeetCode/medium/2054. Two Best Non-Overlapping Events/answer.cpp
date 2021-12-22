#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// use binary search

class Solution {
 public:
  int maxTwoEvents(vector<vector<int>> &events) {
    int size = events.size();

    sort(events.begin(), events.end(),
         [&](const vector<int> &a, const vector<int> &b) {
           return a[0] < b[0];
         });

    // biggest[index] : biggest value of event after index (index ~ size-1)
    vector<int> biggest(size, 0);
    biggest[size - 1] = events[size - 1][2];

    int answer = events[size - 1][2];
    for (int i = size - 2; i >= 0; i--) {
      int value = events[i][2];

      biggest[i] = max(biggest[i + 1], value);
      answer = max(answer, value);
    }

    for (int i = 0; i < size; i++) {
      // use binary search to find other maximum from i+1 ~ size
      int left = i + 1, right = size;
      bool isFind = false;

      while (left < right) {
        int mid = left + (right - left) / 2;

        // events[i].end < events[mid].start
        if (events[i][1] < events[mid][0]) {
          // pick left
          isFind = true;
          right = mid;
        } else {
          // pick right
          left = mid + 1;
        }
      }

      if (!isFind) continue;
      answer = max(events[i][2] + biggest[left], answer);
    }

    return answer;
  }
};