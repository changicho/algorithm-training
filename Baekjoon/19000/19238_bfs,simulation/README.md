# 19238. 스타트 택시

[링크](https://www.acmicpc.net/problem/19238)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   20.613    |

## 설계

### 시간 복잡도

각 경우별로 손님을 찾는 BFS, 목적지까지 도달하는 BFS를 두번 수행해야한다.

각 BFS는 20^2 번 만큼 수행한다.

손님의 수는 최대 400명 까지이다

따라서 시간 복잡도는

```cpp
400 * 2 * (20^2) = 320,000
```

이므로 제한시간 1초 내에 충분하다.

### 공간 복잡도

입력받는 수는 0과 1 이다.

그리고 지도에 각 손님의 시작 위치를 표시해야 하고, 손님의 index는 1~400 까지 이다.

따라서 int형으로 선언한다.

### 가까운 손님 찾기

BFS를 이용해 가까운 손님을 찾는다.

시작 위치에 손님이 있을 수 있음에 유의한다.

```cpp
AxisDist getClosePerson() {
  memset(visited, 0, sizeof(visited));

  if (map[taxi.axis.y][taxi.axis.x] > 0) {
    return {taxi.axis, 0};
  }
  vector<Axis> v;
  queue<AxisDist> q;
  q.push({taxi.axis, 0});
  int dist = 500;

  while (!q.empty()) {
    AxisDist cur = q.front();
    q.pop();

    if (dist <= cur.dist) continue;
    if (visited[cur.axis.y][cur.axis.x]) continue;
    visited[cur.axis.y][cur.axis.x] = true;

    for (int d = 0; d < 4; d++) {
      Axis dir = dirs[d];
      Axis next = cur.axis;
      next.x += dir.x;
      next.y += dir.y;

      if (next.y > limit.y || next.y < 1 || next.x > limit.y || next.x < 1)
        continue;
      if (map[next.y][next.x] == -1) continue;
      if (map[next.y][next.x] > 0) {
        v.push_back(next);
        dist = cur.dist + 1;
        continue;
      }
      q.push({next, cur.dist + 1});
    }
  }

  if (v.size() == 0) {
    return {-1, -1, -1};
  }

  sort(v.begin(), v.end(), compare);

  AxisDist ret = {v.front(), dist};
  v.resize(0);

  return ret;
}
```

### 목적지 까지 거리

각 손님의 목적지와 도착지는 다르므로, 예외처리는 필요하지 않다.

거리를 BFS로 탐색한다.

```cpp
int getDist(Axis from, Axis to) {
  memset(visited, 0, sizeof(visited));

  queue<AxisDist> q;
  q.push({from, 0});
  int dist = -1;

  while (!q.empty()) {
    AxisDist cur = q.front();
    q.pop();

    if (cur.axis.y == to.y && cur.axis.x == to.x) {
      return cur.dist;
    }

    if (visited[cur.axis.y][cur.axis.x]) continue;
    visited[cur.axis.y][cur.axis.x] = true;

    for (Axis dir : dirs) {
      Axis next = cur.axis;
      next.x += dir.x;
      next.y += dir.y;

      if (next.y > limit.y || next.y < 1 || next.x > limit.y || next.x < 1)
        continue;
      if (map[next.y][next.x] == -1) continue;

      q.push({next, cur.dist + 1});
    }
  }

  return dist;
}
```

이 때 시작위치에 visited 방문을 잊지 말아야 함에 유의한다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       0        |

## 고생한 점

시작 위치에 visited를 처리하지 않아 메모리 초과가 발생했다.

또한 택시의 위치에 바로 손님이 존재하는 경우에 대한 처리가 필요함.
