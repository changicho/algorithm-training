# 786. K-th Smallest Prime Fraction

[링크](https://leetcode.com/problems/k-th-smallest-prime-fraction/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N, 입력받은 수를 K라 하자.

모든 쌍에 대해서 분수를 만들고 이를 우선순위 큐에 넣어 K번째 작은 값을 찾는다. 이 경우 O(N^2 \* log_2(K))의 시간 복잡도가 소요된다.

배열 arr이 정렬되어 있으므로 현재 가장 유리한 작은 분수를 찾을 수 있다.

우선순위 큐를 이용해 가장 작은 값들을 K-1개 제거하는 경우 O((N + K) \* log_2(K))의 시간 복잡도를 사용한다.

### 공간 복잡도

우선순위 큐에 O(K)의 공간 복잡도를 사용한다.

### 우선순위 큐 (모든쌍)

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|     425      | O(N^2 \* log_2(K)) |    O(K)     |

모든 쌍을 계산 후 우선순위 큐를 이용해 K번째 작은 값을 찾는다.

```cpp
struct Prime {
  double val;
  int a, b;

  bool operator<(const Prime& b) const { return val < b.val; }
};

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
  int size = arr.size();
  priority_queue<Prime> pq;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      int a = arr[i], b = arr[j];
      pq.push({double(a) / b, a, b});
      if (pq.size() > k) pq.pop();
    }
  }

  Prime target = pq.top();
  return {target.a, target.b};
}
```

### 우선순위 큐

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     274      | O((N + K) \* log_2(K)) |    O(K)     |

min heap을 사용하며 각 경우마다 가장 작은 값을 찾는다.

이후 해당 값의 분모값을 감소시킨 값을 다시 heap에 넣는다.

이를 K-1번 반복하면 K번째 작은 값을 찾을 수 있다.

```cpp
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
  int size = arr.size();
  priority_queue<Prime> pq;

  for (int i = 0; i < size; i++) {
    int a = i, b = size - 1;
    pq.push({double(arr[a]) / arr[b], a, b});
  }

  // iterate k-1
  while (k-- > 1) {
    Prime cur = pq.top();
    pq.pop();

    int a = cur.a, b = cur.b - 1;

    pq.push({double(arr[a]) / arr[b], a, b});
  }

  Prime target = pq.top();
  return {arr[target.a], arr[target.b]};
}
```

## 고생한 점
