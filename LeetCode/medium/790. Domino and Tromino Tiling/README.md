# 790. Domino and Tromino Tiling

[링크](https://leetcode.com/problems/domino-and-tromino-tiling/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 크기를 N이라 하자. (N <= 1,000)

모든 경우를 탐색할 경우 시간 복잡도가 매우 크므로 동적 계획법을 이용한다.

현재 값을 계산하는 데 두가지 값이 필요하다. (모두 차있는 경우의 수, 일부만 차있는 경우의 수)

이 값들을 순회하며 갱신할 수 있으므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 값에 대해 동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

직전 값들만 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

현재 길이가 N인 타일을 완전히 채울 때 다음과 같은 이전 값들을 사용가능하다.

- N-1인 완전히 채워진 타일 : | 모양 타일 하나를 붙임
- N-2인 완전히 채워진 타일 : = 모양 타일 하나를 붙임
- N-1인 한칸만 채워진 타일 : L 모양 타일 하나를 붙임 (2가지 경우 존재)

길이가 N인 타일을 한칸만 남도록 채울때 다음과 같은 이전 값들을 사용 가능하다.

- N-2인 완전히 채워진 타일 : L 모양 타일 하나를 붙임
- N-1인 한칸만 채워진 타일 : - 모양 타일 하나를 붙임

따라서 일반 식을 다음과 같이 세울 수 있다.

```cpp
// definition
long fully[i]; // 완전히 채워진 길이가 i인 경우의 수
long partially[i]; // 한칸만 채워진 길이가 i인 경우의 수

// update
fully[i] = (fully[i - 1] + fully[i - 2] + 2 * partially[i - 1]);
partially[i] = (partially[i - 1] + fully[i - 2]);

// init
fully[1] = 1;
fully[2] = 2;
partially[1] = 0;
partially[2] = 1;
```

이를 이용해 구현하면 다음과 같다.

```cpp
const int MOD = 1e9 + 7;

int numTilings(int n) {
  if (n <= 2) {
    return n;
  }

  long fully[n + 1];
  long partially[n + 1];

  fully[1] = 1L;
  fully[2] = 2L;
  partially[2] = 1L;

  for (int i = 3; i <= n; i++) {
    fully[i] = (fully[i - 1] + fully[i - 2] + 2 * partially[i - 1]) % MOD;
    partially[i] = (partially[i - 1] + fully[i - 2]) % MOD;
  }
  return int(fully[n]);
}
```

## 고생한 점
