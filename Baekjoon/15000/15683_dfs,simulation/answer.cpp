#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define WATCH 9

using namespace std;

struct Axis {
  int y, x;
};

struct Camera {
  vector<int> dirs;
  Axis axis;
};

vector<Axis> dirs = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};
Axis limit;
int map[8][8];
int map_ori[8][8];
int answer = 8 * 8;

vector<vector<int>> cameraDir = {{},     {0},       {0, 2},
                                 {0, 1}, {0, 1, 2}, {0, 1, 2, 3}};
vector<Camera> cameras;

void watch(int dir, Axis axis) {
  Axis cur = {axis.y, axis.x};

  while (true) {
    cur.y += dirs[dir].y;
    cur.x += dirs[dir].x;

    if (cur.y < 0 || cur.y >= limit.y || cur.x < 0 || cur.x >= limit.x) {
      break;
    }

    if (map[cur.y][cur.x] == 6) {
      break;
    }
    if (map[cur.y][cur.x] == 0) {
      map[cur.y][cur.x] = WATCH;
    }
  }
}

void clear_map() {
  for (int y = 0; y < limit.y; y++) {
    for (int x = 0; x < limit.x; x++) {
      map[y][x] = map_ori[y][x];
    }
  }
}

int countBlank() {
  int count = 0;
  for (int y = 0; y < limit.y; y++) {
    for (int x = 0; x < limit.x; x++) {
      if (map[y][x] == 0) {
        count += 1;
      }
    }
  }
  return count;
}

void dfs(int index, vector<int> cameraDirs) {
  if (index == cameras.size()) {
    for (int i = 0; i < cameras.size(); i++) {
      Camera camera = cameras[i];
      for (int dir : camera.dirs) {
        watch((dir + cameraDirs[i]) % 4, camera.axis);
      }
    }

    answer = min(answer, countBlank());

    clear_map();
    return;
  }

  if (cameras[index].dirs.size() == 4) {
    cameraDirs.push_back(0);
    dfs(index + 1, cameraDirs);

    return;
  }

  for (int i = 0; i < 4; i++) {
    vector<int> cur_dirs = cameraDirs;
    cur_dirs.push_back(i);
    dfs(index + 1, cur_dirs);
  }
}

void solution() {
  int N, M;

  cin >> N >> M;

  limit.y = N;
  limit.x = M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> map_ori[y][x];

      if (map_ori[y][x] >= 1 && map_ori[y][x] <= 5) {
        Camera camera;
        camera.dirs = cameraDir[map_ori[y][x]];
        camera.axis = {y, x};

        cameras.push_back(camera);
      }
    }
  }

  clear_map();

  vector<int> camers_dirs;
  dfs(0, camers_dirs);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}