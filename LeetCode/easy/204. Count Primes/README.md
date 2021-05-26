# 204. Count Primes

[링크](https://leetcode.com/problems/count-primes/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

N은 최대 5 \* 10^6 까지이다.

매 수마다 소수 여부를 직접 구할 경우 제한시간 내에 불가능하다.

따라서 에라토스테네스의 채를 이용해 미리 소수를 모두 구한 뒤 count를 수행한다.

에라토스테네스의 채를 이용할 경우 시간 복잡도는 O(sqrt(N) \* log_e(log_e(N))) 이므로 제한시간 내에 충분하다.

### 공간 복잡도

N까지의 숫자가 각각 소수인지 아닌지를 저장해야 하므로 O(N)의 공간 복잡도가 필요하다.

### 정리

| 내 코드 (ms) |          시간 복잡도          | 공간 복잡도 |
| :----------: | :---------------------------: | :---------: |
|      44      | O(sqrt(N) \* log_e(log_e(N))) |    O(N)     |

0부터 N-1까지의 수를 순회하며 소수의 갯수를 세는 문제이다.

N까지 소수를 미리 다 구해놓은 뒤 count한다.

시간 복잡도는 다음과 같이 계산된다.

우선 sqrt(N)의 경우 outer loop에 의해 결정된다.

이후 내부 iterator에서 반복하는 횟수는 N/2 + N/3 + N/5 + ... 가 된다.

이는 log_e(log_e(N)))이다. [증명](http://www.cs.umd.edu/~gasarch/BLOGPAPERS/sump.pdf)

따라서 최종 시간 복잡도는 O(sqrt(N) \* log_e(log_e(N)))가 된다.

```cpp
int countPrimes(int n) {
  vector<bool> isNotPrime(n + 1, false);
  isNotPrime[0] = isNotPrime[1] = true;

  for (int cur = 2; cur <= sqrt(n); cur++) {
    if (isNotPrime[cur]) continue;

    for (int next = cur * cur; next <= n; next += cur) {
      isNotPrime[next] = true;
    }
  }

  int answer = 0;
  for (int number = 0; number < n; number++) {
    if (isNotPrime[number] == false) answer += 1;
  }

  return answer;
}
```

## 고생한 점
