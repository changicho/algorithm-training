#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct edge {
  int end, cost;
};

struct node {
  int cost, index;
};

struct compare {
  bool operator()(node a, node b) { return a.cost > b.cost; }
};

vector<vector<edge>> links;
vector<int> costs;
int max_cost;

void dijikstra(int start) {
  priority_queue<node, vector<node>, compare> pq;

  pq.push({0, start});

  while (!pq.empty()) {
    node cur = pq.top();
    pq.pop();

    for (edge current : links[cur.index]) {
      int new_val = costs[cur.index] + current.cost;
      int before_val = costs[current.end];

      // 현재 노드로 부터 연결된 엣지의 목적지까지 가는 거리와 기존의 거리를
      // 비교하여, 새로운 cost가 작으면 값을 갱신하고 pq에 넣는다
      if (new_val < before_val || before_val == -1) {
        int destination = current.end;

        costs[destination] = new_val;
        pq.push({new_val, destination});

        max_cost = max(costs[destination], max_cost);
      }
    }
  }
}

void solution() {
  int N, M;

  cin >> N >> M;

  // 1부터 시작
  links.resize(N + 1);
  costs.resize(N + 1);

  for (int i = 1; i <= N; i++) {
    costs[i] = -1;
  }
  costs[1] = 0;

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    links[from].push_back({to, 1});
    links[to].push_back({from, 1});
  }

  dijikstra(1);

  int answer_index;
  int answer_cost = max_cost;
  int answer_count = 0;

  for (int i = N; i > 0; i -= 1) {
    if (costs[i] == answer_cost) {
      answer_index = i;
      answer_count += 1;
    }
  }

  cout << answer_index << " " << answer_cost << " " << answer_count << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}