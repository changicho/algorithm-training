# 9328. 열쇠

[링크](https://www.acmicpc.net/problem/9328)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold I |   24.203    |       1       |

## 설계

### 시간 복잡도

미로의 크기는 최대 100^2 이다. 가질 수 있는 열쇠의 최대 개수를 찾기 위해선 모든 경우를 탐색해야 한다.

이 때 열쇠를 가지는 경우 이전에 방문한 여부를 초기화하고 처음부터 다시 탐색한다.

열쇠의 개수는 최대 26개이고, 각 경우마다 최대 100^2번 탐색하므로 최악의 경우 시간 복잡도는 O(26 \* 100^2) 정도이다.

이는 제한시간 1초 내에 충분하다.

### 공간 복잡도

정답은 최악의 경우도 100^2 이하이다. 따라서 int형으로 선언한다.

### 열쇠 비트마스킹

열쇠의 개수는 최대 26개이다. 2^26은 int형 이내이므로 비트 마스킹으로 열쇠 여브를 관리한다.

새로운 열쇠를 얻을 때마다 해당 비트를 증가시킨다.

```cpp
int keys = 0;
// 비트 설정
keys |= 1 << (key - 'a');
```

"&" 연산을 이용해 비트를 포함했는지 여부를 판단할 수 있다.

```cpp
bool compareKeys(int keys, int key) {
  // 0인 경우는 비트를 가지고 있지 않음.
  return keys & (1 << key);
}
```

### 너비 우선 탐색

테두리에서 들어올 수 있는 입구를 찾아야한다.

들어올 수 있는 입구들을 중복해서 탐색하지 않고, 입력받는 지도에 빈칸으로 채워진 테두리를 두른 뒤 아무 테두리에서만 탐색을 진행한다.

이 방법을 사용할 경우 지도의 크기를 2칸씩 증가시킨다.

```cpp
for (int x = 0; x < W + 2; x++) {
  board[0][x] = board[H + 1][x] = '.';
}
for (int y = 0; y < H + 2; y++) {
  board[y][0] = board[y][W + 1] = '.';
}
for (int y = 1; y <= H; y++) {
  cin >> line;
  for (int x = 1; x <= W; x++) {
    board[y][x] = line[x - 1];

    if ('A' <= board[y][x] && board[y][x] <= 'Z') {
      doors[board[y][x] - 'A'].push_back({y, x});
    }
  }
}
```

BFS 탐색을 진행하며 열쇠를 찾을 때마다 visited 배열을 초기화하며 탐색을 이어나간다.

```cpp
while (!q.empty()) {
  Axis cur = q.front();
  q.pop();

  if (cur.y < 0 || cur.y >= H + 2 || cur.x < 0 || cur.x >= W + 2) continue;
  if (visited[cur.y][cur.x]) continue;
  if (board[cur.y][cur.x] == '*') continue;
  if ('A' <= board[cur.y][cur.x] && board[cur.y][cur.x] <= 'Z' && !compareKeys(keys, board[cur.y][cur.x] - 'A')) continue;

  visited[cur.y][cur.x] = true;

  if (board[cur.y][cur.x] == '$') {
    board[cur.y][cur.x] = '.';
    answer += 1;
  }
  if ('a' <= board[cur.y][cur.x] && board[cur.y][cur.x] <= 'z') {
    int key = board[cur.y][cur.x];
    board[cur.y][cur.x] = '.';
    keys |= 1 << (key - 'a');

    memset(visited, false, sizeof(visited));
    for (Axis door : doors[key - 'a']) {
      board[door.y][door.x] = '.';
    }

    while (!q.empty()) {
      q.pop();
    }
    q.push(cur);

    continue;
  }

  for (Axis dir : dirs) {
    Axis next = cur;
    next.y += dir.y;
    next.x += dir.x;

    q.push(next);
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      20      |       0        |

## 고생한 점
