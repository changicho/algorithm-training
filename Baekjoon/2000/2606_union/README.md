# 2606. 바이러스

[링크](https://www.acmicpc.net/problem/2606)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   42.856    |

## 설계

### 시간복잡도

N은 최대 100까지이며, 시간 제한은 1초이다.

문제의 풀이 방법은 다음 두가지가 존재한다.

1. 그래프 순회를 이용 (DFS, BFS)
2. 유니온 파인드

1번 방법의 경우 1번 정점에서부터 DFS, BFS로 순회해 방문한 노드의 수를 count하면 된다.

DFS의 시간 복잡도는 정점의갯수 + 간선의 개수 이므로 O(V+E) 이다.

정점은 최대 100개, 간선의 개수는 최대 n(n-1)/2 이므로 최악의 시간복잡도는 대략 O(100 + 100^2) 이므로 제한 시간 1초 내에 충분하다.

2번 방법 유니온 파인드의 경우 두가지 함수로 나누어진다.

union_find의 경우 최악 O(log(N)) 정도이며 union_merge의 경우 에커만 상수에 의해 거의 상수라고 봐도 무방하다.

따라서 이 방법 또한 제한 시간 1초 내에 사용할 수 있다.

### BFS

1번 노드에서부터 도달할 수 있는 모든 노드들을 검사한다.

이후 1번 노드를 제외한 방문한 노드의 갯수를 센다.

```cpp
queue<int> q;
bool visited[101] = {false};
int answer = -1;
q.push(1);

while (!q.empty()) {
  int cur = q.front();
  q.pop();

  if (visited[cur]) continue;
  visited[cur] = true;
  answer += 1;

  for (int next : graph[cur]) {
    q.push(next);
  }
}
```

### 유니온 파인드

한 정점에서 루트 노드를 찾는 find 함수의 경우 다음과 같다.

```cpp
int union_find(int index) {
  if (links[index] == index) {
    return index;
  }
  return links[index] = union_find(links[index]);
}
```

루트 노드의 경우 자기 자신을 가리키기 때문에 links[index] = index이다.

또한 find 함수를 실행하며 연결을 재귀호출로 갱신해준다.

두 그래프를 합치는 merge 연산의 경우 다음과 같다.

```cpp
void union_merge(int first, int second) {
  if (first > second) {
    swap(first, second);
  }

  first = union_find(first);
  second = union_find(second);

  if (first == second) {
    return;
  }

  if (first > second) {
    swap(first, second);
  }

  links[second] = first;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

유니온을 합치기 위한 함수에서 두 인자의 순서를 맞춰주어야 한다.
