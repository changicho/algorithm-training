#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Status {
  int node, depth;

  bool operator<(const Status &b) const {
    return depth > b.depth;
  }
};

vector<int> graph[1000001];
vector<int> tree[1000001];
int dp[1000001][2];  // node번째가 얼리어답터인경우, 아닌경우;
bool visited[1000001][2];

vector<Status> node_visit_array;

void make_tree(int node, int parent, int depth) {
  tree[parent].push_back(node);

  for (int next : graph[node]) {
    if (next == parent) continue;
    make_tree(next, node, depth + 1);
  }
  node_visit_array.push_back({node, depth});
}

int recursive(int node, bool isEarly) {
  if (visited[node][isEarly]) {
    return dp[node][isEarly];
  }
  visited[node][isEarly] = true;

  int count = isEarly ? 1 : 0;
  if (isEarly) {  // 현재 노드가 얼리어답터인 경우 자식은 아무 상태가 되어도 상관없다.
    for (int next : tree[node]) {
      count += min(recursive(next, false), recursive(next, true));
    }
  } else {  // 현재 노드가 얼리어답터가 아닌경우 자식은 얼리어답터여야함
    for (int next : tree[node]) {
      count += recursive(next, true);
    }
  }

  return dp[node][isEarly] = count;
}

void solution() {
  int N;
  cin >> N;

  int from, to;
  for (int i = 0; i < N - 1; i++) {
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  make_tree(1, 0, 0);
  sort(node_visit_array.begin(), node_visit_array.end());

  for (Status cur : node_visit_array) {
    int node = cur.node;

    dp[node][true] = 1;
    dp[node][false] = 0;
    for (int next : tree[node]) {
      dp[node][true] += min(dp[next][false], dp[next][true]);
    }
    for (int next : tree[node]) {
      dp[node][false] += dp[next][true];
    }
  }

  int answer = min(dp[1][false], dp[1][true]);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}