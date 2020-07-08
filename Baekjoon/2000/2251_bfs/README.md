# 2251. 물통

[링크](https://www.acmicpc.net/problem/2251)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   48.065    |

## 설계

### 시간 복잡도

중복되는 경우에도 탐색을 계속할 경우 탐색이 끊이지 않는다.

따라서 중복을 제거한 가능한 방법 모두를 탐색해야한다.

물통 A와 B에 물이 존재하는 경우는 0~200 까지이므로 201^2 이다.

이는 약 40,000 이고 이 경우가 bfs로 가능한 모든 경우이다.

이는 제한시간 내에 충분하다.

### 공간 복잡도

A, B, C는 모두 200 이하의 0을 포함한 자연수 이므로 int형으로 선언한다.

### BFS

물통 A, B, C의 상태를 큐에 저장해 탐색을 진행한다.

현재 상태에서 A가 0이면 C를 정답 vector에 저장한다.

중복을 제거하기 위해 set 을 이용한다.

물통에서 물을 옮길 때, 넘칠 경우에 대한 예외 처리는 if문을 사용한다.

```cpp
while (!q.empty()) {
  Bottle cur = q.front();
  q.pop();

  string status = change(cur);
  if (s.find(status) != s.end()) continue;
  s.insert(status);

  if (cur.b[0] == 0) {
    answers.push_back(cur.b[2]);
  }

  for (int from = 0; from < 3; from++) {
    for (int to = 0; to < 3; to++) {
      if (from == to) continue;
      Bottle next = cur;

      if (next.b[to] + next.b[from] > limit.b[to]) {
        next.b[from] = next.b[to] + next.b[from] - limit.b[to];
        next.b[to] = limit.b[to];
      } else {
        next.b[to] = next.b[to] + next.b[from];
        next.b[from] = 0;
      }

      q.push(next);
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

물통에서 물을 옮길 때의 구현이 어려운 경우는 if문으로 분기처리 하자.
