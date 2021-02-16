# 1987. 알파벳

[링크](https://www.acmicpc.net/problem/1987)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold IV |   29.492    |       2       |

## 설계

### 시간 복잡도

가로와 세로의 최대 크기는 각각 20 까지이다.

모든 경우를 탐색할 때 시간 복잡도는 (20^2)^4 가량 된다. (중복된 경로로 계속 이동 할 수 있으므로)

따라서 불가능한 경우는 백트래킹을 이용해 탐색을 중지한다.

### 공간 복잡도

정답의 수는 최대 20^2 이하이다. 이는 int형으로 충분하다.

### 깊이 우선 탐색

각 경우마다 현재 알파벳을 true로 놓은 상태에서 탐색을 진행한다.

다음 상태로 넘어갈 때 조건에 맞지 않는경우 건너뛴다.

```cpp
void recursive(Axis cur, bool alpha_visited[], int count) {
  answer = max(answer, count);

  alpha_visited[board[cur.y][cur.x]] = true;
  for (Axis dir : dirs) {
    Axis next = cur;
    next.y += dir.y;
    next.x += dir.x;

    if (!isSafe(next)) continue;
    char alpha = board[next.y][next.x];
    if (alpha_visited[alpha]) continue;

    recursive(next, alpha_visited, count + 1);
  }
  alpha_visited[board[cur.y][cur.x]] = false;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     508      |       4        |

## 고생한 점
