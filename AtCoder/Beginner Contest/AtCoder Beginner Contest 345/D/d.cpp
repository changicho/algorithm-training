#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Rectangle {
  int h, w;
};

bool answer = false;

bool board[10][10] = {
    false,
};

bool isUsed[10] = {
    false,
};

int width, height;

bool isAllFilled() {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (!board[y][x]) return false;
    }
  }
  return true;
};

bool checkCanPlace(Rectangle &rec, int y, int x) {
  for (int i = 0; i < rec.h; i++) {
    for (int j = 0; j < rec.w; j++) {
      if (board[y + i][x + j]) {
        return false;
      }
    }
  }
  return true;
}

void recursive(vector<Rectangle> &recs, int y, int x) {
  if (answer) return;

  if (y == height) {
    if (isAllFilled()) {
      answer = true;
    }
    return;
  }

  int nx = x == width - 1 ? 0 : x + 1;
  int ny = nx == 0 ? y + 1 : y;

  if (board[y][x]) {
    recursive(recs, ny, nx);
  }

  for (int index = 0; index < recs.size(); index++) {
    if (isUsed[index]) continue;

    vector<Rectangle> curs = {recs[index], {recs[index].w, recs[index].h}};

    for (Rectangle &rec : curs) {
      if (y + rec.h > height || x + rec.w > width) continue;

      bool canPlace = checkCanPlace(rec, y, x);

      if (!canPlace) continue;
      for (int i = 0; i < rec.h; i++) {
        for (int j = 0; j < rec.w; j++) {
          board[y + i][x + j] = true;
        }
      }

      isUsed[index] = true;
      recursive(recs, y, x);
      isUsed[index] = false;

      for (int i = 0; i < rec.h; i++) {
        for (int j = 0; j < rec.w; j++) {
          board[y + i][x + j] = false;
        }
      }
    }
  }
}

bool solution(int h, int w, vector<Rectangle> &rectangles) {
  width = w;
  height = h;

  recursive(rectangles, 0, 0);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, H, W;
  cin >> N >> H >> W;

  vector<Rectangle> rectangles(N);
  for (int i = 0; i < N; i++) {
    cin >> rectangles[i].h >> rectangles[i].w;
  }

  bool answer = solution(H, W, rectangles);

  cout << (answer ? "Yes" : "No") << endl;

  return 0;
}