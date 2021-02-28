# 17143. 낚시왕

[링크](https://www.acmicpc.net/problem/17143)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   22.747    |       1       |

## 설계

### 시간 복잡도

보드의 크기는 최대 100^2, 상어의 갯수는 최대 100^2 이다.

각 경우마다 시뮬레이션을 돌려야한다.

각 연산마다 시간 복잡도는 다음과 같다.

- 탐색 경우 : O(100)
- 제거할 상어를 찾음 : O(100)
- 상어의 이동 : O(100^2 \* 1000)
- 상어 잡아먹히는 여부 판별 : O(100^2)
- 살아남은 상어 판별 : O(100^2);

이때 상어의 이동을 최적화 하지 않는 경우 최악의 경우 시간복잡도는 O(100^3 \* 1000)이 되고 이는 1,000,000,000이 되어 제한시간 내에 불가능하다.

따라서 상어의 이동을 최적화해야한다.

### 공간 복잡도

정답의 개수는 최대 100까지이므로 int형으로 선언한다.

### 시뮬레이션

우선 각 구조체를 만든다.

```cpp
struct Axis {
  int y, x;
};

struct Shark {
  bool isExist; // 제거되었는지 여부
  Axis axis;    // 현재 위치
  Axis dir;     // 이동하는 방향
  int speed;    // 속도
  int size;     // 크기
};
```

이 때 상어들을 입력받으며 상어의 속도를 최적화해야한다.

만약 상어가 이동하는 속도가 해당 방향으로의 크기의 2배 이상인 경우 불필요한 이동을 반복하기 때문에 mod 연산을 이용해 최적화해준다.

```cpp
if (shark.dir.y == 0) {
  shark.speed %= 2 * (C - 1);
}
if (shark.dir.x == 0) {
  shark.speed %= 2 * (R - 1);
}
```

그리고 낚시꾼의 위치를 이동시키며 상어를 잡는다.

```cpp
for (int position = 0; position < C; position += 1) {
  // 상어 잡기

  // 상어 이동

  // 상어 잡아먹히기

  // 남은 상어 추출

  // 보드 갱신
}
```

상어를 잡는 동작은 다음과 같이 구현한다.

```cpp
for (int y = 0; y < R; y++) {
  if (board[y][position] != -1) {
    int delete_target = board[y][position];
    board[y][position] = -1;

    answer += sharks[delete_target].size;
    sharks[delete_target].isExist = false;
    break;
  }
}
```

다음으로 살아남은 상어들로만 이루어진 vector를 만든다.

상어를 이동시킬 때 이미 잡힌 상어의 경우 이동시키지 않고, 이동한 상어 vector에서 제외한다.

```cpp
vector<Shark> new_sharks;
for (Shark shark : sharks) {
  if (!shark.isExist) continue;

  for (int move = 0; move < shark.speed; move++) {
    if ((shark.axis.x == 0 && shark.dir.x == -1) || (shark.axis.x == C - 1 && shark.dir.x == 1)) {
      shark.dir.x *= -1;
    }
    if ((shark.axis.y == 0 && shark.dir.y == -1) || (shark.axis.y == R - 1 && shark.dir.y == 1)) {
      shark.dir.y *= -1;
    }

    shark.axis.x += shark.dir.x;
    shark.axis.y += shark.dir.y;
  }

  new_sharks.push_back(shark);
}
```

다음으로 상어가 잡아먹히는 것을 구현한다.

보드에 겹쳐지면 상어가 잡아먹히는 것이므로 기존 보드를 초기화 하고 겹치는지 판별한다.

```cpp
clearBoard();
for (int index = 0; index < new_sharks.size(); index++) {
  Shark shark = new_sharks[index];
  Axis axis = shark.axis;

  if (board[axis.y][axis.x] == -1) {
    board[axis.y][axis.x] = index;
  } else {
    int target = board[axis.y][axis.x];
    if (new_sharks[target].size > shark.size) continue;

    board[axis.y][axis.x] = index;
  }
}
```

다음으로 잡아먹히지 않은 남은 상어들을 추출한다.

```cpp
sharks.clear();
sharks.resize(0);
for (int y = 0; y < R; y++) {
  for (int x = 0; x < C; x++) {
    if (board[y][x] != -1) {
      int target = board[y][x];
      sharks.push_back(new_sharks[target]);
    }
  }
}
clearBoard();
```

다음으로 기존 상어 배열의 index에 맞춰 board를 초기화한다.

```cpp
for (int index = 0; index < sharks.size(); index++) {
  Shark shark = sharks[index];
  Axis axis = shark.axis;

  board[axis.y][axis.x] = index;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     192      |       8        |

## 고생한 점
