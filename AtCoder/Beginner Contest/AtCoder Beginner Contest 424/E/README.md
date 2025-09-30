# E - Cut in Half

[링크](https://atcoder.jp/contests/abc424/tasks/abc424_e)

| 난이도 |
| :----: |
|  475   |

## 설계

### 시간 복잡도

입력받은 숫자의 갯수를 N, 변경횟수를 K, 구해야 하는 숫자를 X라 하자.

모든 경우를 직접 수행할 경우 O((N + K + X) \* log_2(N))의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

우선순위 큐를 사용해 변경 횟수를 최적화할 수 있다. (실제 값을 저장하지 않고 변경된 횟수를 저장함)

이 경우 변경을 수행하는데 O(log_2(N) \* log_2(K))의 시간 복잡도를 사용한다.

숫자를 저장하는데 O(N \* log_2(N))의 시간 복잡도를 사용하며 최종 값을 구하는데 O(log_2(N) \* log_2(X))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O((N + log_2(K) + log_2(X)) \* log_2(N))가 된다. O(log_2(2^N \* K \* X) \* log_2(N))

### 공간 복잡도

우선순위 큐에 O(N)의 공간 복잡도를 사용한다.

### 힙

| 내 코드 (ms) |             시간 복잡도             | 공간 복잡도 |
| :----------: | :---------------------------------: | :---------: |
|     161      | O(log_2(2^N \* K \* X) \* log_2(N)) |    O(N)     |

힙에 다음과 같은 정보를 저장한다.

- value: 현재 값
- count: 현재 값이 힙에 몇 번 등장하는지

이를 이용해 K번 연산을 수행할 때 큐에 값을 여러번 저장하지 않고 한번에 처리할 수 있다.

또한 연산을 묶어 처리할 수 있다.

이를 이용해 압축된 정보를 힙에 저장한 뒤 이중 X번째 값을 구한다.

```cpp
struct Number {
  double value;
  long long count;

  bool operator<(const Number &other) const { return value < other.value; }
};

double solution(int size, long long k, long long x, vector<int> &nums) {
  priority_queue<Number> pq;
  for (int &num : nums) {
    pq.push({(double)num, 1});
  }

  while (k > 0) {
    Number top = pq.top();
    pq.pop();

    if (k >= top.count) {
      pq.push({top.value / 2, top.count * 2});
      k -= top.count;
    } else {
      pq.push({top.value / 2, k});
      pq.push({top.value, top.count - k});
      k = 0;

      break;
    }
  }

  double answer = 0;
  while (x > 0) {
    Number top = pq.top();
    pq.pop();

    if (x > top.count) {
      x -= top.count;
    } else {
      answer = top.value;
      break;
    }
  }
  return answer;
}
```

## 고생한 점
