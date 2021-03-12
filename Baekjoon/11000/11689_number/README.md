# 11689. GCD(n, k) = 1

[링크](https://www.acmicpc.net/problem/11689)

|   난이도   | 정답률(\_%) | 시간 제한(초) |
| :--------: | :---------: | :-----------: |
| Platinum V |   34.750    |       1       |

## 설계

### 시간 복잡도

N은 10^12 까지이다. 따라서 long long 형으로 선언한다.

### 공간 복잡도

### 소인수 분해

N이 45인 경우를 생각해보자. 45 = 3^2 \* 5 이다.

1부터 45까지

- 3의배수 15개
- 5의 배수 9개
- (3 \* 5)의 배수 3개 (3과 5가 겹치는 경우)

45 - 15 - 9 + 3 = 24가 나온다.

즉 이 문제는 포함 배제를 이용해 풀이할 수 있다.

N은 최대 10^12이므로 1 ~ 10^6까지 소수를 구해준다.

또한 N이 10^12 까지이며 N이 가질 수 있는 소인수의 개수는 (중복을 제외했을때) 11개를 넘지 않는다.

```cpp
2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29 ...
```

### 포함 배제

집합에서 합의 공식을 n개짜리 합집합으로 일반화한 것이다.

```text
∣A∪B∣=∣A∣+∣B∣−∣A∩B∣
∣A∪B∪C∣=∣A∣+∣B∣+∣C∣−∣A∩B∣−∣B∩C∣−∣C∩A∣+∣A∩B∩C∣
```

일반적으로 n개의 유한 집합 A1,A2,…,An이 있다고 하자. 그 합집합의 크기는 아래와 같다. (An는 n번째 유한 집합)

부분집합의 개수가 홀수개면 부분 집합에서 교집합을 통해 만들어진 원소의 갯수들에게 +부호를 붙이고 짝수라면 −부호를 붙인다.

```text
|A1∪A2∪A3∪ ... ∪An| =
+ sigma(i: 1 ~ N)Ai
- sigma(i,j:1 <= i <= j <= N)|Ai∩Aj|
+ sigma(i,j,k:1 <= i <= j <= k <= N)|Ai∩Aj∩Ak|
- ...
// ...
```

N이 45일때를 다시 확인해보자.

1부터 45까지

- 3의배수 15개
- 5의 배수 9개
- (3 \* 5)의 배수 3개 (3과 5가 겹치는 경우)

이므로 소인수의 조합이 겹치는 경우와 겹치지 않는 경우를 나눠 짝수인 경우 빼고 홀수인 경우는 더해 문제를 풀이할 수 있다.

따라서 N의 소인수들을 구해놓고, 조합 배제의 원리를 이용해 소인수들을 조합해 만들 수 있는 경우를 전부 구한다.

이때 조합은 소인수의 개수가 크지 않으므로 비트마스킹을 이용해 구현한다.

인수의 개수가 홀수일 때는 빼고, 짝수일 때는 더해 답을 구한다.

```cpp
// 에라토스 테네스의 채를 이용해 소인수들을 구함
vector<long long> getPrimeFactors(long long number) {
  vector<long long> primeFactors;
  for (long long prime = 2; prime * prime <= number; prime += 1) {
    long long square = 0;
    while (number % prime == 0) {
      square += 1;
      number /= prime;
    }
    if (square == 0) continue;

    primeFactors.push_back(prime);
  }
  if (number != 1) {
    primeFactors.push_back(number);
  }

  sort(primeFactors.begin(), primeFactors.end());
  primeFactors.erase(unique(primeFactors.begin(), primeFactors.end()), primeFactors.end());

  return primeFactors;
}
```

```cpp
long long answer = N;
for (int bit = 1; bit < (1 << primeFactors.size()); bit++) {
  long long now = 1;
  int count = 0;

  for (int index = 0; index < primeFactors.size(); index++) {
    if (!(bit & (1 << index))) {
      continue;
    }
    now *= primeFactors[index];
    count++;
  }

  if (count % 2 == 1) {
    answer -= (N / now);
  } else {
    answer += (N / now);
  }
}
```

### 오일러 파이 함수

> 1부터 n까지 n과 서로소인 수들의 개수

오일러 파이의 정의 자체가 이 문제와 동일하다.

즉 오일러 파이 함수(Euler phi function)를 ϕ 라고 했을때 다음을 구하는 문제이다.

```cpp
ϕ(N);
```

여기서 오일러 파이 함수는 다음을 만족한다.

```cpp
ϕ(a * b) = ϕ(a) * ϕ(b) // a,b는 서로소인 정수
ϕ(p^m) = p^m − p^(m−1) = p^m * (1 − 1/p) // (p는 소수, m은 양의 정수)
```

N이 480인 경우를 생각해보자.

```cpp
ϕ(480)
= ϕ(2^5 * 3 * 5)
= ϕ(2^5) * ϕ(3) * ϕ(5)
= (2^5 - 2^4) * (3^1 - 3^0) * (5^1 - 5^0)
= 128
```

이므로 에라토스 테네스의 채를 이용해 소인수 분해를 하며 각 경우마다 오일러 파이 함수 값을 곱해준다.

제곱 함수는 직접 제곱할 경우 제한시간 내에 불가능하므로 분할정복을 이용한 제곱 함수를 이용한다.

```cpp
long long myPow(long long value, long long square) {
  if (square == 0) return 1LL;
  if (square == 1) return value;
  if (square & 1) {  // square % 2 == 1
    return myPow(value, square - 1) * value;
  }

  long long root = myPow(value, square / 2);
  return root * root;
}
```

이 때, 최후에 남은 경우를 고려한다.

```cpp
long long answer = 1;
for (long long prime = 2; prime * prime <= N; prime += 1) {
  long long count = 0;
  while (N % prime == 0) {
    count += 1;
    N /= prime;
  }
  if (count == 0) continue;

  answer *= (myPow(prime, count) * (prime - 1)) / prime;
}
if (N != 1) {
  long long prime = N, count = 1;
  answer *= (myPow(prime, count) * (prime - 1)) / prime;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      8       |       0        |

## 고생한 점
