# 1463. 1로 만들기

[링크](https://www.acmicpc.net/problem/1463)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Silver III |   32.003    |

## 설계

### 시간 복잡도

N은 최대 1,000,000 까지이다.

1에서 시작해 N까지 도달하는 모든 경우를 탐색할 경우 최악의 경우 시간 복잡도는 log_2(N)+1 이다. (이분 탐색으로 도달하므로)

또한 동적 계획법을 이용해 이전 계산결과를 이용해 문제를 풀이할 수 있으며 이는 O(N) 이다.

두 방법 모두 제한시간 0.5초 내에 풀이 가능하다.

### 공간 복잡도

정답은 최대 1,000,000 까지임이 보장된다. 따라서 int형으로 선언한다.

### 동적 계획법

일반식은 다음과 같다.

```cpp
counts[n] = min(counts[n-1], counts[n/2], counts[n/3]) + 1
// n이 2 혹은 3의 배수가 아닌경우
counts[n] = counts[n-1] + 1
```

이 경우 초기값을 1~3 까지 지정해줘야하며 이는 다음과 같다.

```cpp
counts[1] = 0;
counts[2] = 1;
counts[3] = 1;
```

정답의 갱신은 다음과 같이 이루어진다.

```cpp
for (int i = 4; i <= N; i++) {
  int before_count = counts[i - 1];
  if (i % 2 == 0) {
    before_count = min(before_count, counts[i / 2]);
  }
  if (i % 3 == 0) {
    before_count = min(before_count, counts[i / 3]);
  }

  counts[i] = before_count + 1;
}
```

### 그리디 알고리즘 (탐색)

현재 수를 n/2 에서 만드는 경우와 n/3 에서 만드는 경우를 비교한다.

이 때의 시간 복잡도는 O(log_2(N) + log_3(N)) 이며 이는 제한시간 내에 충분하다.

```cpp
int recursive(int n) {
  int from_two, from_three;
  if(n < 2) return 0;

  from_two = recursive(n / 2) + n % 2;
  from_three = recursive(n / 3) + n % 3;

  return min(from_two, from_three) + 1;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       0        |

## 고생한 점

```text
642

10

===

643

11
```

해당 경우에서 오답이 발생해 재채점결과 틀렸다.

이는 dp를 이용한 방법에서 2의 배수이며 3의 배수인 경우에 2의배수 먼저 판별하기 때문이였다.

2의 배수인 경우와 3의 배수인 경우 모두를 판별해야 한다.
