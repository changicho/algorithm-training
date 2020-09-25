#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define INF 987654321

using namespace std;

struct Edge {
  int to;
  int cost;
};

struct compare {
  bool operator()(Edge a, Edge b) { return a.cost > b.cost; }
};

int solution(int n, vector<vector<int>> edge) {
  int answer = 0;

  priority_queue<Edge, vector<Edge>, compare> pq;
  vector<vector<Edge>> lines(n + 1);
  vector<int> costs(n + 1, INF);
  costs[0] = 0;

  for (vector<int> e : edge) {
    int from = e[0];
    int to = e[1];

    lines[from].push_back({to, 1});
    lines[to].push_back({from, 1});
  }

  int start = 1;
  costs[start] = 0;
  pq.push({start, 0});

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    for (Edge current : lines[cur.to]) {
      int new_val = costs[cur.to] + current.cost;
      int before_val = costs[current.to];

      if (new_val < before_val) {
        int destination = current.to;

        costs[destination] = new_val;
        pq.push({destination, new_val});
      }
    }
  }

  sort(costs.begin(), costs.end());

  answer = costs.end() - lower_bound(costs.begin(), costs.end(), costs.back());
  return answer;
}

struct TestCase {
  int n;
  vector<vector<int>> edge;
  int answer;
};

int main() {
  vector<TestCase> tcs = {
      {6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}}, 3}

  };

  for (TestCase tc : tcs) {
    int answer = solution(tc.n, tc.edge);

    bool isCorrect = answer == tc.answer;

    cout << isCorrect << ", answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}