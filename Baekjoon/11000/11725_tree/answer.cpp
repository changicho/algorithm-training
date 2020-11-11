#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> links[100001];
int parents[100001];
bool visited[100001];

void recursive(int node) {
  visited[node] = true;

  for (int to : links[node]) {
    if (visited[to]) continue;

    parents[to] = node;
    recursive(to);
  }
}

void solution() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    int from, to;
    cin >> from >> to;

    links[from].push_back(to);
    links[to].push_back(from);
  }

  recursive(1);

  for (int i = 2; i <= N; i++) {
    cout << parents[i] << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}