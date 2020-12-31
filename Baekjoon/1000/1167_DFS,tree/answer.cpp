#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Link {
  int to;
  int dist;
};

int N;
bool visited[100001];
vector<vector<Link> > links;
Link farestNode;

void recursive(int dist, int node) {
  if (visited[node]) return;
  visited[node] = true;

  if (farestNode.dist < dist) {
    farestNode.dist = dist;
    farestNode.to = node;
  }

  for (Link link : links[node]) {
    if (visited[link.to]) continue;

    recursive(dist + link.dist, link.to);
  }
}

void solution() {
  cin >> N;
  links.resize(N + 1);

  int from, to, dist;
  for (int i = 0; i < N; i++) {
    cin >> from;

    cin >> to;
    while (to != -1) {
      cin >> dist;
      links[from].push_back({to, dist});
      cin >> to;
    }
  }

  recursive(0, 1);

  memset(visited, false, sizeof(visited));
  farestNode.dist = 0;
  recursive(0, farestNode.to);

  int answer = farestNode.dist;

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}