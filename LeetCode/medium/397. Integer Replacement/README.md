# 397. Integer Replacement

[링크](https://leetcode.com/problems/integer-replacement/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

1부터 N까지 모든 경우를 BFS로 순회할 경우 최소 O(N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

따라서 반대로 N에서 1까지 가능한 경우를 BFS로 순회한다.

이 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

중복 방문을 제거해야 하므로 이에 hash set을 사용한다.

이 공간 복잡도는 O(log_2(N))이다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) | O(log_2(N)) |

N에서부터 1으로 만들 때 까지 각 연산들을 수행하며 BFS로 탐색을 진행한다.

이 때 이전에 방문한 수는 탐색하지 않는다.

각 경우마다 step을 체크해야 한다.

```cpp
int integerReplacement(int n) {
  int count = 0;

  unordered_set<long> us;
  us.insert(n);

  queue<long> q;
  q.push(n);

  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      long cur = q.front();
      q.pop();

      if (cur == 1) return count;

      if (cur % 2 == 0 && us.count(cur / 2) == 0) {
        q.push(cur / 2);
        us.insert(cur / 2);
      }
      if (cur % 2 == 1 && us.count(cur - 1) == 0) {
        q.push(cur - 1);
        us.insert(cur - 1);
      }
      if (cur % 2 == 1 && us.count(cur + 1) == 0) {
        q.push(cur + 1);
        us.insert(cur + 1);
      }
    }
    count++;
  }

  return count;
}
```

## 고생한 점
