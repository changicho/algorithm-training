# 70. Climbing Stairs

[링크](https://leetcode.com/problems/climbing-stairs/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

N은 최대 45 이다. 매 경우마다 DFS를 통해 탐색을 진행할 경우 시간 복잡도는 약 O(1,836,311,903)이다. (n=45일 때)

이는 제한시간 내에 불가능하므로 dp를 이용한다.

### 공간 복잡도

dp를 이용할 경우 이전 연산 결과가 필요하므로 45 크기의 배열을 선언한다.

정답은 int형임이 보장되므로 int형 배열을 선언한다.

### 동적 계획법

초기값은 다음과 같다.

```cpp
dp[1] = 1;
dp[2] = 2;
```

일반식은 다음과 같다.

```cpp
dp[n] = dp[n-1] + dp[n-2];
```

이는 다음과 같이 증명 가능하다.

N번째에 도달하는 경우의 수는, N-2번째에서 2칸 올라오는 경우 + N-1번째에서 1칸 올라오는 경우 이다.

### 브루트 포스

직접 탐색을 수행해 풀이할 수 있다.

이 경우 시간 복잡도는 O(2^N) 이다.

```cpp
int climbStairs(int n) {
  return recursive(0, n);
}
int recursive(int i, int n) {
  if (i > n) {
    return 0;
  }
  if (i == n) {
    return 1;
  }
  return recursive(i + 1, n) + recursive(i + 2, n);
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
