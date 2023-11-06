# B. Deja Vu

[링크](https://codeforces.com/contest/1891/problem/B)

## 설계

### 시간 복잡도

입력받은 두 배열의 크기를 N, Q라 하자. (1 <= N, Q <= 10^5)

모든 경우마다 직접 연산을 수행할 경우 최소 O(N \* Q)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

크기가 Q인 쿼리들의 값은 최대 30까지이다.

이 때 쿼리들 중 현재 쿼리를 사용할 때 해당 값 이상의 쿼리들은 이후에 나와도 사용할 수 없다.

N의 각 원소에서 각 수마다 적용할 수 있는 쿼리를 계산할 수 있으며 이는 O(1)의 시간 복잡도를 사용한다.

따라서 각 수를 순회하며 적용할 쿼리만을 적용하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

반환할 배열에 O(N)의 공간 복잡도를 사용한다.

배열에 O(N + Q)의 공간 복잡도를 사용한다.

### 순회 & 유효한 쿼리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     218      |    O(N)     |  O(N + Q)   |

현재 쿼리의 값을 X라 하자.

만약 현재 값이 X로 나누어떨어지는 경우 현재 값에 X/2를 더한다.

이 경우 X/2를 더했을 때 해당 값은 더이상 X로 나누어떨어지지 않게 된다.

따라서 쿼리들 중에서 이전에 나온 값 이상의 쿼리들은 적용할 수 없는 쿼리이다.

따라서 X의 값들 중 값이 감소하게 하는 값만 적용할 수 있다.

이후 N개의 원소를 순회하며 2의 배수들로 나누어 떨어지는지 판단한다. 

만약 나누어 떨어지며 해당 2의 배수를 쿼리로 만들 수 있는 경우 해당 값에 문제에 주어진 조건대로 더한다.

```cpp
vector<long long> solution(vector<long long> &arr, vector<int> &queries) {
  unordered_set<long long> us;
  stack<long long> stk;

  for (int &q : queries) {
    long long cur = 1 << q;

    if (!stk.empty() && stk.top() <= cur) {
      continue;
    }
    stk.push(cur);
  }

  while (!stk.empty()) {
    us.insert(stk.top());
    stk.pop();
  }

  int size = arr.size();
  for (int i = 0; i < size; i++) {
    long long cur = arr[i];
    long long sum = 0;

    for (int j = 1; j <= 30; j++) {
      int divisor = 1 << j;

      if (cur % divisor == 0 && us.count(divisor) > 0) {
        sum += divisor / 2;
      }
    }

    arr[i] += sum;
  }
  return arr;
}
```

## 고생한 점
