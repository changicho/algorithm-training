#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define DIV 1000000007
#define SIZE 8

using namespace std;

vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b) {
  vector<vector<long long>> ret(SIZE, vector<long long>(SIZE, 0));

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      for (int k = 0; k < SIZE; k++) {
        ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]) % DIV;
      }
    }
  }
  return ret;
}

vector<vector<long long>> powMatrix(vector<vector<long long>> a, int n) {
  vector<vector<long long>> ret(SIZE, vector<long long>(SIZE, 0));

  for (int i = 0; i < SIZE; i++) {
    ret[i][i] = 1;
  }

  while (n > 0) {
    if (n % 2 == 1) {
      ret = multiply(ret, a);
    }

    n /= 2;
    a = multiply(a, a);
  }

  return ret;
}

void solution() {
  int D;
  cin >> D;

  vector<vector<long long>> board = {
      {0, 1, 0, 0, 1, 0, 0, 0},
      {1, 0, 1, 0, 1, 0, 0, 0},
      {0, 1, 0, 1, 1, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 1, 0},
      {1, 1, 1, 0, 0, 0, 1, 0},
      {0, 0, 0, 1, 0, 0, 0, 1},
      {0, 0, 1, 1, 1, 0, 0, 1},
      {0, 0, 0, 0, 0, 1, 1, 0}};

  board = powMatrix(board, D);

  cout << board[0][0] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}