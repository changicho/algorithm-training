# C - Snake Numbers

[링크](https://atcoder.jp/contests/abc387/tasks/abc387_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

입력받은 두 수를 R, L이라 하자.

각 수의 자리수를 이용해 계산할 수 있다. 이 경우 시간 복잡도는 O(log_10(R) + log_10(L)) 이므로 O(log_10(L * R)) 이다.

### 공간 복잡도

각 경우마다 9^18의 값들을 더할 수 있으므로 long long형으로 선언한다.

각 자리수별로 저장하는 데 O(1)의 공간 복잡도를 사용한다.

### 경우의 수

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      1       | O(log_10(L * R)) |    O(1)     |

L ~ R까지의 조건을 만족하는 경우의 수를 구하기 위해 아래 방법을 사용할 수 있다.

0 ~ X까지의 경우의 수를 구하는 함수를 F(X)라 하자.

- F(R) - F(L-1)을 구한다.

이 F를 구하기 위해 다음 방법을 사용한다.

X가 아래와 같이 이루어져있다고 하자.

- X = Axxxxxxx ...
- A는 X의 가장 첫번째 자리수
- x는 X의 나머지 자리수

이 경우 다음 두 부분으로 나눌 수 있다.

- 0 ~ (Axxxxxxx ... - 1) 까지 경우의 수
- A000000 ... ~ Axxxxxxx ... 까지 경우의 수

여기서 첫번째 경우의 수는 각 자리수별로 경우의 수를 구해 더하면 된다.

두번째 경우의 수는 다음과 같이 구할 수 있다.

- X의 자리수를 순차적으로 순회하며 각 자리수가 몇번 나타날 수 있는지 구한다.
- 만약 현재 자리수가 A 이상인 경우 현재 자리수 이후부터는 더 이상 탐색하지 않는다.

```cpp
long long my_pow(long long a, int t) {
  long long res = 1;
  while (t--) res *= a;
  return res;
}

long long calc(long long num) {
  // cur number : AXXXX...
  string digits = to_string(num);
  int size = digits.size();

  int front = digits[0] - '0';

  long long ret = 0;

  // calc A0000... ~ AXXXX...
  for (int i = 1; i <= size; i++) {
    if (i == size) {
      ret++;
      break;
    }

    int cur = digits[i] - '0';

    long long curCase = min(front, cur);
    long long otherCase = my_pow(front, size - 1 - i);
    ret += curCase * otherCase;

    if (cur >= front) break;
  }

  // calc 0 ~ (A000... - 1)
  for (int i = 0; i < size; i++) {
    int limit = (i != 0 ? 9 : (front - 1));

    for (int digit = 1; digit <= limit; digit++) {
      ret += my_pow(digit, size - 1 - i);
    }
  }
  return ret;
}

long long solution(long long left, long long right) {
  long long answer = calc(right) - calc(left - 1);

  return answer;
}
```

## 고생한 점
