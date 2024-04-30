# E - Toward 0

[링크](https://atcoder.jp/contests/abc350/tasks/abc350_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. (N <= 10^18)

N은 매우 크므로 모든 경우를 탐색할 경우 제한시간 내에 불가능하다.

재귀호출과 메모이제이션을 이용해 중복 연산을 최적화 할 수 있다.

N이 주어졌을 때 주사위를 굴려 나올 수 있는 경우의 수 1~6마다 나눈 몫이 발생한다.

중복 경우를 제외할 경우 각 경우의 수마다 소수 2,3,5를 약수로 가진 수들이 존재한다.

각 약수의 갯수는 log_2(N), log_3(N), log_5(N)개씩 이다.

이 수들에 대해 재귀호출을 수행해야 하므로 각 약수들의 경우의 수는 최악의 경우도 log_2(N)^3 이하이다.

이에 대한 시간복잡도는 O(log_2(N)^3) 이다.

### 공간 복잡도

메모이제이션에 나올 수 있는 경우의 수에 최대 O(log_2(N)^3)의 공간 복잡도가 필요하다.

### memoization

| 내 코드 (ms) |  시간 복잡도  |  공간 복잡도  |
| :----------: | :-----------: | :-----------: |
|      2       | O(log_2(N)^3) | O(log_2(N)^3) |

현재 수 N에 대해서 각 경우마다 다음 2가지 경우의 수가 존재한다.

- A로 나누고 X를 지불함
- 주사위를 굴리고 Y를 지불함

여기서 두번째 경우에 대한 비용은 다음과 같이 나타낼 수 있다.

- f(N)을 현재 N에서 주사위를 굴렸을 때 내는 비용이라 하자.
- f(N) = Y + (f(N/1) + f(N/2) + f(N/3) + f(N/4) + f(N/5) + f(N/6)) / 6
- 이 때 f(N/1)은 f(N)과 같으므로 위 식을 정리하면 아래와 같다.
- f(N) = 6/5Y + (f(N/2) + f(N/3) + f(N/4) + f(N/5) + f(N/6)) / 5

위 식을 이용해 재귀호출을 수행하며 메모이제이션을 이용해 중복 연산을 최적화한다.

```cpp
double solution(long long n, long long a, long long x, long long y) {
  unordered_map<long long, double> memo;

  function<double(long long)> f = [&](long long n) -> double {
    if (n == 0) return 0;
    if (memo[n]) return memo[n];

    double payX = f(n / a) + x;
    double payY = (double)y * 6 / 5 +
                  (f(n / 2) + f(n / 3) + f(n / 4) + f(n / 5) + f(n / 6)) / 5;

    return memo[n] = min(payX, payY);
  };

  return f(n);
}
```

## 고생한 점
