#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define endl '\n';

using namespace std;

struct Axis {
  int y, x;
};

struct Pipe {
  Axis start, end;
  char status;
};

int answer = 0;
Axis limit;
bool board[16][16];

map<char, vector<pair<Axis, char>>> m = {{'-', {{{0, 1}, '-'}, {{1, 1}, '\\'}}},
                                         {'\\', {{{0, 1}, '-'}, {{1, 1}, '\\'}, {{1, 0}, '|'}}},
                                         {'|', {{{1, 1}, '\\'}, {{1, 0}, '|'}}}};

void recursive(Pipe pipe) {
  for (pair<Axis, char> move : m[pipe.status]) {
    Pipe next = {pipe.end, {pipe.end.y + move.first.y, pipe.end.x + move.first.x}, move.second};

    if (next.end.y > limit.y || next.end.x > limit.x) continue;
    if (board[next.end.y][next.end.x]) continue;
    if (next.status == '\\' && (board[next.start.y][next.start.x + 1] || board[next.start.y + 1][next.start.x])) continue;

    if (next.end.y == limit.y && next.end.x == limit.x) {
      answer += 1;
      continue;
    }

    recursive(next);
  }
}

void solution() {
  int N;
  cin >> N;

  limit.y = limit.x = N - 1;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];
    }
  }

  Pipe pipe = {{0, 0}, {0, 1}, '-'};
  recursive(pipe);

  cout << answer << endl;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}