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

struct Student {
  int arrive, time;
  int type;
};

int calc(int people, vector<Student> &students) {
  int time = 0;

  priority_queue<int, vector<int>, greater<int>> pq;  // minHeap
  int ret = 0;
  for (Student &s : students) {
    while (!pq.empty() && pq.top() <= s.arrive) {
      pq.pop();
    }

    if (pq.size() < people) {
      pq.push(s.arrive + s.time);
      continue;
    }

    int beforeEnd = pq.top();
    pq.pop();

    ret += beforeEnd - s.arrive;

    pq.push(max(beforeEnd, s.arrive) + s.time);
  }
  return ret;
}

int solution(int k, int n, vector<vector<int>> reqs) {
  vector<Student> students[5];

  sort(reqs.begin(), reqs.end(), [](auto &a, auto &b) { return a[0] < b[0]; });

  for (vector<int> &req : reqs) {
    int arrive = req[0], time = req[1], type = req[2] - 1;

    students[type].push_back({arrive, time, type});
  }

  // [type][people]
  int times[5][21] = {
      0,
  };

  for (int type = 0; type < k; type++) {
    times[type][0] = INT_MAX;

    for (int people = 1; people <= n; people++) {
      times[type][people] = calc(people, students[type]);
    }
  }

  long long answer = INT_MAX;

  function<void(int, int, int)> recursive = [&](int index, int left,
                                                long long cost) {
    if (index == k) {
      if (left == 0) {
        answer = min(answer, cost);
      }
      return;
    }

    for (int people = 1; people <= left; people++) {
      long long newCost = cost + times[index][people];
      recursive(index + 1, left - people, newCost);
    }
  };

  recursive(0, n, 0);

  return (int)answer;
}