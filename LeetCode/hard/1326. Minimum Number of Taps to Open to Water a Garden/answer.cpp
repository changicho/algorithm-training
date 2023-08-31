#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minTaps(int n, vector<int> &ranges) {
    int size = ranges.size();

    vector<pair<int, int>> arr;
    for (int i = 0; i < size; i++) {
      arr.push_back({i - ranges[i], i + ranges[i]});
    }

    sort(arr.begin(), arr.end());

    int right = 0;
    int index = 0;

    int answer = 0;
    while (index < size && right < n) {
      int next = -1;
      while (index < size && arr[index].first <= right) {
        if (right <= arr[index].second) {
          next = max(next, arr[index].second);
        }
        index++;
      }

      if (next == -1) return -1;
      answer++;
      right = next;
    }

    if (answer == 0) return -1;
    return answer;
  }
};