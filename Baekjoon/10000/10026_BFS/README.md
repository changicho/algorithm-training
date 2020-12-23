# 10026. 적록색약

[링크](https://www.acmicpc.net/problem/10026)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   58.136    |

## 설계

### 시간 복잡도

N은 최대 100까지이다. BFS를 이용해 구역들의 수를 확인할 수 있으므로 이를 통해 탐색을 진행하는 경우

한번의 BFS당 시간 복잡도는 O(40,000) 이다.

정상과 색맹의 경우 두번 BFS를 실행해야 하므로 최악의 경우 시간 복잡도는 O(80,000) 이며 이는 제한시간 내에 충분하다.

### 공간 복잡도

색상의 경우 띄어쓰기 없이 바로 들어오므로 string 배열을 이용해 2차원 좌표를 관리한다.

count의 경우 최악의 경우도 100을 넘지 않으므로 int형으로 선언한다.

### BFS

```cpp
int BFS(bool isDisabled) {
  bool visited[100][100] = {
      false,
  };
  int count = 0;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (visited[y][x]) continue;

      char color = board[y][x];
      queue<Axis> q;
      q.push({y, x});
      count += 1;

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;

        for (Axis dir : dirs) {
          Axis next = cur;
          next.y += dir.y;
          next.x += dir.x;

          if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) continue;

          if (!isDisabled) {
            if (board[next.y][next.x] != color) continue;

            q.push(next);
          } else {
            if ((color == 'R' && board[next.y][next.x] == 'G') || (color == 'G' && board[next.y][next.x] == 'R')) {
              q.push(next);

              continue;
            }
            if (board[next.y][next.x] != color) continue;

            q.push(next);
          }
        }
      }
    }
  }

  return count;
}
```

여기서 좌표의 중복 처리를 제대로 하지 않는경우 메모리 초과가 발생한다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
