#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Link {
  int to;
  int dist;
};

int N;
vector<bool> visited;
vector<int> distArr;
vector<vector<Link> > links;

void getDistance(int dist, int node) {
  if (visited[node]) return;
  visited[node] = true;

  distArr[node] = dist;

  for (Link link : links[node]) {
    if (visited[link.to]) continue;

    getDistance(dist + link.dist, link.to);
  }
}

Link getFarestNode(int node) {
  visited.clear();
  distArr.clear();
  visited.resize(N + 1, false);
  distArr.resize(N + 1, 0);

  Link ret = {0, 0};

  getDistance(0, node);

  for (int target = 1; target <= N; target++) {
    if (distArr[target] > ret.dist) {
      ret.dist = distArr[target];
      ret.to = target;
    }
  }

  return ret;
}

void solution() {
  cin >> N;
  links.resize(N + 1);

  int from, to, dist;
  for (int i = 0; i < N - 1; i++) {
    cin >> from >> to >> dist;

    links[from].push_back({to, dist});
    links[to].push_back({from, dist});
  }

  Link A = getFarestNode(1);
  Link B = getFarestNode(A.to);

  cout << B.dist << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}