# 15684. 사다리 조작

[링크](https://www.acmicpc.net/problem/15684)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   20.632    |

## 설계

### 시간 복잡도

N = 10, H = 30 까지 입력받을 수 있다.

최대 3개까지 사다리를 놓을 수 있으므로, 모든 경우를 탐색할 경우 최악의 경우 시간 복잡도는 300^3 정도이다.

이는 27,000,000 정도이며 제한시간 2초를 초과한다. 따라서 백트래킹을 이용해 탐색을 제한한다.

### 공간 복잡도

사다리의 유무를 판단할 boolean 배열을 선언한다.

### 풀이

현재 좌표에서 다음 x좌표 (x+1)에 사다리를 놓을 수 있는지 판단하는것으로 탐색을 이어나갔다.

```cpp
void recursive(int y, int x, int count) {
  if (count > 3) return;
  if (count >= answer) return;

  if (isFine()) {
    answer = min(count, answer);
  }

  for (int i = y; i <= H; i++, x = 1) {
    for (int j = x; j < N; j++) {
      if (board[i][j] != 0 || board[i][j + 1] != 0) {
        continue;
      }

      board[i][j] = j + 1;
      board[i][j + 1] = j;
      recursive(i, j, count + 1);
      board[i][j] = 0;
      board[i][j + 1] = 0;
    }
  }
}
```

사다리의 유무는 각 좌표의 값이 0이 아닌 경우 해당 x축으로 이동할 수 있음을 표시하도록했다.

따라서 사다리의 이동은 다음과 같다.

```cpp
int goDown(int start) {
  int cur = start;
  for (int h = 1; h <= H; h++) {
    if (board[h][cur] != 0) {
      cur = board[h][cur];
    }
  }
  return cur;
}

bool isFine() {
  for (int x = 1; x <= N; x++) {
    if (goDown(x) != x) return false;
  }
  return true;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     840      |       0        |

## 고생한 점

현재 좌표에서 사다리를 놓을지 말지로 분기처리를 하는 경우 시간초과가 발생함.
