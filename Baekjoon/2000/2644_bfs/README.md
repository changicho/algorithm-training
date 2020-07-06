# 2644. 촌수계산

[링크](https://www.acmicpc.net/problem/2644)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   45.487    |

## 설계

### 시간 복잡도

사람은 최대 100명이다.

BFS로 모든 사람을 방문 할 경우, 시간복잡도는 최대 100 이다.

이는 제한 시간 내에 충분하다.

### 공간 복잡도

100 이하의 양수만 index로 주어지므로 모든 데이터는 int형으로 선언한다.

### 촌수 계산

한 사이클에서 bfs를 직전 q.size 만큼만 수행한다.

사이클이 끝날 때 마다 answer를 증가시킨다.

```cpp
int answer = 0;
bool isEnd = false;
while (!q.empty()) {
  int q_size = q.size();

  for (int size = 0; size < q_size; size++) {
    int cur = q.front();
    q.pop();

    if (cur == to) {
      isEnd = true;
      break;
    }

    for (int temp_to : relations[cur]) {
      if (visited[temp_to]) continue;

      q.push(temp_to);
      visited[temp_to] = true;
    }
  }

  if (isEnd) break;
  answer++;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
