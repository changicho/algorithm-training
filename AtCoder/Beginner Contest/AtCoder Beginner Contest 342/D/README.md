# D - Square Pair

[링크](https://atcoder.jp/contests/abc342/tasks/abc342_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

배열 A의 크기를 N이라 하자.

모든 쌍에 대해 곱을 구하고, 이 값이 제곱수인지 판별할 경우 O(N^2)의 시간 복잡도가 필요하며 이는 제한시간 내에 불가능하다.

따라서 count & 순회를 이용해 풀이한다.

이 때 제곱수를 만들기 위한 판별에 소인수 분해를 이용한다. 이를 위해 소인수들을 미리 구할 경우 A의 최대값 200,000에 대한 소인수들을 구해야 한다.

sqrt(200,000)은 약 447이므로 500까지의 소수를 구해놓으며 이를 구하는 데 에라토스 테네스의 채를 이용할 경우 O(N) 미만의 시간 복잡도를 사용한다.

이후 소수를 순회하는데 O(1)의 시간 복잡도를 사용한다.

A를 순회하며 소인수 분해를 진행하고 정답에 추가하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

소수들을 구하는 데 500까지의 배열이 필요하다. 이 공간 복잡도는 O(1)이다.

정답의 최대값은 N \* (N-1) / 2 이므로 long long 형으로 선언한다.

각 과정마다 남은 소인수들의 count를 저장하는 데 O(N)의 공간 복잡도가 필요하다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      76      |    O(N)     |    O(N)     |

두 수의 곱이 제곱수인지 판단은 아래와 같이 할 수 있다.

- 특정 수가 제곱수 이기 위해선 각 소인수들의 갯수가 모두 짝수여야 한다.
- 두 수의 소인수들의 갯수를 더했을 때 위 조건을 만족해야 한다.

배열을 순회하며 현재 남은 홀수개의 소인수들의 갯수를 센다. 이를 모두 곱해 key로 설정한다.

만약 이전의 수중에서 해당 key에 해당하는 수들이 존재한다면, 해당 숫자와 현재 숫자를 곱하면 제곱수가 된다.

따라서 이전의 수들을 count에 더해주고, 현재 숫자를 count에 추가한다.

이 때 현재 수가 0인 경우는 모든 수와 곱했을 때 제곱수 0이 되므로 예외 처리해야 한다.

만약 배열에 0이 여러개 있는 경우 중복되서 계산될 수 있으므로 0의 경우 아래와 같이 정답에 더한다.

- 현재까지 나온 0의 갯수를 zeroCount라 하자.
- (N - 1) - zeroCount 만큼 정답에 더한다.

```cpp
long long solution(vector<int> &nums) {
  const int PRIME_SIZE = 500;
  bool isNotPrime[PRIME_SIZE] = {false};

  for (int i = 2; i < PRIME_SIZE; i++) {
    if (isNotPrime[i]) continue;
    for (int j = i * 2; j < PRIME_SIZE; j += i) {
      isNotPrime[j] = true;
    }
  }

  vector<int> primes;
  for (int i = 2; i < PRIME_SIZE; i++) {
    if (!isNotPrime[i]) {
      primes.push_back(i);
    }
  }

  long long answer = 0;
  unordered_map<int, int> counts;

  int zeroCount = 0;

  for (int &num : nums) {
    if (num == 0) {
      answer += (nums.size() - 1 - zeroCount);

      zeroCount++;
      continue;
    }

    // trim num;
    unordered_map<int, int> factors;
    for (int &prime : primes) {
      if (prime > num) break;
      while (num % prime == 0) {
        factors[prime]++;
        num /= prime;
      }
    }

    int converted = num;
    for (auto &factor : factors) {
      if (factor.second % 2 == 0) {
        continue;
      }
      converted *= factor.first;
    }

    if (converted == 1) {
      converted = 0;
    }

    answer += counts[converted];
    counts[converted]++;
  }

  return answer;
}
```

## 고생한 점
