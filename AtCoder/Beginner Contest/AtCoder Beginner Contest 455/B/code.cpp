#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(int rows, int cols, vector<string>& board) {
  int answer = 0;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      for (int yy = y; yy < rows; yy++) {
        for (int xx = x; xx < cols; xx++) {
          bool isAllSame = true;

          for (int i = y; i <= yy; i++) {
            for (int j = x; j <= xx; j++) {
              char target = board[y + yy - i][x + xx - j];
              if (board[i][j] != target) isAllSame = false;
            }
          }

          answer += isAllSame;
        }
      }
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int H, W;
  cin >> H >> W;

  vector<string> board(H);
  for (int i = 0; i < H; i++) {
    cin >> board[i];
  }

  auto answer = solution(H, W, board);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}