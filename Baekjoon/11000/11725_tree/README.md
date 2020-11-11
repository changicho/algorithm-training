# 11725. 트리의 부모 찾기

[링크](https://www.acmicpc.net/problem/11725)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   44.133    |

## 설계

### 시간 복잡도

노드의 개수 N은 최대 100,000개 까지이다.

dfs로 탐색을 진행하며 모든 노드의 트리를 구할 경우 시간 복잡도는

log(V+E) 이다.

간선의 개수는 N-1개 까지 가능하므로 시간 복잡도는 최악의 경우 O(200,000) 이다.

따라서 제한시간 1초 내에 충분하다.

### 공간 복잡도

노드끼리 연결되어있음을 판단하기 위해 vector를 사용한다.

정답의 경우 100,000 이하의 자연수임이 보장되므로 int형으로 관리한다.

### 재귀호출을 이용한 탐색

```cpp
void recursive(int node) {
  visited[node] = true;

  for (int to : links[node]) {
    if (visited[to]) continue;

    parents[to] = node;
    recursive(to);
  }
}
```

```cpp
for (int i = 0; i < N; i++) {
  int from, to;
  cin >> from >> to;

  links[from].push_back(to);
  links[to].push_back(from);
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      48      |       4        |

## 고생한 점
