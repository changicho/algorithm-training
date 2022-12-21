# 841. Keys and Rooms

[링크](https://leetcode.com/problems/keys-and-rooms/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

방의 갯수를 N이라 하자.

시작 방(0번) 부터 BFS로 순회해 모든 방을 방문했는 지 판단할 수 있다.

이 경우 중복을 제외한 BFS 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS탐색에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(N)     |

입력받은 rooms는 그래프로 사용할 수 있다.

시작 방 0번부터 BFS로 순회를 한다.

이후 방문한 방의 수가 N개인지를 판단한다.

```cpp
bool canVisitAllRooms(vector<vector<int>>& rooms) {
  int size = rooms.size();

  unordered_set<int> visited;

  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (visited.count(cur)) continue;
    visited.insert(cur);

    for (int next : rooms[cur]) {
      q.push(next);
    }
  }

  return visited.size() == size;
}
```

## 고생한 점
