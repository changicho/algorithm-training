# 17144. 미세먼지 안녕!

[링크](https://www.acmicpc.net/problem/17144)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   53.613    |

## 설계

### 시간 복잡도

시간은 최대 1000 까지, 지도의 크기는 최대 50^2 까지이다.

각 경우마다 먼지의 증가, 공기청정기 순환을 수행하는데 들어가는 시간 복잡도는 대략

50^2를 4번 정도 수행한다고 가정하자.

최악의 경우 시간 복잡도는

```cpp
50^2 * 4 * 1000 = 10,000,000
```

이므로 제한시간 내에 충분하다.

### 공간 복잡도

미세 먼지의 입력되는 최대 값은 1000 이다.

강 경우마다 1000 이상이 되는 경우는 존재하지 않으므로, int형으로 선언한다.

4방향 비교 및 공기청정기는 struct를 이용해 구현한다.

```cpp
struct Axis {
  int y, x;
};

struct AirCleaner {
  Axis upper, lower;
};
```

### 회전의 구현

사각형의 4면을 한칸씩 회전하기 위해 4번의 반복문을 이용해 구현했다.

이 때 끝칸에서 부터 한칸씩 당기는 것에 유의한다.

또한 인자로 받은 좌표를 이용해야 함에 유의한다.

```cpp
void ClockWise(Axis start) {
  for (int y = start.y + 1; y < limit.y - 1; y += 1) {
    board[y][start.x] = board[y + 1][start.x];
  }
  for (int x = 0; x < limit.x - 1; x += 1) {
    board[limit.y - 1][x] = board[limit.y - 1][x + 1];
  }
  for (int y = limit.y - 1; y > start.y; y -= 1) {
    board[y][limit.x - 1] = board[y - 1][limit.x - 1];
  }
  for (int x = limit.x - 1; x > start.x; x -= 1) {
    board[start.y][x] = board[start.y][x - 1];
  }
  board[start.y][start.x] = -1;
  board[start.y][start.x + 1] = 0;
}

void CounterClockWise(Axis start) {
  for (int y = start.y; y > 0; y -= 1) {
    board[y][start.x] = board[y - 1][start.x];
  }
  for (int x = start.x; x < limit.x - 1; x += 1) {
    board[0][x] = board[0][x + 1];
  }
  for (int y = 0; y < start.y; y += 1) {
    board[y][limit.x - 1] = board[y + 1][limit.x - 1];
  }
  for (int x = limit.x - 1; x > start.x + 1; x -= 1) {
    board[start.y][x] = board[start.y][x - 1];
  }
  board[start.y][start.x] = -1;
  board[start.y][start.x + 1] = 0;
}
```

### 먼지의 증가

먼지가 증가해야 하는 경우는 다음과 같다

현재 칸의 먼지를 5로 나눈 값의 몫이 1 이상인 경우.

또한 먼지의 증가는 모든 칸에서 동시에 일어나므로 증가해야할 먼지들의 배열을 만들고 이후에 한꺼번에 증가시켜야 한다.

```cpp
vector<Axis> dusts;
for (int y = 0; y < R; y++) {
  for (int x = 0; x < C; x++) {
    if (board[y][x] > 0) dusts.push_back({y, x});
  }
}

int diff[50][50] = {
    0,
};
for (Axis cur : dusts) {
  int count = board[cur.y][cur.x] / 5;
  if (count == 0) continue;

  for (Axis dir : dirs) {
    Axis next = cur;
    next.y += dir.y;
    next.x += dir.x;

    if (next.y < 0 || next.y >= R || next.x < 0 || next.x >= C) continue;
    if (board[next.y][next.x] == -1) continue;

    diff[next.y][next.x] += count;
    diff[cur.y][cur.x] -= count;
  }
}

for (int y = 0; y < R; y++) {
  for (int x = 0; x < C; x++) {
    board[y][x] += diff[y][x];
  }
}
```

### 전체 알고리즘

```cpp
for(int time < 0; time < T; time++){
  // 먼지의 증가
  // 공기청정기 회전
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      44      |       12       |

## 고생한 점
