# 11266. 단절점

[링크](https://www.acmicpc.net/problem/11266)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold I |   31.457    |

## 설계

### dfs를 이용한 단절점 찾기

```cpp
vector<vector<int> > graph;
vector<int> discovered;
vector<bool> isCut;

// here == 정점 A
int findCut(int here, bool isRoot) {
  discovered[here] = start_node;  // DFS 탐색 순서 지정
  start_node += 1;

  int ret = discovered[here];
  int child = 0;

  for (int next : graph[here]) {
    // 만약 이미 DFS에서 탐색된 정점이라면
    // 현재 정점의 방문순서와 탐색된 정점의 방문 순서중 min값을 찾는다.
    // 이 방법을 이용해야
    // " A번 정점에서 자식 노드들이 정점 A를 거치지 않고
    // 정점 A보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점이다. "
    // 를 찾을 수 있다.
    if (discovered[next]) {
      ret = min(ret, discovered[next]);
      continue;
    }

    child++;
    int prev = findCut(next, false);

    // 정점 A가 루트가 아니라면
    // A번 정점에서 자식 노드들이 정점 A를 거치지 않고 정점 A보다 빠른
    // 방문번호를 가진 정점으로 갈 수 없다면 단절점이다.
    if (!isRoot && prev >= discovered[here]) isCut[here] = true;

    ret = min(ret, prev);
  }

  // 정점 A가 루트 라면, 자식 수가 2개 이상이면 단절점이다.
  if (isRoot) {
    if (child >= 2) {
      isCut[here] = true;
    }
  }

  return ret;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      28      |                |

## 고생한 점
