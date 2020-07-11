# 1707. 이분 그래프

[링크](https://www.acmicpc.net/problem/1707)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   22.833    |

## 설계

### 시간 복잡도

테스트케이스는 최대 5개 까지이다.

그래프의 모든 정점을 BFS로 탐색하며 이분이 가능한지 판단하므로 시간복잡도는 O(V+E) 이다.

```cpp
(V + E) * T = (20,000 + 200,000) * 5 = 1,100,000
```

이므로 제한 시간 내에 충분하다.

### 공간 복잡도

정점의 수는 20,000 개 까지이므로 int형으로 충분하다.

### BFS

모든 정점을 방문하며, 방문할 때 중복 여부 체킹 전, 이분 그래프인지 검사를 해야 한다.

또한 그래프가 끊어져 있는 경우 (독립된 그래프가 2개 이상 있는 경우)에도 다른 개별 그래프를 탐색해야 한다.

노드에 들어가야 될 정보는 다음과 같다

- 정점번호
- 색

따라서 노드를 구조체로 정의한다.

```cpp
struct Status {
  int index, color;
};
```

BFS로 이분 그래프 검사는 다음과 같이 수행한다.

```cpp
while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (colors[cur.index] != 0 && colors[cur.index] != cur.color) {
    isBinary = false;
    break;
  }
  if (colors[cur.index] != 0) {
    continue;
  }
  colors[cur.index] = cur.color;

  for (int next : links[cur.index]) {
    q.push({next, -cur.color});
  }
}
```

그리고 BFS의 탐색을 모든 정점에 대해 한번 수행한다.

이 때 이미 방문한 정점은 건너뛴다.

```cpp
for (int start = 1; start <= V; start++) {
  if (colors[start] != 0) continue;

  bfs();
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     292      |       32       |

## 고생한 점
