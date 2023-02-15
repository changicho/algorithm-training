# 2558. Take Gifts From the Richest Pile

[링크](https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 선물의 수를 N, 고르는 횟수를 K라 하자.

각 경우마다 가장 큰 값을 고르는 경우가 제곱근의 수가 가장 크므로 최선의 경우를 찾는다.

이를 위해 우선순위 큐를 사용하며 이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

K개를 꺼낸 이후 남은 수들의 합을 더해야 하므로 총 pop, push 연산에 O((N + K) \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

우선순위 큐를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 우선순위 큐

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      13      | O((N + K) \* log_2(N)) |    O(N)     |

각 경우마다 가장 큰 값을 꺼내 제곱근으로 변경한다.

이후 남은 수를 모두 더한다.

```cpp
long long pickGifts(vector<int>& gifts, int k) {
  long long answer = 0;
  priority_queue<int> pq;
  for (int& g : gifts) {
    pq.push(g);
  }

  while (k-- && !pq.empty()) {
    int top = pq.top();
    pq.pop();

    int next = sqrt(top);
    pq.push(next);
  }

  while (!pq.empty()) {
    int top = pq.top();
    pq.pop();
    answer += top;
  }

  return answer;
}
```

## 고생한 점
