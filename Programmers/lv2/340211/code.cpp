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

// use simulation
// time : O(N * M)
// space : O(N)
struct Axis {
  int y, x;

  int convert() { return y * 1000 + x; }
};

struct Robot {
  Axis cur;
  queue<Axis> goals;
};

Axis move(Axis cur, Axis goal) {
  int yDiff = goal.y - cur.y;
  int xDiff = goal.x - cur.x;

  if (abs(yDiff) > 0) {
    cur.y += (yDiff > 0 ? 1 : -1);
  } else if (abs(xDiff) > 0) {
    cur.x += (xDiff > 0 ? 1 : -1);
  }

  return cur;
}

bool isSame(Axis &a, Axis &b) { return a.y == b.y && a.x == b.x; }

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
  int size = routes.size();

  queue<Robot> robots;

  for (int i = 0; i < size; i++) {
    Robot r;

    for (int &p : routes[i]) {
      r.goals.push({points[p - 1][0], points[p - 1][1]});
    }
    r.cur = r.goals.front();

    robots.push(r);
  }

  int answer = 0;
  while (!robots.empty()) {
    int size = robots.size();

    unordered_set<int> visited;
    unordered_set<int> crashPoints;

    while (size--) {
      Robot r = robots.front();
      robots.pop();

      r.cur = move(r.cur, r.goals.front());

      if (visited.count(r.cur.convert()) > 0) {
        crashPoints.insert(r.cur.convert());
      }
      visited.insert(r.cur.convert());

      if (isSame(r.cur, r.goals.front())) {
        r.goals.pop();
      }
      if (r.goals.empty()) continue;
      robots.push(r);
    }

    answer += crashPoints.size();
  }

  return answer;
}