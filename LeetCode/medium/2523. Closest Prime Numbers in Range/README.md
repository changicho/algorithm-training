# 2523. Closest Prime Numbers in Range

[링크](https://leetcode.com/problems/closest-prime-numbers-in-range/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수의 범위 중 최대값을 N이라 하자.

에라토스 테네스의 체를 이용해 소수를 미리 구할 경우 O(N \* log_2(log_2(N)))의 시간 복잡도가 소요된다.

이후 각 소수를 순회하는데 최대 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

에라토스 테네스의 체를 이용해 소수를 미리 구할 경우 O(N)의 공간 복잡도가 필요하다.

### 정리

| 내 코드 (ms) |         시간 복잡도         | 공간 복잡도 |
| :----------: | :-------------------------: | :---------: |
|      67      | O(N \* log_2(log_2(N)) + N) |    O(N)     |

에라토스 테네스의 체를 이용해 소수를 미리 구하고, 이후 각 소수를 순회하며 가장 가까운 두 소수를 찾는다.

```cpp
vector<int> closestPrimes(int left, int right) {
  bool isNotPrime[1000001] = {
      false,
  };
  isNotPrime[0] = isNotPrime[1] = true;
  for (int i = 2; i * i <= right; i++) {
    if (!isNotPrime[i]) {
      for (int next = i * i; next <= right; next += i) {
        isNotPrime[next] = true;
      }
    }
  }

  vector<int> primes;
  for (int num = left; num <= right; num++) {
    if (!isNotPrime[num]) {
      primes.push_back(num);
    }
  }

  int diff = INT_MAX;
  vector<int> answer = {-1, -1};

  for (int i = 1; i < primes.size(); i++) {
    int curDiff = primes[i] - primes[i - 1];

    if (curDiff < diff) {
      diff = curDiff;
      answer[0] = primes[i - 1];
      answer[1] = primes[i];
    }
  }

  return answer;
}
```

## 고생한 점
