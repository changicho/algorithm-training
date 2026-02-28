#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

struct Edge {
  int from, to;
};

vector<int> solution(int n, int eSize, vector<Edge>& edges) {
  vector<int> answer;

  vector<vector<int>> graph(n + 1);
  for (Edge& e : edges) {
    graph[e.from].push_back(e.to);
  }

  unordered_set<int> visited;
  unordered_set<int> remainNodes;
  queue<int> q;

  q.push(1);
  visited.insert(1);

  for (int canReach = 1; canReach <= n; canReach++) {
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int& next : graph[cur]) {
        if (visited.count(next)) continue;

        if (next <= canReach) {
          q.push(next);
          visited.insert(next);
        } else {
          remainNodes.insert(next);
        }
      }
    }

    if (visited.size() == canReach) {
      answer.push_back(remainNodes.size());
    } else {
      answer.push_back(-1);
    }

    if (remainNodes.count(canReach + 1) > 0) {
      q.push(canReach + 1);
      visited.insert(canReach + 1);

      remainNodes.erase(canReach + 1);
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<Edge> edges(M);
  for (int i = 0; i < M; i++) {
    cin >> edges[i].from >> edges[i].to;
  }

  auto answer = solution(N, M, edges);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}