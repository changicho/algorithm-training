#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Line {
  int to, weight;
};

vector<vector<Line> > map;
bool visited[100001];
int N, M;

bool canVisit(int from, int to, int val) {
  memset(visited, false, sizeof(visited));

  queue<int> q;
  q.push(from);
  visited[from] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (cur == to) {
      return true;
    }

    for (Line line : map[cur]) {
      if (line.weight >= val && !visited[line.to]) {
        visited[line.to] = true;
        q.push(line.to);
      }
    }
  }

  return false;
}

void solution() {
  int answer = 0;
  int from, to;
  int start = 0, end = 0, mid;

  cin >> N >> M;

  map.resize(N + 1);

  for (int i = 0; i < M; i++) {
    int A, B, C;

    cin >> A >> B >> C;

    map[A].push_back({B, C});
    map[B].push_back({A, C});
    end = max(end, C);
  }

  cin >> from >> to;

  while (start <= end) {
    mid = (start + end) / 2;

    if (canVisit(from, to, mid)) {
      answer = max(answer, mid);
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./data/input.txt", "r", stdin);
  solution();

  return 0;
}