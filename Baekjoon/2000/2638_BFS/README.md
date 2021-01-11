# 2638. 치즈

[링크](https://www.acmicpc.net/problem/2638)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   45.606    |

## 설계

### 시간 복잡도

모눈종이의 크기는 N ≤ 100, M ≤ 100 까지이다. (N 세로, M 가로)

각 상황마다 바깥 공기에 닿은 치즈가 산화하므로 BFS를 이용해 산화를 탐지해야 한다.

BFS의 시간 복잡도는 각 노드의 개수에 4 방향을 곱한 값이므로

```cpp
100 * 100 * 4 = 40,000
```

이다.

이를 최악의 경우 100번까지 반복하므로 최악의 경우 시간 복잡도는

```cpp
4,000,000
```

이므로 제한 시간 1초 내에 충분하다.

### 공간 복잡도

정답은 최악의 경우 100 이하임이 보장되므로 int형으로 선언한다.

각 치즈별로 공기와 맞닿은 면적의 개수는 최대 4개이다.

따라서 2차원 배열들 또한 int형으로 선언한다.

### 너비우선탐색

치즈의 개수가 0개가 될 때 까지 BFS 탐색을 반복한다.

BFS 이후 매 경우 공기와 2면 이상 맞닿은 치즈들을 찾을때 직접 탐색하지 않기 위해서 산화 할 때마다 체크한다.

```cpp
int answer = 0;
while (cheeseCount != 0) {
  answer += 1;

  bool visited[100][100] = {
      false,
  };
  int count[100][100] = {
      0,
  };

  vector<Axis> deletes;
  queue<Axis> q;
  q.push({0, 0});

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (visited[cur.y][cur.x]) continue;
    visited[cur.y][cur.x] = true;

    for (Axis dir : dirs) {
      Axis next = cur;
      next.y += dir.y;
      next.x += dir.x;

      if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M) continue;
      if (board[next.y][next.x] == 1) {
        if (count[next.y][next.x] < 1) {
          count[next.y][next.x] += 1;
        } else {
          deletes.push_back(next);
        }
        continue;
      }

      q.push(next);
    }
  }

  for (Axis target : deletes) {
    if (board[target.y][target.x] == true) {
      cheeseCount -= 1;
      board[target.y][target.x] = false;
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      16      |       0        |

## 고생한 점
