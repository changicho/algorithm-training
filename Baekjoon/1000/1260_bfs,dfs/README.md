# 1260. DFS와 BFS

[링크](https://www.acmicpc.net/problem/1260)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   31.495    |

## 설계

### DFS BFS

DFS는 재귀호출, stack을 이용해 구현

BFS는 queue를 이용해 구현한다.

### DFS - stack

스택의 경우 bfs처럼 현재 정점에서 순회하면서 이동가능한 경로를 stack에 쌓는것이 아니라,

현재 정점에서 순회 가능한 곳이 나왔을 때 바로 stack에 쌓고, 더이상 탐색하지 않아야한다.

그리고 현재 정점에서 순회 가능한곳이 없는 경우에 stack에서 pop을 한다.

```cpp
while (!s.empty()) {
  bool flag = true;
  int current = s.top();

  for (int next : links[current]) {
    if (visited[next]) {
      continue;
    }

    visited[next] = true;
    s.push(next);
    cout << next << " ";

    flag = false;
    break;
  }

  if (flag) {
    s.pop();
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       0        |

## 고생한 점
