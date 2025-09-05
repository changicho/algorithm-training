# D - RLE Moving

[링크](https://atcoder.jp/contests/abc421/tasks/abc421_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

전체 이동의 수를 N, takahashi, aoki의 이동 횟수를 각각 M, L이라 하자.

모든 경우를 직접 시뮬레이션 할 경우 O(N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다 (N <= 10^14)

각자의 이동 횟수에서 압축해서 이동을 시뮬레이션 할 수 있다. 이 경우 O(M + L)의 시간 복잡도를 사용한다.

이 과정에서 각 이동에서 겹치는 횟수를 세는 데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 이동 정보를 저장하는데 O(M + L)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      21      |  O(M + L)   |  O(M + L)   |

타카하시를 T, 아오키를 A라 하자.

A와 T의 이동 횟수가 다음과 같을 수 있다.

- LLLUURRRR
- DUUUUUULL

이 경우 서로 방향이 바뀌는 경우에 대해서 커팅해 다음과 같이 이동을 압축시킬 수 있다.

- L/LL/UU/RR/RR
- D/UU/UU/UU/LL

(각자 방향이 바뀔 때마다 A,T의 이동을 나누며 5개의 이동으로 압축됨)

나눠진 이동에 대해서 A,T에 대해서 이동을 시뮬레이션 하며 이 때 서로 좌표가 얼마나 겹치는지에 대해서 구하고 정답에 더한다.

이 때 이동이 겹치는 경우를 다음과 같이 나눌 수 있다.

- 서로 직교하는 경우 (한쪽은 수평, 한쪽은 수직)
- 서로 시작점과 끝점이 같은 경우
- 서로 평행한 경우

또한 각 A,T의 이동에 대해서 이동하는 거리와 실제 만나기 위해 이동하는 횟수의 차이를 구해 만날 수 있는지 판별한다.

```cpp
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

auto solution(Axis axisT, Axis axisA, deque<Move> &movesT, deque<Move> &movesA, long long totalMoves) {
  long long answer = 0;

  unordered_map<char, Axis> dirs = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

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
```

## 고생한 점
