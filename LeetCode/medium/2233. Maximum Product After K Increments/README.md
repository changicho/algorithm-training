# 2233. Maximum Product After K Increments

[링크](https://leetcode.com/problems/maximum-product-after-k-increments/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

숫자의 갯수를 N, 입력받은 수를 K라 하자.

매 경우마다 가장 작은 수를 증가시킬 경우 가장 큰 수를 만들 수 있다.

이를 위해 minHeap을 사용하고, 힙에 원소를 모두 넣는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 가장 작은 수를 증가시키는 과정을 K번 반복한다.

이 경우 O((N + K) \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

힙을 사용하므로 O(N)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     656      | O((N + K) \* log_2(N)) |    O(N)     |

숫자 A와 B가 있다고 하자. (A > B)

두 수를 각각 1 증가시켰을 때 곱은 다음과 같다.

- (A + 1) \* B : AB + B
- A \* (B + 1) : AB + A

위 식을 토대로 작은 수를 증가시켰을 때 더 큰 결과를 얻을 수 있음을 알 수 있다.

따라서 minHeap에 모든 원소를 넣고, 가장 작은 값을 증가시킨 뒤 다시 heap에 넣는 과정을 K번 반복한다.

이를 구현하면 다음과 같다.

```cpp
int maximumProduct(vector<int>& nums, int k) {
  priority_queue<int, vector<int>, greater<int>> minHeap;

  for (int& n : nums) {
    minHeap.push(n);
  }

  while (k--) {
    int cur = minHeap.top();
    minHeap.pop();
    cur++;
    cur %= MOD;

    minHeap.push(cur);
  }

  int product = 1;
  while (!minHeap.empty()) {
    product = ((long)product * minHeap.top()) % MOD;
    minHeap.pop();
  }
  return product;
}
```

## 고생한 점
