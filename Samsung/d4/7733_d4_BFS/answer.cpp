#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct axis {
  int y, x;
};
int N;
int map[101][101];

axis moves[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int countChunk(int day) {
  int visited[101][101]{
      0,
  };
  int count = 0;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (visited[y][x] || map[y][x] <= day) {
        continue;
      }
      queue<axis> q;
      visited[y][x] = 1;
      q.push(axis{y, x});
      count++;

      while (!q.empty()) {
        axis current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
          axis next = current;
          next.x += moves[i].x;
          next.y += moves[i].y;

          if (0 > next.x || N == next.x || 0 > next.y || N == next.y) {
            continue;
          }
          if (!visited[next.y][next.x] && map[next.y][next.x] > day) {
            visited[next.y][next.x] = 1;
            q.push(next);
          }
        }
      }
    }
  }

  return count;
}

void solution(int test_case) {
  int answer = 1;
  int max_taste = 1;
  int temp;
  cin >> N;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> temp;
      map[y][x] = temp;
      max_taste = max(max_taste, temp);
    }
  }

  for (int day = 1; day < max_taste; day++) {
    answer = max(answer, countChunk(day));
  }

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}