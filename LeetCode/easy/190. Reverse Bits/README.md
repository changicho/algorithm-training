# 190. Reverse Bits

[링크](https://leetcode.com/problems/reverse-bits/submissions/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

32비트 숫자의 비트를 reverse해야한다. (맨 앞부터 맨 뒤까지 순서를 뒤집음)

따라서 한번의 순회 뒤집을 비트들을 확인해야 한다. 32비트를 뒤집으면 되므로 시간 복잡도는 O(32)이다.

### 공간 복잡도

모든 비트를 뒤집기 위해 정답의 공간만 필요하므로 O(1)의 공간 복잡도가 필요하다.

### 비트 뒤집기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(1)     |    O(1)     |

맨 오른쪽 비트부터 순회하며 새로운 수를 생성한다.

```cpp
uint32_t reverseBits(uint32_t n) {
  uint32_t answer = 0;
  for (int i = 31; i >= 0; i--) {
    // answer |= (n % 2) << i;
    answer |= (n & 1) << i;
    n /= 2;
  }
  return answer;
}
```

절반만 순회할 경우 다음과 같다.

```cpp
int reverseBits(int n) {
  int answer = 0;

  for (int i = 0; i < 16; i++) {
    int left = 1 << i;
    int right = 1 << (31 - i);

    answer += (n & right) ? left : 0;
    answer += (n & left) ? right : 0;
  }
  return answer;
}
```

### 바이트단위 이동

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(1)     |    O(1)     |

32개의 비트를 총 4개의 바이트로 나눈다고 하자.

바이트를 뒤집는 연산을 reverseByte라고 할 때 다음과 같이 나타낼 수 있다.

```cpp
// as is
[byte1, byte2, byte3, byte4]

// to be
[reverseByte(byte4), reverseByte(byte3), reverseByte(byte3), reverseByte(byte1)]
```

바이트를 뒤집는 방법중 한가지인 다음 방법을 이용한다.

[출처](https://graphics.stanford.edu/~seander/bithacks.html#ReverseByteWith64BitsDiv)

```cpp
uint32_t reverseByte(uint32_t byte) {
  return (byte * 0x0202020202 & 0x010884422010) % 1023;
}
```

```cpp
uint32_t reverseBits(uint32_t n) {
  uint32_t ret = 0;
  int power = 24;

  while (n != 0) {
    ret += reverseByte(n & 0xff) << power;
    n = n >> 8;
    power -= 8;
  }
  return ret;
}
```

### merge

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(1)     |    O(1)     |

현재 숫자를 뒤집기 위해서 정 중앙에서 두 비트로 나눈다.

그 후 두 비트를 shift연산한 뒤 다시 합친다.

다음과 같은 순서로 나타낼 수 있다.

1. original : AB
2. divide : A0, 0B
3. reverse : 0A, B0
4. merge : BA

이를 절반씩 나눠 하나의 비트를 이동할 때까지 총 4번 반복한다.

1. 먼저 원래 32 비트를 16 비트의 2 개 블록으로 나누고 전환한다.
2. 그런 다음 16 비트 블록을 8 비트의 2 개 블록으로 나눕니다. 마찬가지로 8 비트 블록의 위치를 전환한다.
3. 그런 다음 1 비트 블록 레벨에 도달 할 때까지 블록을 더 작은 블록으로 계속 나눈다.
4. 위의 각 단계에서 중간 결과를 다음 단계의 입력으로 사용되는 단일 정수로 병합한다.

```cpp
uint32_t reverseBits(uint32_t n) {
  n = (n >> 16) | (n << 16);
  n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
  n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
  n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
  n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
  return n;
}
```

## 고생한 점
