# 1939. 중량제한

[링크](https://www.acmicpc.net/problem/1939)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   24.060    |

## 설계

### 시간 복잡도

무게의 범위가 1,000,000,000을 초과하므로 이를 N으로 탐색할 경우 시간초과가 발생한다.

따라서 이를 이분 탐색해 풀이한다.

각 무게별로 섬을 이동하는것이 가능한 지는 BFS를 이용해 탐색한다.

BFS를 이용할 경우 탐색은 N번 만에 가능하다.

무게를 바꿔가며, 그 무게로 섬을 이동하는 것이 가능한 지 체크 할 때 시간복잡도는

```cpp
N * log(C) = 10,000 * log(1,000,000) = 300,000
```

따라서 제한시간 1초 내에 충분하다

### 공간 복잡도

섬들의 연결 관계를 2차원 배열로 선언할 경우 메모리 초과가 발생한다.

따라서 이를 다음과 같이 생성한다.

```cpp
struct Line {
  int to, weight;
};

vector<vector<Line> > map;
```

### BFS

현재 섬에서 다음 섬으로 이동이 가능한 지 체크하기 위해 다음 함수를 이용한다.

```cpp
bool canVisit(int from, int to, int val) {
  // 각 섬들의 방문 여부 초기화
  memset(visited, false, sizeof(visited));

  queue<int> q;
  q.push(from);
  visited[from] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (cur == to) {
      return true;
    }

    for (Line line : map[cur]) {
      if (line.weight >= val && !visited[line.to]) {
        visited[line.to] = true;
        q.push(line.to);
      }
    }
  }

  return false;
}
```

### 이분 탐색

가능한 무게를 이분 탐색한다.

```cpp
while (start <= end) {
  mid = (start + end) / 2;

  if (canVisit(from, to, mid)) {
    answer = max(answer, mid);
    start = mid + 1;
  } else {
    end = mid - 1;
  }
}
```

위 while이 끝났을 때 start는 end 보다 크다.

변경되기 전 start를 answer로 저장한다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      44      |       8        |

## 고생한 점

처음에 map의 크기를 100,000^2 로 설정해 메모리 초과가 발생했다.
