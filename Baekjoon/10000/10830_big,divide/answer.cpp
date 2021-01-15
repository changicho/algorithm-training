#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > origin;
int N;

vector<vector<int> > multiplyMatrix(vector<vector<int> > matrixA, vector<vector<int> > matrixB) {
  vector<vector<int> > temp(N);
  for (int i = 0; i < N; i++) {
    temp[i].resize(N, 0);
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      int sum = 0;

      for (int i = 0; i < N; i++) {
        sum += matrixA[y][i] * matrixB[i][x];
        sum %= 1000;
      }

      temp[y][x] = sum;
    }
  }

  return temp;
}

vector<vector<int> > squaredMatrix(long long N, vector<vector<int> > matrix) {
  if (N == 1) {
    return matrix;
  }

  vector<vector<int> > targetA = squaredMatrix(N / 2, matrix);

  vector<vector<int> > ret = multiplyMatrix(targetA, targetA);
  if (N % 2 == 1) {
    ret = multiplyMatrix(ret, origin);
  }
  return ret;
}

void solution() {
  vector<vector<int> > board;
  long long B;

  cin >> N >> B;

  origin.resize(N);
  for (int i = 0; i < N; i++) {
    origin[i].resize(N, 0);
  }

  board.resize(N);
  for (int i = 0; i < N; i++) {
    board[i].resize(N, 0);
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];
      origin[y][x] = board[y][x];
    }
  }

  vector<vector<int> > answer = squaredMatrix(B, board);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cout << answer[y][x] % 1000 << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}