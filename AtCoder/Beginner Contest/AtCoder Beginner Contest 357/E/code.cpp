#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class UnionFind {
  vector<int> childrens;
  vector<int> parents;
  int count;

 public:
  UnionFind(int n) {
    count = n;
    childrens.resize(n, 1);
    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
  }

  int find(int node) {
    if (parents[node] == node) {
      return node;
    }

    return parents[node] = find(parents[node]);
  };

  void merge(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB) return;
    if (parentA > parentB) swap(parentA, parentB);

    parents[parentA] = parentB;
    childrens[parentB] += childrens[parentA];
    count--;
  };

  int getChildren(int node) { return childrens[find(node)]; }
  int getCount() { return count; }
};

vector<vector<int>> findSCC(int n, vector<int> &nexts) {
  vector<vector<int>> graph(n), rGraph(n);

  for (int i = 0; i < n; i++) {
    int next = nexts[i];
    graph[i].push_back(next);
    rGraph[next].push_back(i);
  }

  vector<bool> visited(n, false);
  stack<int> stk;
  vector<vector<int>> scc;

  function<void(int)> dfs = [&](int node) {
    visited[node] = true;
    for (int &next : graph[node]) {
      if (!visited[next]) dfs(next);
    }
    stk.push(node);
  };

  function<void(int, vector<int> &)> dfsR = [&](int node, vector<int> &cycle) {
    visited[node] = true;
    cycle.push_back(node);
    for (int &next : rGraph[node]) {
      if (!visited[next]) dfsR(next, cycle);
    }
  };

  for (int node = 0; node < n; node++) {
    if (!visited[node]) dfs(node);
  }
  visited.assign(n, false);
  while (!stk.empty()) {
    int now = stk.top();
    stk.pop();
    if (visited[now]) continue;

    vector<int> cycle;
    dfsR(now, cycle);
    scc.push_back(cycle);
  }

  return scc;
}

long long solution(int n, vector<int> &nexts) {
  UnionFind uf(n);

  long long answer = 0;

  vector<vector<int>> cycles = findSCC(n, nexts);

  for (vector<int> &cycle : cycles) {
    int base = cycle[0];
    for (int node : cycle) {
      uf.merge(base, node);
    }

    answer += cycle.size() * (cycle.size() - 1);
  }

  vector<int> inDegrees(n, INT_MAX);
  for (int i = 0; i < n; i++) {
    inDegrees[uf.find(i)] = 0;
  }
  for (int node = 0; node < n; node++) {
    if (node != uf.find(node)) continue;

    int next = uf.find(nexts[node]);
    if (next == node) continue;
    inDegrees[uf.find(next)]++;
  }

  // use topological sort
  queue<int> q;

  vector<int> childrens(n, 0);
  for (int i = 0; i < n; i++) {
    if (inDegrees[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    int children = childrens[node];
    answer += children * uf.getChildren(node);

    int next = uf.find(nexts[node]);
    childrens[next] += children + 1;

    inDegrees[next]--;

    if (inDegrees[next] == 0) {
      q.push(next);
    }
  }

  return answer + n;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }

  long long answer = solution(N, A);

  cout << answer << endl;

  return 0;
}