# 191. Number of 1 Bits

[링크](https://leetcode.com/problems/number-of-1-bits/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

32개의 비트에서 1의 갯수를 세는 문제이다.

모든 비트를 순회하는 방법을 사용할 경우 시간 복잡도는 O(32)이다.

비트에서 1을 제거하는 방법을 사용할 경우에 최악의 경우 시간 복잡도는 O(32)이다.

### 공간 복잡도

별도의 공간이 필요하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

직접 끝자리부터 1인지를 count한다.

```cpp
// use mod and divide
int hammingWeight(uint32_t n) {
  int answer = 0;
  for(int i=0;i<32;i++){
    if(n % 2 == 1) answer += 1;
    n /= 2;
  }

  return answer;
}

// use and operator and shift
int hammingWeight(uint32_t n) {
  int answer = 0;
  for (int i = 0; i < 32; i++) {
    if (n & 1 == 1) answer += 1;
    n >>= 1;
  }

  return answer;
}
```

### 1씩 제거

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

비트 1을 한번씩 제거하며 숫자가 0이 될때 까지 몇개를 제거했는지를 return하면 된다.

이 때 맨 오른쪽 비트부터 제거하는 방법은 다음과 같다.

1. N에서 1을 뺀 수를 N`라고 하자.
2. N을 N과 N`의 AND연산한 값으로 바꾼다.
3. N이 0이 될 때까지 반복한다.

```cpp
int hammingWeight(uint32_t n) {
  int answer = 0;
  while (n != 0) {
    answer++;
    n &= (n - 1);
  }
  return answer;
}
```

## 고생한 점
