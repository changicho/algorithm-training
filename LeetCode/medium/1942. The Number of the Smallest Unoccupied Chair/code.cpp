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

// use two heap
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int size = times.size();

    int targetArrive = times[targetFriend][0];
    sort(times.begin(), times.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        leaves;
    priority_queue<int, vector<int>, greater<int>> pq;

    int answer = -1;

    for (int i = 0; i < size; i++) {
      pq.push(i);
    }
    for (vector<int>& time : times) {
      int arrive = time[0], leave = time[1];

      while (!leaves.empty() && leaves.top().first <= arrive) {
        pq.push(leaves.top().second);
        leaves.pop();
      }

      int chair = pq.top();
      pq.pop();

      if (arrive == targetArrive) {
        answer = chair;
        break;
      }
      leaves.push({leave, chair});
    }
    return answer;
  }
};