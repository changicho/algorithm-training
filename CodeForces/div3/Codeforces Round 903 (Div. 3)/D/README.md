# D. Divide and Equalize

[링크](https://codeforces.com/contest/1881/problem/D)

## 설계

### 시간 복잡도

입력받은 수를 N, 각 수의 최대값을 M이라 하자.

입력받은 수들의 공약수들이 N으로 나누어 떨어지는 지 판별하면된다.

이 때 공약수를 구하는 데 O(M)의 시간 복잡도를 사용한다.

이를 더 빠르게 수행하기 위해 에라토스테네스의 채를 이용해 소수인 경우 빠르게 판별할 수 있다.

이를 구하는 데 O(M \* log_2(log_2(M)))의 시간 복잡도를 사용하며 이는 거의 O(M)이다.

이 경우 공약수를 구하는 데 최악의 경우 O(sqrt(M))의 시간 복잡도를 사용한다.

따라서 총 O(M + N \* sqrt(M))의 시간 복잡도를 사용한다.

이후 공약수들을 count하는데 hash map을 사용할 경우 O(1)의 시간 복잡도를 사용한다.

이후 공약수들을 순회하는 데 O(sqrt(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

에라토스 테네스의 채를 이용하는데 O(M)의 공간 복잡도를 사용한다.

공약수를 저장하는 데 O(sqrt(M))의 공간 복잡도를 사용한다.

### 에라토스테네스의 채

|     시간 복잡도     |  공간 복잡도   |
| :-----------------: | :------------: |
| O(M + N \* sqrt(M)) | O(M + sqrt(M)) |

에라토스테네스의 채를 이용해 M까지의 소수를 모두 구한다.

이에 O(M \* log_2(log_2(M)))의 시간 복잡도를 사용하며 거의 O(M)이다.

이후 N개의 수를 인수분해 하며 약수들을 count한다.

이후 약수들의 갯수가 N으로 나누어 떨어지는 지 판별한다.

만약 나누어 떨어지지 않는 경우 모든 수를 같게 만들 수 없다.

```cpp
void factorization(int num, unordered_map<int, int> &counts) {
  for (int &prime : primes) {
    if (num == 1) return;
    if (isPrime[num]) {
      counts[num]++;
      return;
    }

    while (num % prime == 0) {
      counts[prime]++;
      num /= prime;
    }
  }
}

bool solution(vector<int> &arr) {
  int size = arr.size();

  unordered_map<int, int> counts;
  for (int &num : arr) {
    factorization(num, counts);
  }

  for (auto &it : counts) {
    int count = it.second;

    if (count % size != 0) return false;
  }

  return true;
}
```

## 고생한 점
