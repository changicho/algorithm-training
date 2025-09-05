#include <algorithm>
#include <climits>
#include <cmath>
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

struct Axis {
  long long y, x;

  bool operator==(Axis &a) const { return y == a.y && x == a.x; }

  Axis operator+(Axis &a) const { return {y + a.y, x + a.x}; }
};

struct Move {
  char dir;
  long long move;
};

long long calc(Axis a, Axis da, Axis b, Axis db, long long move) {
  long long diffY = a.y - b.y;
  long long diffX = a.x - b.x;
  long long vectorY = da.y - db.y;
  long long vectorX = da.x - db.x;

  if (vectorY == 0 && vectorX == 0) {
    return (diffY == 0 && diffX == 0) ? move : 0;
  }

  if (vectorY == 0) {
    // vertical
    if (diffY != 0) return 0;
    if (diffX % vectorX != 0) return 0;

    long long k = -diffX / vectorX;
    return (1 <= k && k <= move);
  } else if (vectorX == 0) {
    // horizontal
    if (diffX != 0) return 0;
    if (diffY % vectorY != 0) return 0;

    long long k = -diffY / vectorY;
    return (1 <= k && k <= move);
  }

  if (diffY % vectorY != 0 || diffX % vectorX != 0) return 0;
  long long k1 = -diffY / vectorY;
  long long k2 = -diffX / vectorX;

  if (k1 != k2) return 0;
  return (1 <= k1 && k1 <= move);
}

auto solution(Axis axisT, Axis axisA, deque<Move> &movesT, deque<Move> &movesA,
              long long totalMoves) {
  long long answer = 0;

  unordered_map<char, Axis> dirs = {
      {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

  while (!movesT.empty() && !movesA.empty()) {
    Axis dirT = dirs[movesT.front().dir];
    Axis dirA = dirs[movesA.front().dir];
    long long moveCount = min(movesT.front().move, movesA.front().move);

    Move movesTFront = movesT.front();
    Move movesAFront = movesA.front();
    movesT.pop_front();
    movesA.pop_front();

    if (movesTFront.move < movesAFront.move) {
      movesAFront.move -= moveCount;
      movesA.push_front(movesAFront);
    } else if (movesTFront.move > movesAFront.move) {
      movesTFront.move -= moveCount;
      movesT.push_front(movesTFront);
    }

    long long step = calc(axisT, dirT, axisA, dirA, moveCount);
    answer += step;

    dirT.y *= moveCount;
    dirT.x *= moveCount;
    dirA.y *= moveCount;
    dirA.x *= moveCount;

    Axis nextT = axisT + dirT;
    Axis nextA = axisA + dirA;

    axisT = nextT;
    axisA = nextA;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  Axis T, A;

  cin >> T.y >> T.x;
  cin >> A.y >> A.x;

  long long N;
  long long M, L;
  cin >> N >> M >> L;

  deque<Move> tMoves, aMoves;

  for (long long i = 0; i < M; i++) {
    Move move;
    cin >> move.dir >> move.move;
    tMoves.push_back(move);
  }
  for (long long i = 0; i < L; i++) {
    Move move;
    cin >> move.dir >> move.move;
    aMoves.push_back(move);
  }

  auto answer = solution(T, A, tMoves, aMoves, N);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}