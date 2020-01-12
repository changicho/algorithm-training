#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct axis {
  int y, x;
};

axis moves[8]{{-1, +0}, {-1, +1}, {+0, +1}, {+1, +1},
              {+1, +0}, {+1, -1}, {+0, -1}, {-1, -1}};

int N, answer = 1000001;
int map[50][50];
bool check_house[50][50];

bool is_safe(axis a) {
  if (a.x < 0 || a.x >= N || a.y < 0 || a.y >= N) return false;
  return true;
}

void solution() {
  cin >> N;

  string line;
  axis start_point;
  vector<axis> houses;
  vector<int> heights;

  for (int y = 0; y < N; y += 1) {
    cin >> line;
    for (int x = 0; x < N; x += 1) {
      switch (line[x]) {
        case 'P':
          start_point = {y, x};
          break;
        case 'K':
          houses.push_back(axis{y, x});
          check_house[y][x] = 1;
          break;
      }
    }
  }

  for (int y = 0; y < N; y += 1) {
    for (int x = 0; x < N; x += 1) {
      cin >> map[y][x];
      heights.push_back(map[y][x]);
    }
  }

  sort(heights.begin(), heights.end());
  heights.erase(unique(heights.begin(), heights.end()), heights.end());

  int w_start = 0, w_end = 0;
  while (w_start < heights.size()) {
    bool visited[50][50] = {
        0,
    };

    queue<axis> q;
    int start_height = map[start_point.y][start_point.x];

    if (start_height < heights[w_start] || start_height > heights[w_end]) {
      if (w_end + 1 < heights.size()) w_end++;
      continue;
    }
    int K_count = 0;

    q.push(axis{start_point.y, start_point.x});
    visited[start_point.y][start_point.x] = 1;

    while (!q.empty()) {
      axis current = q.front();
      q.pop();

      for (int dir = 0; dir < 8; dir++) {
        axis next = current;
        next.y += moves[dir].y;
        next.x += moves[dir].x;
        int next_height = map[next.y][next.x];

        if (!is_safe(next) || visited[next.y][next.x]) continue;
        if (next_height < heights[w_start] || next_height > heights[w_end])
          continue;

        visited[next.y][next.x] = 1;
        if (check_house[next.y][next.x] == 1) K_count++;

        q.push(axis{next.y, next.x});
      }
    }

    if (K_count == houses.size()) {
      answer = min(answer, heights[w_end] - heights[w_start]);

      w_start++;
    } else if (w_end + 1 < heights.size()) {
      w_end++;
    } else {
      break;
    }
  }

  cout << answer << "\n ";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}