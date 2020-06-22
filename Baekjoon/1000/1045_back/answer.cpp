#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, +1}, {0, -1}, {-1, 0}, {+1, 0}};
int N;
double answer = 0;
bool visited[31][31];
double percents[4];

void dfs(int index, Axis cur, double val) {
  if (index == N) {
    answer += val;
    return;
  }

  visited[cur.y][cur.x] = true;
  for (int i = 0; i < 4; i++) {
    Axis next = cur;
    next.y += dirs[i].y;
    next.x += dirs[i].x;

    if (visited[next.y][next.x]) continue;

    dfs(index + 1, next, val * percents[i]);
  }
  visited[cur.y][cur.x] = false;
}

void solution() {
  cin >> N;

  for (int i = 0; i < 4; i++) {
    cin >> percents[i];
    percents[i] /= 100;
  }

  Axis start = {14, 14};

  dfs(0, start, 1);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(11);
  cout << fixed;

  // freopen("./data/input.txt", "r", stdin);

  solution();

  return 0;
}