#include <algorithm>
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

struct Subset {
  int cost;
  vector<int> nodes;
};

long long solution(int n, vector<Subset> &subsets) {
  sort(subsets.begin(), subsets.end(),
       [](const Subset &a, const Subset &b) { return a.cost < b.cost; });

  vector<int> parents(n + 1);
  for (int node = 1; node <= n; node++) {
    parents[node] = node;
  }
  int graphCount = n;

  long long answer = 0;

  function<int(int)> find = [&](int node) -> int {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  };

  function<void(int, int, int)> merge = [&](int a, int b, int cost) -> void {
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (a < b) swap(a, b);

    graphCount--;
    answer += cost;
    parents[a] = b;
  };

  for (Subset &subset : subsets) {
    int parent = find(subset.nodes[0]);

    for (int node : subset.nodes) {
      merge(parent, node, subset.cost);
    }
  }

  if (graphCount > 1) return -1;

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

  vector<Subset> subsets(M);
  for (int i = 0; i < M; i++) {
    int K, C;
    cin >> K >> C;
    subsets[i].cost = C;
    subsets[i].nodes.resize(K);

    for (int j = 0; j < K; j++) {
      cin >> subsets[i].nodes[j];
    }
  }

  long long answer = solution(N, subsets);
  cout << answer << endl;

  return 0;
}