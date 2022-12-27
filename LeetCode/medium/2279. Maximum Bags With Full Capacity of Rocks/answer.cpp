#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use heap sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks,
                  int additionalRocks) {
    int size = capacity.size();

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < size; i++) {
      pq.push(capacity[i] - rocks[i]);
    }

    int answer = 0;
    while (!pq.empty() && additionalRocks >= 0) {
      int cur = pq.top();
      pq.pop();

      if (additionalRocks < cur) break;

      additionalRocks -= cur;
      answer++;
    }

    return answer;
  }
};

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks,
                  int additionalRocks) {
    int size = capacity.size();

    vector<int> diffs;

    for (int i = 0; i < size; i++) {
      diffs.push_back(capacity[i] - rocks[i]);
    }
    sort(diffs.begin(), diffs.end());

    int answer = 0;
    for (int& diff : diffs) {
      if (additionalRocks < diff) break;

      additionalRocks -= diff;
      answer++;
    }

    return answer;
  }
};