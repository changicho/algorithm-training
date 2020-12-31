# 1167. 트리의 지름

[링크](https://www.acmicpc.net/problem/1167)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Gold III |   36.585    |

## 설계

### 시간 복잡도

트리의 정점의 개수 V는 최대 (2 ≤ V ≤ 100,000) 까지이다.

트리에서 가장 멀리있는 정점을 찾는데 DFS를 이용하는 경우 시간 복잡도는

O(|V| + |E|) 이다. 이는 최악의 경우 300,000 이내이며 제한시간 2초 내에 충분하다.

### 공간 복잡도

주어지는 거리는 모두 10,000 이하의 자연수이다.

최악의 경우 정답은 1,000,000,000 까지 이므로 int형으로 선언한다.

### 트리의 지름

각 정점끼리 연결에 표현해야할 정보가 거리와 목적지 2가지 이므로 struct로 관리한다.

```cpp
struct Link {
  int to;
  int dist;
};
```

트리의 지름을 구하는 방법은 다음과 같다.

1. 임의의 점에서 가장 멀리있는 (거리가 먼) 노드를 구한다.
2. 그 노드에서 가장 멀리있는 노드를 구한다. (정점의 번호와 거리)
3. 1번에서 구한 노드와 2번에서 구한 노드사이의 길이가 트리의 지름이다.

한 노드에서 가장 멀리있는 노드를 구하는데 DFS를 이용한다.

```cpp
Link farestNode;
bool visited[100001];
vector<vector<Link> > links;

void recursive(int dist, int node) {
  if (visited[node]) return;
  visited[node] = true;

  if (farestNode.dist < dist) {
    farestNode.dist = dist;
    farestNode.to = node;
  }

  for (Link link : links[node]) {
    if (visited[link.to]) continue;

    recursive(dist + link.dist, link.to);
  }
}
```

위와 같이 탐색을 반복하는 경우 현재 정점에서 가장 멀리있는 정점을 구할 수 있다.

```cpp
recursive(0, 1);

int target = farestNode.to;
// clear array, variable
memset(visited, false, sizeof(visited));
farestNode.dist = 0;

recursive(0, target);

int answer = farestNode.dist;
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      76      |       24       |

## 고생한 점
