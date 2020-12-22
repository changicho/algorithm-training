# 9205. 맥주 마시면서 걸어가기

[링크](https://www.acmicpc.net/problem/9205)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   35.477    |

## 설계

### 시간 복잡도

N은 최대 100까지이다. 시작과 끝, 그리고 편의점의 위치를 노드로 볼 때, 노드의 최대 개수는 102개 까지이다.

DFS로 탐색을 수행할 경우 시간 복잡도는 N^2이다.

이는 제한시간 1초 내에 충분하다.

### 공간 복잡도

각 입력좌표의 크기는 -32768 ≤ x, y ≤ 32767 이므로 거리는 int형으로 충분하다.

### 그래프의 생성

그래프 연결 구조가 주어지지 않으므로 직접 연결구조를 생성한다.

이 때, 거리 계산 함수를 분리해 이용한다.

N이 작으므로 2차원 좌표를 이용해 구현했다.

```cpp
int getLength(Axis a, Axis b) {
  return abs(a.y - b.y) + abs(a.x - b.x);
}

bool canReach(Axis a, Axis b) {
  return getLength(a, b) <= 1000 ? true : false;
}

for (int from = 0; from < N + 2; from++) {
  for (int to = 0; to < N + 2; to++) {
    if (from == to) continue;

    if (canReach(axises[from], axises[to])) {
      graphs[from][to] = true;
      graphs[to][from] = true;
    }
  }
}
```

### 탐색

모든 경우를 탐색할 필요 없이, 시작점에서 끝점으로 도달하는지만 검사하면 된다.

따라서 한 노드에 도착한 경우에는 다음번에 그 노드를 검사할 필요가 없다.

```cpp
void recursive(int from) {
  visited[from] = true;

  for (int to = 0; to < axises.size(); to++) {
    if (!graphs[from][to]) continue;
    if (visited[to]) continue;

    recursive(to);
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

어떠한 경우에서라도 한번 거쳐간 노드를 건너뛰지 않아 시간초과가 발생했다.

N+2개가 최대임을 잊어 배열의 범위를 초과했다.
