# 3266. Final Array State After K Multiplication Operations II

[링크](https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 배열 nums의 크기를 N, 곱셈 연산의 횟수를 K라 하자. 또한 곱하는 수를 M이라 하자.

K가 10^9 이하이므로 K번의 곱셈 연산을 직접 수행할 경우 제한시간 내에 불가능하다.

각 배열의 수들의 차이를 줄여 어떤 값이라도 M을 곱했을 때 새로운 최대값이 되는 상태를 만든다.

이 상태에서는 각 수마다 조건에 맞는 연산의 횟수를 구할 수 있다.

각 경우마다 가장 작은 값을 증가시켜야 하므로 min heap을 이용한다. 이에 최대 O(N \* log_2(K))의 시간 복잡도를 사용한다.

이후 각 수마다 연산의 횟수를 구하는 데 O(N \* log_2(N))의 시간 복잡도가 필요하다.

### 공간 복잡도

우선순위 큐(min heap)에 O(N)의 공간 복잡도를 사용한다.

### 그리디 & 우선순위 큐

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     213      | O(N \* log_2(K)) |    O(N)     |

nums의 수들에 각각 M을 곱하는 연산을 적절히 수행한다고 하자.

결과적으로 어떤 수에 M을 곱할경우 해당 값이 최대값이 되는 상태를 만든다.

이를 균형 상태라 하자.

따라서 해당 경우 가장 작은 값에 M을 곱하면 새로운 최대값이 되며 해당 경우마다 가장 작은 값은 다르다.

따라서 해당 상태에서는 K번 M을 곱하는 연산을 수행할 때 각 수마다 골고루 연산을 수행해야 한다.

이 때 K가 N 미만인 경우는 가장 작은 K % N 개의 수만 M을 곱하면 된다.

위 상태를 만들기 위해 nums의 수들을 조건을 만족하는 상태로 만들어야 한다.

이를 위해 우선순위 큐를 사용해 각 수들이 한번씩 가장 작은 값으로 나타나는지를 판단한다.

만약 연산을 수행하며 모든 index의 수들이 가장 작은 값을 한번씩 만족한 경우 균형상태가 되었다고 판단할 수 있다.

균형 상태에서 남은 K를 각 index의 수에 적절히 연산을 수행한다.

```cpp
const int MOD = 1e9 + 7;

struct Number {
  long long val;
  int index;

  bool operator<(const Number& b) const {
    if (val == b.val) return index > b.index;
    return val > b.val;
  }
};

int powMod(long long num, int exp, int mod) {
  long long res = 1;
  for (long long base = num; exp > 0; exp /= 2) {
    if (exp % 2 == 1) {
      res = (res * base) % mod;
    }

    base = (base * base) % mod;
  }

  return res;
}

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
  int size = nums.size();

  if (multiplier == 1) return nums;

  priority_queue<Number> pq;

  unordered_set<int> visited;
  for (int i = 0; i < size; i++) {
    pq.push({nums[i], i});
  }

  while (k-- && visited.size() < size) {
    auto [num, index] = pq.top();

    pq.pop();
    pq.push({num * multiplier, index});
    visited.insert(index);
  }

  int quotient = k / size, remainder = k % size;

  vector<int> answer(size);
  while (!pq.empty()) {
    auto [num, index] = pq.top();
    pq.pop();

    answer[index] =
        ((num % MOD) *
          powMod(multiplier, quotient + (remainder >= 0 ? 1 : 0), MOD)) %
        MOD;
    remainder--;
  }

  return answer;
}
```

## 고생한 점
