# 1306. Jump Game III

[링크](https://leetcode.com/problems/jump-game-iii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

BFS를 이용해 특정 index까지 도달 가능한지 판단한다.

이에 O(N)의 공간 복잡도를 사용한다.

### 공간 복잡도

BFS에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

start 부터 탐색을 진행하며 값이 0인 index에 도달 가능한지 판단한다.

```cpp
bool canReach(vector<int>& arr, int start) {
  int size = arr.size();

  vector<bool> visited(size);

  queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (arr[cur] == 0) return true;

    int prev = cur - arr[cur];
    int next = cur + arr[cur];

    if (prev >= 0 && !visited[prev]) {
      q.push(prev);
      visited[prev] = true;
    }
    if (next < size && !visited[next]) {
      q.push(next);
      visited[next] = true;
    }
  }

  return false;
}
```

## 고생한 점
