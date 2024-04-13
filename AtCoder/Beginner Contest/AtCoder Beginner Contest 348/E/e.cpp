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

struct Edge {
  int a, b;
};

long long solution(int n, vector<Edge> &edges, vector<long long> &costs) {
  vector<vector<int>> graph(n);
  for (Edge &edge : edges) {
    int a = edge.a - 1, b = edge.b - 1;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  long long costSum = accumulate(costs.begin(), costs.end(), 0LL);
  long long costsFromRoot = 0;
  long long answer = LLONG_MAX;
  vector<long long> subTreeCostSums(n, 0);

  function<void(int, int, int)> preProcess = [&](int node, int parent,
                                                 int depth) -> void {
    costsFromRoot += costs[node] * depth;
    subTreeCostSums[node] += costs[node];

    for (int &child : graph[node]) {
      if (child == parent) continue;

      preProcess(child, node, depth + 1);
      subTreeCostSums[node] += subTreeCostSums[child];
    }
  };

  function<void(int, int, long long)> recursive =
      [&](int node, int parent, long long curCost) -> void {
    answer = min(answer, curCost);

    for (int &child : graph[node]) {
      if (child == parent) continue;

      long long curPartSum = subTreeCostSums[child];
      long long otherPartSum = costSum - subTreeCostSums[child];

      long long nextCost = curCost - curPartSum + otherPartSum;
      recursive(child, node, nextCost);
    }
  };

  preProcess(0, -1, 0);
  recursive(0, 0, costsFromRoot);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;
  vector<Edge> edges(N - 1);
  for (int i = 0; i < N - 1; i++) {
    cin >> edges[i].a >> edges[i].b;
  }

  vector<long long> costs(N);
  for (int i = 0; i < N; i++) {
    cin >> costs[i];
  }

  long long answer = solution(N, edges, costs);

  cout << answer << endl;

  return 0;
}