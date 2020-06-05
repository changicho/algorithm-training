# 14500. 테트로미노

[링크](https://www.acmicpc.net/problem/14500)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   34.142    |

## 설계

### 시간 복잡도

두 가지 방법으로 풀이가 가능하다

1. dfs를 이용해 연속된 모양 탐색 후, T 자 모양 따로 처리
2. 모든 모양을 직접 탐색

1번 방법의 경우 한 좌표에서 dfs로 탐색을 할 때 4^4 만큼의 시간이 소요된다.

이를 좌표의 크기 500^2 번만큼 반복하는 경우 총 64,000,000 번 정도 소요되므로 제한시간 내에 충분하다.

2번 방법의 경우 발생 가능한 모든 경우는 다음과 같다. 이 떄 중복되는 경우는 제외한다.

(현재 위치에서 아래, 오른쪽 방향으로만 탐색)

- I : 2
- 네모 : 1
- L 모양 : 4
- T 모양 : 4
- Z 모양 : 4

이 경우 모든 모양을 탐색할 때 약 16번, 이를 모든 좌표 500^2 만큼 반복한다고 하면

총 4,000,000‬ 번 정도 소요된다.

두 방법 모두 제한시간 내에 풀이가 가능하다

### 공간 복잡도

지도에 숫자는 최대 1000 까지 이므로 int형으로 선언해도 충분하다.

또한 정답의 경우 최대 4000 까지 이므로 int형으로 선언한다.

지도 경우 모양의 튀어나온 부분에서 index 초과가 발생할 수 있으므로 지도를 상 하 좌 우로 여유분을 두고 계산한다.

상 하 좌 우로 4 이상씩 여분을 충분히 준다고 했을 때 크기는 510^2 의 int 형으로 선언할 수 있다.

### DFS를 이용한 방법

T 모양을 제외한 모든경우를 DFS를 이용해 탐색한다.

이때 완전한 중복을 줄이기 위해 처음 시작하는 경우 왼쪽 방향으로의 탐색은 건너뛴다.

```cpp
void dfs(int index, Axis cur, int count) {
  if (index == 4) {
    answer = max(answer, count);
    return;
  }

  int dir = 0;
  if (index == 0) {
    dir += 1;
  }

  for (; dir < 4; dir++) {
    Axis next = cur;
    next.x += dirs[dir].x;
    next.y += dirs[dir].y;

    if (next.x < 0 || next.x >= limit.x || next.y < 0 || next.y >= limit.y) {
      continue;
    }
    if (visited[next.y][next.x]) {
      continue;
    }

    visited[next.y][next.x] = true;
    dfs(index + 1, next, count + map[next.y][next.x]);
    visited[next.y][next.x] = false;
  }
};
```

T자 모양의 경우 직접 계산한다.

```cpp
// x축으로 증가하는 경우일 때
if (cur.x + 3 < limit.x) {
  int line =
      map[cur.y][cur.x] + map[cur.y][cur.x + 1] + map[cur.y][cur.x + 2];

  if (cur.y - 1 >= 0) {
    int temp = line + map[cur.y - 1][cur.x + 1];
    answer = max(answer, temp);
  }

  if (cur.y + 1 < limit.y) {
    int temp = line + map[cur.y + 1][cur.x + 1];
    answer = max(answer, temp);
  }
}
```

### 직접 모든 경우를 구현

모든 경우를 구현하는 경우 T자 모양을 계산한 것처럼 4개의 좌표의 값을 직접 더해준다.

```cpp
int temp = map[cur.y][cur.x] + map[cur.y][cur.x + 1] + map[cur.y][cur.x + 2] + map[cur.y - 1][cur.x + 1];
// 이와 같은 방법을 모든 경우에 탐색
```

이 때 중복되는 경우를 삭제하기 위해 현재 방향에서 오른쪽, 아래 로 진행하는 모양만 검사한다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     208      |       4        |

## 고생한 점
