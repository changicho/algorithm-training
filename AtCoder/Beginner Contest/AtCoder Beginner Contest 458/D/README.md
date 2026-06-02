# D - Chalkboard Median

[링크](https://atcoder.jp/contests/abc458/tasks/abc458_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

쿼리의 수를 Q라 하자.

우선순위 큐를 사용해 중앙값을 관리할 경우 O(Q \* log_2(Q))의 시간 복잡도를 사용한다.

### 공간 복잡도

우선순위 큐에 O(Q)의 공간 복잡도를 사용한다.

### 우선순위 큐

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      40      | O(Q \* log_2(Q)) |    O(Q)     |

두개의 우선순위 큐를 관리하며 (max heap, min heap) 이를 이용해 중앙값이 항상 두 우선순위 큐의 top에 오도록 관리한다.

각 쿼리마다 우선 중앙값 기준으로 작은지 큰지 판단 후 적절하게 이동 시킨다

이후 두 힙의 크기의 차가 1이 되도록 크기를 조정한다.

편의상 min heap에 중앙값이 관리되도록 한다.

```cpp
vector<int> solution(int x, int size, vector<pii>& queries) {
  vector<int> answer;

  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int>> right;
  left.push(x);
  left.push(INT_MIN);
  right.push(INT_MAX);

  for (pii& q : queries) {
    int a = q.first, b = q.second;

    for (int cur : {a, b}) {
      if (cur <= left.top()) {
        left.push(cur);
      } else {
        right.push(cur);
      }
    }

    while (left.size() > right.size() + 1) {
      right.push(left.top());
      left.pop();
    }
    while (right.size() + 1 > left.size()) {
      left.push(right.top());
      right.pop();
    }

    answer.push_back(left.top());
  }

  return answer;
}
```

## 고생한 점
