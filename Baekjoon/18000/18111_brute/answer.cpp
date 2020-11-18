#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 2초 : 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
// 1초 : 인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.

int N, M, B;
int board[500][500];
int answerTime = 0;
int answerHeight = 0;

void calculate(int height) {
  int time = 0;
  int inventory = B;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      int diff = board[y][x] - height;

      // 깎아내야하는경우
      if (diff > 0) {
        time += 2 * diff;
        inventory += diff;
      } else {
        // 채워야하는 경우
        time += height - board[y][x];
        inventory -= height - board[y][x];
      }
    }
  }

  if (inventory < 0) return;

  if (answerTime > time) {
    answerTime = time;
    answerHeight = height;
  } else if (answerTime == time) {
    answerHeight = max(answerHeight, height);
  }
}

void solution() {
  int fromHeight = 256, toHeight = 0;

  cin >> N >> M >> B;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> board[y][x];

      fromHeight = min(fromHeight, board[y][x]);
      toHeight = max(toHeight, board[y][x]);

      answerTime += 2 * board[y][x];
    }
  }

  for (int height = fromHeight; height <= toHeight; height++) {
    calculate(height);
  }

  cout << answerTime << " " << answerHeight << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}