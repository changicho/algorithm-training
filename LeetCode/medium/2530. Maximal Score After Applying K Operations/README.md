# 2530. Maximal Score After Applying K Operations

[링크](https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 입력받은 수를 K라 하자.

우선순위 큐를 이용해 매번 최대 값을 찾을 수 있다. 이 경우 O((N + K) * log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

우선순위 큐에 O(N)의 공간 복잡도를 사용한다.

### 힙

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|     203      | O((N + K) * log_2(N)) |    O(N)     |

각 경우마다 최대값을 빠르게 찾기 위해 힙을 사용한다.

이후 해당 값을 3으로 나눈 몫을 다시 힙에 넣는다.

이를 K번 반복한다.

```cpp
long long maxKelements(vector<int>& nums, int k) {
  priority_queue<int> pq;

  for (int& num : nums) {
    pq.push(num);
  }

  long long answer = 0;
  while (k--) {
    int cur = pq.top();
    pq.pop();

    answer += cur;

    pq.push(ceil((double)cur / 3));
  }
  return answer;
}
```

## 고생한 점
