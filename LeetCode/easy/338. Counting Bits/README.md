# 338. Counting Bits

[링크](https://leetcode.com/problems/counting-bits/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

각 숫자별로 bit를 직접 구할경우 각 경우마다 O(log_2(N))번의 시간 복잡도가 소요된다.

따라서 직접 모두 구할 경우 시간 복잡도는 O(N \* log_2(N))이다.

직전의 연산 결과를 사용할 경우 bit를 구할 때 O(1)만에 구할 수 있으므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

정답으로 O(N)크기의 배열을 반환해야 하므로 공간 복잡도는 O(N)이다.

### 브루트 포스

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(N \* log_2(N)) |    O(N)     |

0부터 N까지 각 숫자에 대해서 비트를 직접 구한다.

1인 비트를 counting하기 위해 나머지 연산과 나누기를 이용한다.

```cpp
int counting(int n) {
  int count = 0;
  while (n != 0) {
    count += n % 2;
    n /= 2;
  }
  return count;
}

vector<int> countBits(int n) {
  vector<int> bits(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    bits[i] = counting(i);
  }

  return bits;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

숫자 X에 대한 비트를 구할 때 맨 오른쪽 비트를 제외한 나머지 비트에 해당하는 숫자는 X보다 작다.

X를 2진법으로 나타낸 길이를 L이라 하자. L-1 비트로 구성된 숫자는 모두 X보다 작기 때문이다.

따라서 X / 2에 대한 1 비트 counting은 이전에 구했으므로 이 값과 현재 맨 오른쪽 비트 counting을 수행한 값을 더해 값을 구한다.

```cpp
vector<int> countBits(int n) {
  vector<int> bits(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    bits[i] = bits[i / 2] + i % 2;
  }

  return bits;
}
```

## 고생한 점
