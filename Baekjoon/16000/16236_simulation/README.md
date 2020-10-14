# 16236. 아기 상어

[링크](https://www.acmicpc.net/problem/16236)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   38.269    |

## 설계

### 시간 복잡도

N의 크기는 최대 20, BFS로 모든 곳을 탐색할 때 20^2 번 만큼 탐색을 수행한다고 할 때,

최악의 경우 시간 복잡도는 지도의 크기만큼 탐색을 반복하는 횟수이다.

따라서 최악의 경우 20^4 = 160,000 번이 소요되며 이는 제한시간 내에 충분하다.

### 공간 복잡도

지도에서 표현해야되는 데이터의 종류는 0,1,2,3,4,5,6,9 로 총 8가지이다.

따라서 지도는 int형으로 선언한다.

각 구조체들을 다음과 같이 정의한다.

```cpp
struct Axis {
  int y, x;
};

struct Shark {
  Axis axis;
  int size;
  int count;
};

struct Status {
  Axis axis;
  int depth;
};
```

### 완전 탐색

엄마상어를 불러야 하는 경우는 다음과 같다.

- 탐색이후 먹이가 없는 경우

따라서 while문을 다음과 같이 선언한다.

```cpp
while(true){
  // BFS search
  if(fish.empty()) break;
  // do something
}
```

BFS 탐색을 진행할 때, 거리또한 계산해야 하므로 다음과 같이 탐색을 진행한다.

```cpp
bool visited[20][20] = {
    0,
};
queue<Status> q;
q.push({babyShark.axis, 0});

vector<Axis> v;
int distance = 0;
bool findFish = false;

while (!q.empty()) {
  if (findFish) break;

  int size = q.size();

  while (size != 0) {
    size -= 1;

    Status cur = q.front();
    q.pop();
    Axis axis = cur.axis;

    if (visited[axis.y][axis.x]) continue;
    visited[axis.y][axis.x] = true;

    if (board[axis.y][axis.x] < babyShark.size && board[axis.y][axis.x] != 0) {
      v.push_back(axis);
      distance = cur.depth;
      findFish = true;
      continue;
    }

    for (Axis dir : dirs) {
      Axis next = axis;
      next.y += dir.y;
      next.x += dir.x;

      if (next.x < 0 || next.x >= limit.x || next.y < 0 || next.y >= limit.y) continue;
      if (board[next.y][next.x] > babyShark.size) continue;

      q.push({next, cur.depth + 1});
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
