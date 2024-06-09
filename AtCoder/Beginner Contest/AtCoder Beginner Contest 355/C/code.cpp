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

int solution(int n, int time, vector<int> &a) {
  vector<vector<bool>> board(n, vector<bool>(n, false));

  for (int i = 0; i < time; i++) {
    int target = a[i] - 1;

    int y = target / n;
    int x = target % n;

    board[y][x] = true;

    bool isColMarked = true;
    for (int y = 0; y < n; y++) {
      if (!board[y][x]) {
        isColMarked = false;
        break;
      }
    }
    bool isRowMarked = true;
    for (int x = 0; x < n; x++) {
      if (!board[y][x]) {
        isRowMarked = false;
        break;
      }
    }
    bool isDiagonalMarked = true;
    for (int i = 0; i < n; i++) {
      if (!board[i][i]) {
        isDiagonalMarked = false;
        break;
      }
    }
    bool isReverseDiagonalMarked = true;
    for (int i = 0; i < n; i++) {
      if (!board[i][n - i - 1]) {
        isReverseDiagonalMarked = false;
        break;
      }
    }

    if (isColMarked || isRowMarked || isDiagonalMarked ||
        isReverseDiagonalMarked) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, T;
  cin >> N >> T;

  vector<int> A(T);
  for (int i = 0; i < T; i++) {
    cin >> A[i];
  }

  int answer = solution(N, T, A);

  cout << answer << endl;

  return 0;
}