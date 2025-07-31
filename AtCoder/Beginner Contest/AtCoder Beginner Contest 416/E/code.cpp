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

const long long INF = 1e18;

struct Edge {
  int a, b, c;
};

long long getTotal(vector<vector<long long>> &dp, int n) {
  long long total = 0;
  for (int from = 1; from <= n; from++) {
    for (int to = 1; to <= n; to++) {
      if (from == to) continue;

      if (dp[from][to] != INF) {
        total += dp[from][to];
      }
    }
  }
  return total;
}

void update(vector<vector<long long>> &dp, int n, int a) {
  for (int through = 0; through <= n; through++) {
    for (int to = 0; to <= n; to++) {
      dp[a][to] = min(dp[a][to], dp[a][through] + dp[through][to]);
      dp[to][a] = min(dp[to][a], dp[to][through] + dp[through][a]);
    }
  }
  for (int from = 0; from <= n; from++) {
    for (int to = 0; to <= n; to++) {
      dp[from][to] = min(dp[from][to], dp[from][a] + dp[a][to]);
      dp[to][from] = min(dp[to][from], dp[to][a] + dp[a][from]);
    }
  }
}

vector<long long> solution(int n, vector<Edge> &edges, vector<int> &airports,
                           long long T, vector<vector<int>> &queries) {
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
  // sky is 0
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 0;
  }

  for (int &a : airports) {
    // cost when landing at airport
    dp[a][0] = min(dp[a][0], T);
    dp[0][a] = min(dp[0][a], 0LL);
  }

  for (Edge &e : edges) {
    int from = e.a, to = e.b;
    long long cost = e.c;

    dp[from][to] = min(dp[from][to], cost);
    dp[to][from] = min(dp[to][from], cost);
  }

  // use floyd
  for (int through = 0; through <= n; through++) {
    for (int from = 0; from <= n; from++) {
      for (int to = 0; to <= n; to++) {
        dp[from][to] = min(dp[from][to], dp[from][through] + dp[through][to]);
      }
    }
  }

  vector<long long> answer;

  for (vector<int> &query : queries) {
    int command = query[0];

    if (command == 1) {
      int a = query[1], b = query[2];
      long long cost = query[3];

      dp[a][b] = min(dp[a][b], cost);
      dp[b][a] = min(dp[b][a], cost);

      update(dp, n, a);
      update(dp, n, b);

    } else if (command == 2) {
      int x = query[1];

      dp[x][0] = min(dp[x][0], T);
      dp[0][x] = min(dp[0][x], 0LL);

      update(dp, n, x);
      update(dp, n, 0);

    } else if (command == 3) {
      long long total = getTotal(dp, n);
      answer.push_back(total);
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
    cin >> edges[i].a >> edges[i].b >> edges[i].c;
  }

  int K, T;
  cin >> K >> T;
  vector<int> airports(K);
  for (int i = 0; i < K; i++) {
    cin >> airports[i];
  }

  int Q;
  cin >> Q;

  vector<vector<int>> queries(Q);
  for (int i = 0; i < Q; i++) {
    int command;
    cin >> command;

    if (command == 1) {
      int x, y, t;
      cin >> x >> y >> t;
      queries[i] = {command, x, y, t};
    } else if (command == 2) {
      int x;
      cin >> x;
      queries[i] = {command, x};
    } else if (command == 3) {
      queries[i] = {command};
    }
  }

  vector<long long> answer = solution(N, edges, airports, T, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}