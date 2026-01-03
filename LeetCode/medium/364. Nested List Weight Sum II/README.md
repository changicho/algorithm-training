# 364. Nested List Weight Sum II

[링크](https://leetcode.com/problems/nested-list-weight-sum-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 nestedList의 실제 모든 숫자의 갯수를 N이라 하자.

BFS를 사용할 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

BFS를 사용할 경우 큐에 최대 N개의 원소가 들어갈 수 있으므로 O(N)의 공간 복잡도를 가진다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

nestedList를 BFS로 depth별로 탐색한다.

이후 현재 숫자와 해당 숫자의 depth를 저장한 뒤, BFS탐색을 마무리해 최대 깊이가 구해진 경우 이를 이용해 정답을 계산한다.

```cpp
int depthSumInverse(vector<NestedInteger>& nestedList) {
  int maxDepth = 0;

  queue<NestedInteger> q;
  for (NestedInteger& ni : nestedList) {
    q.push(ni);
  }
  int depth = 1;
  int count = 0;

  // num, depth;
  vector<pair<int, int>> vals;
  while (!q.empty()) {
    int size = q.size();
    maxDepth = depth;

    while (size--) {
      NestedInteger cur = q.front();
      q.pop();

      if (cur.isInteger()) {
        vals.push_back({cur.getInteger(), depth});
        continue;
      }

      for (NestedInteger& next : cur.getList()) {
        q.push(next);
      }
    }
    depth++;
  }

  int answer = 0;
  for (pair<int, int>& cur : vals) {
    answer += cur.first * (maxDepth - cur.second + 1);
  }
  return answer;
}
```

## 고생한 점
