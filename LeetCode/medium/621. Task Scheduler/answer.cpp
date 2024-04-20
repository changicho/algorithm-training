#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use priority queue
// time : O(N)
// space : O(1)
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    int counts[26] = {
        0,
    };
    for (char& c : tasks) {
      counts[c - 'A']++;
    }

    priority_queue<int> pq;
    for (int i = 0; i < 26; i++) {
      if (counts[i] > 0) {
        pq.push(counts[i]);
      }
    }

    int time = 0;
    while (!pq.empty()) {
      int canChoose = n + 1;
      vector<int> remains;
      int chosen = 0;

      for (int i = 0; i < canChoose && !pq.empty(); i++) {
        int cur = pq.top() - 1;
        pq.pop();

        if (cur > 0) {
          remains.push_back(cur);
        }
        chosen++;
      }

      for (int& count : remains) {
        pq.push(count);
      }
      time += (pq.empty() ? chosen : n + 1);
    }

    return time;
  }
};