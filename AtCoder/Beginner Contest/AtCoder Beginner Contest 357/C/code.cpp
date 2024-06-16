#include <algorithm>
#include <cmath>
#include <functional>
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

vector<string> solution(int n) {
  vector<string> board(pow(3, n), string(pow(3, n), '#'));

  function<void(int, int, int)> recursive = [&](int n, int x, int y) {
    if (n == 0) {
      board[y][x] = '#';
      return;
    }

    int size = pow(3, n - 1);
    recursive(n - 1, x, y);
    recursive(n - 1, x + size, y);
    recursive(n - 1, x + size * 2, y);

    recursive(n - 1, x, y + size);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        board[y + size + i][x + size + j] = '.';
      }
    }
    recursive(n - 1, x + size * 2, y + size);

    recursive(n - 1, x, y + size * 2);
    recursive(n - 1, x + size, y + size * 2);
    recursive(n - 1, x + size * 2, y + size * 2);
  };

  recursive(n, 0, 0);

  return board;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<string> answer = solution(N);

  for (string &line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}