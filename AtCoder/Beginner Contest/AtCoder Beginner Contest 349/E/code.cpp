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

int lines[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                   {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

string solution(vector<long long>& board) {
  int colors[9] = {0};

  // turn : +1 -> Takahashi, -1 -> Aoki
  function<long long(int, long long, int)> recursive =
      [&](int turn, long long point, int step) -> int {
    for (auto& line : lines) {
      if (colors[line[0]] == 0) continue;

      bool hasLine = colors[line[0]] == colors[line[1]] &&
                     colors[line[1]] == colors[line[2]];

      if (hasLine) {
        return colors[line[0]];
      }
    }

    if (step == 9) {
      if (point < 0) return -1;
      return +1;
    }

    for (int axis = 0; axis < 9; axis++) {
      if (colors[axis] != 0) continue;
      colors[axis] = turn;

      long long nextScore = point + turn * board[axis];
      if (recursive(-turn, nextScore, step + 1) == turn) {
        colors[axis] = 0;
        return turn;
      }

      colors[axis] = 0;
    }

    // lose case
    return -turn;
  };

  bool answer = recursive(1, 0, 0) == 1;
  return answer ? "Takahashi " : "Aoki ";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  vector<long long> A(9);
  for (int i = 0; i < 9; i++) {
    cin >> A[i];
  }

  string answer = solution(A);
  cout << answer << endl;

  return 0;
}