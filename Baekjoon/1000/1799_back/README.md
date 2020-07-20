# 1799. 비숍

[링크](https://www.acmicpc.net/problem/1799)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold II |   23.914    |

## 설계

### 시간 복잡도

체스판의 크기는 최대 10^2 이다.

모든 경우를 탐색하는 경우 2^(10^2) 번 만큼 수행해야 하며, 이는 제한시간 내에 불가능하다.

따라서 체스판을 흰색과 검은색으로 나눠 탐색해야 한다.

비숍의 특성 때문에 이 방법을 사용할 수 있는데, 비숍은 놓인칸의 색과 같은 색의 부분만 영향을 끼치기 때문이다.

따라서 시간 복잡도는

```cpp
2^(5^2) + 2^(5^2) = 33,554,432 * 2 = 67,108,864
```

이므로 제한 시간 내에 충분하다.

### 공간 복잡도

표현해야 할 정보는 다음과 같다.

- 체스판의 색정보
- 체스판에 비숍이 있는지 없는지 정보
- 체스판에 말을 놓을 수 있는지 정보

위 3가지 요소는 전부 boolean으로 관리할 수 있다.

따라서 boolean 2차원 배열을 3개 만들어관리한다.

### 비숍

비숍이 놓일 수 있는지 여부는 다음과 같이 판단한다.

- 대각선 4방향으로 진행해가며 비숍이 있는지 판단한다.

```cpp
bool isSafe(Axis axis) {
  return !(axis.x < 0 || axis.x >= N || axis.y < 0 || axis.y >= N);
}

bool canLocate(Axis axis) {
  for (Axis dir : moves) {
    Axis next = axis;

    while (isSafe(next)) {
      if (board[next.y][next.x]) {
        return false;
      }
      next.y += dir.y;
      next.x += dir.x;
    }
  }
  return true;
}
```

### backtracking

DFS로 탐색할 때, 탐색해야 하는 색을 인자로 받는다.

그리고 탐색할 때 탐색해야 하는 색 부분만 탐색을 진행한다.

그리고 좌표를 순서대로 탐색해야 하므로, 좌표에 계산에 대한 처리가 필요하다.

x좌표 부터 탐색하고, 끝에 다다르면 y좌표를 증가시키는 방식으로 구현했으므로,

```cpp
Axis next = axis;
next.x += 1;
if (next.x == N) {
  next.x = 0;
  next.y += 1;
}
```

따라서 dfs는 다음과 같다.

```cpp
void dfs(Axis axis, int count, bool color_target) {
  if (axis.y == N) {
    answer = max(count, answer);
    return;
  }

  Axis next = axis;
  next.x += 1;
  if (next.x == N) {
    next.x = 0;
    next.y += 1;
  }

  if (canVisit[axis.y][axis.x] && color[axis.y][axis.x] == color_target && canLocate(axis)) {
    board[axis.y][axis.x] = true;
    dfs(next, count + 1, color_target);
    board[axis.y][axis.x] = false;
  }

  dfs(next, count, color_target);
}
```

마지막으로 dfs를 각 색상 별로 2번 호출해준다.

이 떄 두번쨰 호출 전, answer를 초기화 해야 함에 유의한다.

```cpp
dfs({0, 0}, 0, true);
answerT += answer;
answer = 0;
dfs({0, 0}, 0, false);
answerT += answer;
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     124      |       0        |

## 고생한 점

DFS탐색 시 next 좌표에 비숍을 놓을 수 있는지 여부만 판단했으므로, 0,0 좌표에 비숍을 놓지 못하는 오류가 발생했다.
