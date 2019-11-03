#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX 13

using namespace std;

struct axis {
  int x;
  int y;
};

int answer = MAX * MAX;
int max_cells = 0;
int map[MAX][MAX];
int N;
axis moves[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<axis> cells;

void printMap() {
  cout << "\n### Print Map ###\n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}

/**
 * 입력받은 좌표에서 특정 방향으로 선연결이 계속 가능한지 판단하는 함수
 * 반환이 0이면 연결 불가능, 반환이 1 이상이면 연결하는 선의 길이
 */
int canWire(int x, int y, axis direction) {
  int count = 0;
  while (true) {
    x += direction.x;
    y += direction.y;
    count++;

    if (map[y][x] != 0) {
      return 0;
    }
    if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
      return count;
    }
  }
}

/**
 * 입력받은 좌표에서 특정 방향으로 선을 연결하거나 선을 지움
 * check의 값에 따라 달라짐.
 */
int makeWire(int x, int y, axis direction, int type) {
  int count = 0;
  while (true) {
    x += direction.x;
    y += direction.y;

    map[y][x] = type;
    count++;

    if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
      return count;
    }
  }
}

void dfs(int index, int cell_count, int wire_count) {
  // core의 수가 최대이상이면 갱신
  if (index == cells.size()) {
    if (cell_count > max_cells) {
      answer = wire_count;
      max_cells = cell_count;
    }
    // 최대 코어의 갯수가 같으며 선의 길이가 최소이면 갱신
    if (cell_count == max_cells) {
      answer = min(answer, wire_count);
    }
    return;
  }

  // 4 방향중 가능한 곳에 wire를 연결
  for (axis move : moves) {
    int this_line_count = canWire(cells[index].x, cells[index].y, move);

    if (this_line_count != 0) {
      int new_wire_count = wire_count + this_line_count;

      makeWire(cells[index].x, cells[index].y, move, 3);
      dfs(index + 1, cell_count + 1, new_wire_count);
      makeWire(cells[index].x, cells[index].y, move, 0);
    }
  }

  // 현재 core를 skip하고 다음 core로 넘어감
  dfs(index + 1, cell_count, wire_count);
}

/**
 * 0 : null, 1 : cell, 3 : wire
 */
void solution(int test_case) {
  // 초기화
  cells.clear();
  answer = MAX * MAX;
  max_cells = 0;

  cin >> N;

  // 초기 지도 입력받음
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
      if (map[i][j] == 1) {
        // 가장자리 연결된 cell은 탐색에서 제외
        if (i != 0 && i != N - 1 && j != 0 && j != N - 1) {
          axis cell = {j, i};
          cells.push_back(cell);
        }
      }
    }
  }
  // 남은 cell들로 탐색 시작
  dfs(0, 0, 0);

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