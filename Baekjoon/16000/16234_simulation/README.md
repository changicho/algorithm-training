# 16234. 인구 이동

[링크](https://www.acmicpc.net/problem/16234)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   35.968    |

## 설계

### 시간 복잡도

N은 최대 50까지이고 시간은 최대 2000까지이다.

한 경우마다 모든 좌표에서 BFS 탐색을 수행해야하고, 각 연합마다 인구수를 갱신해야한다.

- 모든 좌표 탐색 : N^2
- BFS 탐색 : N^2
- 인구수 갱신 : N^2

일 때 최악의 경우 시간 복잡도는

```cpp
2,000 * 50^2 * 3= 15,000,000
```

정도이며 이는 제한시간 2초 내에 충분하다.

### 공간 복잡도

정답은 2,000 이하임이 보장된다.

각 국가끼리 연합임을 표시하는 데 int형 숫자를 사용한다.

이 때 모든 국가가 연합없이 독립되어있는 경우 이 수 (index)의 최대 값은 2500 가량이다.

따라서 int형으로 충분하다.

### 연합 만들기

각 연합국가 별로 숫자로 묶는다.

```cpp
int group[50][50] = {
    0,
};

int group_count = 1;
for (int y = 0; y < limit.y; y++) {
  for (int x = 0; x < limit.x; x++) {
    if (group[y][x] != 0) continue;

    int target = board[y][x];
    queue<Axis> q;
    q.push({y, x});

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      if (group[cur.y][cur.x] != 0) continue;
      group[cur.y][cur.x] = group_count;

      for (Axis dir : dirs) {
        Axis next = cur;
        next.y += dir.y;
        next.x += dir.x;

        if (next.y < 0 || next.y >= limit.y || next.x < 0 || next.x >= limit.x) continue;
        if (group[next.y][next.x] != 0) continue;
        int diff = abs(board[cur.y][cur.x] - board[next.y][next.x]);
        if (L > diff || diff > R) continue;

        q.push(next);
      }
    }
    group_count += 1;
  }
}
```

이 때 group_count가 개별 국가의 크기를 초과한 경우 연합이 존재하지 않음을 의미한다.

### 인구 이동

각 연합마다의 좌표를 저장해놓고 각 좌표별로 값을 갱신해준다.

```cpp
for (int y = 0; y < limit.y; y++) {
  for (int x = 0; x < limit.x; x++) {
    group_axis[group[y][x]].push_back({y, x});
  }
}

for (int i = 1; i < group_count; i++) {
  if (group_axis[i].size() == 1) continue;
  int sum = 0;

  for (Axis a : group_axis[i]) {
    sum += board[a.y][a.x];
  }
  int new_value = sum / group_axis[i].size();

  for (Axis a : group_axis[i]) {
    board[a.y][a.x] = new_value;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     704      |       4        |

## 고생한 점

정답 time 변수를 처음에 초기화 하지 않아 틀렸었다.
