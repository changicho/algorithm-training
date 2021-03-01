# 14939. 불 끄기

[링크](https://www.acmicpc.net/problem/14939)

|   난이도   | 정답률(\_%) | 시간 제한(초) |
| :--------: | :---------: | :-----------: |
| Platinum V |   46.167    |       1       |

## 설계

### 시간 복잡도

전구의 총 개수는 10^2 이다.

모든 경우를 비교해 볼 경우 2^(100) 만큼 비교해야 하며 이는 제한시간 내에 불가능하다.

따라서 그리디한 방법으로 전구를 켜 시간 복잡도를 최적화 해야 한다.

### 공간 복잡도

정답의 개수는 100^2 이하임이 보장된다.

다만 정답이 불가능한 경우 또한 고려해야 한다.

### 불 끄기 - 그리디 알고리즘

첫 줄에 전구를 어떤 방식으로 뒤집는 걸 결정을 했다고 가정하자.

현재 좌표에서 바로 위의 전구가 켜져 있는지 여부에 따라서 toggle 여부를 판별한다.

- 현재 좌표가 (y, x) 일 때, (y - 1, x) 좌표의 전구가 불이 켜져있으면 현재 좌표의 불을 킨다.

첫 줄의 경우는 브루트 포스 방법을 적용하기 위해서 첫 줄을 뒤집는 모든 경우 (2^10)를 시작점으로 설정한다.

그 이후 y축을 증가시키며 탐색을 진행하며 그리디한 방법으로 전구를 뒤집어주어 최적의 답을 구한다.

이후 맨 마지막 줄의 불이 모두 꺼져 있는 경우는 모든 불이 꺼져있다는 뜻이므로 그때 정답을 갱신한다.

### 비트마스크

한 줄에 전구의 개수는 10개 이므로 2^10 크기의 숫자로 비트마스킹을 이용할 수 있다.

처음 입력을 받을 때 비트를 설정한다.

```cpp
for (int y = 0; y < 10; y++) {
  cin >> line;

  for (int x = 0; x < 10; x++) {
    if (line[x] == 'O') {
      board[y] |= (1 << (10 - x - 1));
    }
  }
}
```

toggle의 경우 xor을 이용해 구현한다.

```cpp
void toggle(Axis axis) {
  int y = axis.y, x = axis.x;
  temp_board[y] ^= (1 << (10 - x - 1));

  if (y > 0) {
    temp_board[y - 1] ^= (1 << (10 - x - 1));
  }
  if (y < 10 - 1) {
    temp_board[y + 1] ^= (1 << (10 - x - 1));
  }
  if (x > 0) {
    temp_board[y] ^= (1 << (10 - x));
  }
  if (x < 10 - 1) {
    temp_board[y] ^= (1 << (10 - x - 2));
  }
}
```

이후 비트 마스크의 모든 경우에 대해 탐색을 진행한다.

```cpp
int answer = -1;

for (int bitMask = (1 << 10) - 1; bitMask >= 0; bitMask--) {
  int count = 0;

  for (int y = 0; y < 10; y++) {
    temp_board[y] = board[y];
  }

  // y == 0 인 경우
  for (int x = 0; x < 10; x++) {
    if (bitMask & (1 << (10 - x - 1))) {
      toggle({0, x});

      count++;
    }
  }

  for (int y = 1; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      // {y - 1, x} 좌표의 전구가 불이 켜져있을때
      if (temp_board[y - 1] & (1 << (10 - x - 1))) {
        toggle({y, x});

        count++;
      }
    }
  }

  if (temp_board[10 - 1] == 0) {
    if (answer == -1) {
      answer = count;
    } else {
      answer = min(answer, count);
    }
  }
}
```

### 2차원 배열을 이용한 방법

2차원 배열을 이용해 board를 구현한다.

```cpp
string line;
for (int y = 0; y < 10; y++) {
  cin >> line;
  for (int x = 0; x < 10; x++) {
    board[y][x] = line[x] == 'O' ? true : false;
  }
}
```

toggle의 경우 다음과 같이 구현한다.

```cpp
void toggle(Axis axis) {
  int y = axis.y, x = axis.x;

  temp_board[y][x] = !temp_board[y][x];

  for (Axis dir : dirs) {
    Axis next = axis;
    next.y += dir.y;
    next.x += dir.x;

    if (next.y < 0 || next.y >= 10 || next.x < 0 || next.x >= 10) continue;
    temp_board[next.y][next.x] = !temp_board[next.y][next.x];
  }
}
```

이후 첫줄의 모든 경우는 비트마스크를 이용해 구현하고, 나머지는 2차원 배열을 이용해 구현한다.

```cpp
int answer = -1;

for (int bitMask = (1 << 10) - 1; bitMask >= 0; bitMask--) {
  int count = 0;

  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      temp_board[y][x] = board[y][x];
    }
  }

  // y == 0 인 경우
  for (int x = 0; x < 10; x++) {
    if (bitMask & (1 << (10 - x - 1))) {
      toggle({0, x});

      count++;
    }
  }

  for (int y = 1; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      // {y - 1, x} 좌표의 전구가 불이 켜져있을때
      if (temp_board[y - 1][x]) {
        toggle({y, x});

        count++;
      }
    }
  }

  int onCount = 0;
  for (int x = 0; x < 10; x++) {
    if (temp_board[10 - 1][x]) {
      onCount += 1;
    }
  }

  if (onCount == 0) {
    if (answer == -1) {
      answer = count;
    } else {
      answer = min(answer, count);
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
