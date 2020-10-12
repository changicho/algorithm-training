# 17070. 파이프 옮기기 1

[링크](https://www.acmicpc.net/problem/17070)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   49.383    |

## 설계

### 시간 복잡도

현재 경우에서 2~3가지 경우로 탐색이 가능하다.

N = 16이며 벽이 없는 경우 모든 경우의 수는 12,648,486번이다. 이는 제한시간 1초 내에 가능하다.

(대략 어느정도 시간복잡도가 예상되는지 구하기 어려움)

정답의 경우의 수는 최대 1,000,000 가지 이내로 제한했으므로 완전탐색으로 풀 수 있다고 가정한다.

### 공간 복잡도

지도에서 나타내야 하는 정보는 2가지이다. (벽의 유무) 따라서 boolean으로 선언한다.

### 자료구조

```cpp
struct Axis {
  int y, x;
};

struct Pipe {
  Axis start, end;
  char status;
};

map<char, vector<pair<Axis, char>>> m = {{'-', {{{0, 1}, '-'}, {{1, 1}, '\\'}}},
                                         {'\\', {{{0, 1}, '-'}, {{1, 1}, '\\'}, {{1, 0}, '|'}}},
                                         {'|', {{{1, 1}, '\\'}, {{1, 0}, '|'}}}};
```

### 탐색

방향을 나타내는 문자열들을 각각 사용한다

```cpp
// -
// \
// |
```

또한 각 경우별로 앞으로 진행사항을 분기처리 할 수 있도록 map을 이용해 구성했으므로 이를 이용한다.

```cpp
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
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     184      |       0        |

## 고생한 점

### 시간초과

구현 자체는 맞더라도, recursive를 호출한 이후에 예외처리를 진행하는 경우 시간초과가 발생했다.

또한 코드 실행속도를 증가시키기 위해서는 방향 또한 char 형식이 아닌 int형으로 선언해 관리해야한다.
