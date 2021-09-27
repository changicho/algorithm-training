#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use two heap

class Solution {
 private:
  typedef pair<int, int> Data;

 public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    int N = servers.size();
    int M = tasks.size();

    priority_queue<Data, vector<Data>, greater<Data>> pq, busy;
    vector<int> answer;

    for (int i = 0; i < N; ++i) {
      pq.push({servers[i], i});
    }

    int time = 0;
    for (int i = 0; i < M; ++i) {
      time = max(i, time);

      if (pq.empty() && busy.top().first > time) {
        time = busy.top().first;
      }

      while (!busy.empty() && busy.top().first <= time) {
        Data info = busy.top();
        pq.push({servers[info.second], info.second});
        busy.pop();
      }

      Data info = pq.top();
      busy.push({time + tasks[i], info.second});
      pq.pop();

      answer.emplace_back(info.second);
    }

    return answer;
  }
};
