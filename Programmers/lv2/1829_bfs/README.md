# 1829. 카카오프렌즈 컬러링북

[링크](https://programmers.co.kr/learn/courses/30/lessons/42578)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   2262   |

## 설계

### 시간 복잡도

picture의 크기는 최대 100^2 이다.

모든 원소에서, 4가지 방향을 탐색할 수 있으므로 (BFS로 모두 탐색한다고 할 때)

최악의 경우의 시간 복잡도는

```cpp
4 * 100^2 = 40,000
```

이므로 제한시간 내에 충분하다.

### 공간 복잡도

picture의 원소는 2^31 - 1 이하의 값 이므로 int형으로 선언한다.

BFS로 탐색 시 큐에 쌓이는 최악의 크기는 100^2 이하 이다.

### BFS

모든 원소를 순회하며 색이 칠해져 있는 경우 BFS의 시작점으로 설정하고 BFS를 탐색한다.

```cpp
int color = picture[y][x];
int count = 0;
q.push({y, x});

while (!q.empty()) {
  Axis cur = q.front();
  q.pop();

  if (visited[cur.y][cur.x]) continue;
  if (picture[cur.y][cur.x] != color) continue;

  visited[cur.y][cur.x] = true;
  count += 1;

  for (Axis dir : dirs) {
    Axis next = cur;
    next.y += dir.y;
    next.x += dir.x;

    if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) {
      continue;
    }
    q.push(next);
  }
}

colors.push_back({color, count});
```

## 고생한 점
