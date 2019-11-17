#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define MAX_HEIGHT 16
#define MAX_WIDTH 13

using namespace std;

struct axis {
  int x;
  int y;
};

struct fire {
  int x;
  int y;
  int fire_size;
};

axis moves[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<int> > map(MAX_HEIGHT);

int N, W, H;
int answer;
queue<fire> fires;

void print() {
  cout << "\n### Print Map ###\n";
  for (int height = 0; height < H; height++) {
    for (int width = 0; width < W; width++) {
      cout << map[height][width];
    }
    cout << "\n";
  }
}

void clear() { N = 0, W = 0, H = 0, answer = MAX_HEIGHT * MAX_WIDTH; }

void fall() {
  for (int width = 0; width < W; width++) {
    vector<int> column;

    for (int height = 0; height < H; height++) {
      if (map[height][width] != 0) {
        column.push_back(map[height][width]);
      }
    }

    reverse(column.begin(), column.end());
    column.resize(H);
    reverse(column.begin(), column.end());

    // 새로운 지도 그림
    for (int height = 0; height < H; height++) {
      map[height][width] = column[height];
    }
  }
}

void pushStartFirePoint(int x_index) {
  for (int height = 0; height < H; height++) {
    if (map[height][x_index] != 0) {
      fires.push(fire{x_index, height, map[height][x_index]});
      break;
    }
  }
}

void bomb() {
  while (fires.size() != 0) {
    fire f = fires.front();
    fires.pop();
    // 현재 벽돌 폭발
    map[f.y][f.x] = 0;
    // 연쇄 4 방향으로 폭팔
    for (int i = 0; i < 4; i++) {
      int x = f.x, y = f.y;

      for (int fire_size = 0; fire_size < f.fire_size - 1; fire_size++) {
        x += moves[i].x, y += moves[i].y;

        // 끝에 도달하면 종료
        if (y < 0 || y == H || x == W || x < 0) break;
        if (map[y][x] > 1) fires.push(fire{x, y, map[y][x]});
        map[y][x] = 0;
      }
    }
  }
  fall();
}

int countLeft() {
  int count = 0;
  for (int height = 0; height < H; height++) {
    for (int width = 0; width < W; width++) {
      if (map[height][width] != 0) count++;
    }
  }
  return count;
}

void dfs(int depth) {
  if (depth == N) {
    int min_answer = countLeft();
    if (answer > min_answer) {
      answer = min_answer;
    }
    return;
  }

  for (int index = 0; index < W; index++) {
    if (answer == 0) return;
    vector<vector<int> > pre_map = map;
    pushStartFirePoint(index);
    bomb();
    dfs(depth + 1);

    map = pre_map;
  }
}

void solution(int test_case) {
  clear();

  cin >> N >> W >> H;

  for (int height = 0; height < H; height++) {
    for (int width = 0; width < W; width++) {
      cin >> map[height][width];
    }
  }

  dfs(0);

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < MAX_HEIGHT; i++) {
    map[i].resize(MAX_WIDTH);
  }

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}