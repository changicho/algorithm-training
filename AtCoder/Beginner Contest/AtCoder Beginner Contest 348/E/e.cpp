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

  long long sum = accumulate(costs.begin(), costs.end(), 0LL);
  long long temp = 0;
  long long answer = 0;
  vector<long long> costSums(n, 0);

  function<void(int, int, int)> preprocess = [&](int node, int parent,
                                                 int depth) -> void {
    for (int &child : graph[node]) {
      if (child == parent) continue;

      preprocess(child, node, depth + 1);
      costSums[node] += costSums[child];
    }

    temp += costs[node] * depth;
    costSums[node] += costs[node];
  };

  function<void(int, int)> recursive = [&](int node, int parent) -> void {
    answer = min(answer, temp);

    for (int &child : graph[node]) {
      if (child == parent) continue;

      temp -= costSums[child];
      temp += sum - costSums[child];
      recursive(child, node);
      temp += costSums[child];
      temp -= sum - costSums[child];
    }
  };

  preprocess(0, 0, 0);
  answer = temp;
  recursive(0, 0);

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