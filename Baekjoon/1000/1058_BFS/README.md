# 1058. 친구

[링크](https://www.acmicpc.net/problem/1058)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   37.708    |

## 설계

### 시간 복잡도

N은 최대 50이다.

각 경우별로 친구인지를 판단하기 위해 탐색을 진행하면, 시간 복잡도는 N^2이다.

이를 모든 노드에 대해서 반복할 경우 시간복잡도는 N^3이며 이는 제한시간 내에 충분하다.

### 공간 복잡도

boolean 배열을 이용해 연결 여부를 판단한다.

### 너비우선탐색

노드와 몇번째 연결관계인지 나타내는 구조체를 이용한다.

```cpp
struct Status {
  int node, depth;
};
```

queue를 이용해 BFS 탐색을 진행하며, depth가 2단계 이상인 경우에 탐색을 중지한다.

```cpp
int BFS(int vertex) {
  queue<Status> q;

  q.push({vertex, 0});
  visited[vertex] = true;

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.depth == 2) break;

    for (int next = 0; next < N; next++) {
      if (graph[cur.node][next] && !visited[next]) {
        visited[next] = true;
        q.push({next, cur.depth + 1});
      }
    }
  }

  int ret = 0;
  for (int i = 0; i < N; i++) {
    ret += visited[i];
  }

  return ret - 1;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

memset을 이용하기 위해서 cstring을 include하는것을 잊지말자.
