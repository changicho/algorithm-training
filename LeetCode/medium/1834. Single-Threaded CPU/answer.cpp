#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use heap

class Solution {
 private:
  struct Data {
    int index;
    long came, cost;

    bool operator<(const Data &b) const {
      if (cost != b.cost) {
        return cost > b.cost;
      }
      return index > b.index;
    }
  };

 public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    int size = tasks.size();

    vector<Data> datas;
    for (int i = 0; i < size; i++) {
      vector<int> &t = tasks[i];
      datas.push_back({i, t[0], t[1]});
    }

    sort(datas.begin(), datas.end(),
         [&](Data &a, Data &b) { return a.came < b.came; });

    vector<int> answer;
    priority_queue<Data> pq;

    int time = datas.front().came;
    int index = 0;

    // until all task over
    while (answer.size() < size) {
      // push enqued tasks
      while (index < size && datas[index].came <= time) {
        pq.push(datas[index]);
        index++;
      }

      // if pq is empty, move time to next task
      if (pq.empty()) {
        time = datas[index].came;
        continue;
      }

      Data cur = pq.top();
      pq.pop();
      answer.push_back(cur.index);

      time += cur.cost;
    }

    return answer;
  }
};