# 407. Trapping Rain Water II

[링크](https://leetcode.com/problems/trapping-rain-water-ii/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

행의 개수를 R, 열의 개수를 C, 모든 좌표의 개수를 N이라 하자.

모든 좌표를 한번 순회해야 하므로 시간 복잡도는 O(N)보다 작을 수 없다.

테두리부터 높이가 낮은 순으로 BFS를 우선순위 큐를 이용해 진행할 수 있다.

이를 통해 높이가 낮은 쪽부터 테두리를 감소시켜가며 물을 채울 수 있는 경우마다 물을 채운다.

이 경우 우선순위 큐를 사용하는 데 시간 복잡도는 O(N \* log_2(N))이 소요된다.

따라서 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

우선순위 큐를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

그 외에 방문 여부를 판단할 visited 배열에 O(N)의 공간 복잡도를 사용한다.

따라서 공간 복잡도는 O(N)이다.

### 우선순위 큐

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      68      | O(N \* log_2(N)) |    O(N)     |

테두리부터 우선순위 큐에 넣고, 테두리를 점점 좁혀나가며 가능한 water를 count한다.

이 때 높이가 낮은 순서대로 BFS로 방문한다.

이는 테두리에서 가장 낮은 높이부터 탐색하며 방문할 경우 물이 쌓일 수 있는 최소 높이를 계속 계산하며 진행하기 때문이다.

현재 좌표에서 다음 좌표로 진행하며 현재 높이보다 낮은 경우 그만큼 물을 채울 수 있다.

(다른 테두리의 높이들은 현재 높이 이상이므로 가둘 수 있다.)

이를 반복하며 모든 좌표를 방문한다.

다음과 같은 데이터 구조를 사용한다.

```cpp
struct Axis {
  int y, x;
  Axis operator+(const Axis &b) const { return {y + b.y, x + b.x}; }
};

struct Status {
  int height;
  Axis axis;

  bool operator<(const Status &b) const { return height > b.height; };
};

vector<Axis> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
```

이를 이용해 구현하면 다음과 같다.

```cpp
int trapRainWater(vector<vector<int>> &heightMap) {
  int rows = heightMap.size();
  int cols = heightMap.front().size();

  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  priority_queue<Status> pq;

  // push edge to pq
  for (int y = 0; y < rows; y++) {
    pq.push({heightMap[y][0], {y, 0}});
    pq.push({heightMap[y][cols - 1], {y, cols - 1}});

    visited[y][0] = true;
    visited[y][cols - 1] = true;
  }
  for (int x = 1; x < cols - 1; x++) {
    pq.push({heightMap[0][x], {0, x}});
    pq.push({heightMap[rows - 1][x], {rows - 1, x}});

    visited[0][x] = true;
    visited[rows - 1][x] = true;
  }

  int answer = 0;
  int maximum = INT_MIN;
  while (!pq.empty()) {
    Status cur = pq.top();
    Axis &axis = cur.axis;
    pq.pop();

    maximum = max(maximum, cur.height);

    for (Axis &dir : dirs) {
      Axis next = axis + dir;

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;
      visited[next.y][next.x] = true;

      if (heightMap[next.y][next.x] < maximum) {
        answer += maximum - heightMap[next.y][next.x];
      }

      pq.push({heightMap[next.y][next.x], next});
    }
  }

  return answer;
}
```

## 고생한 점
