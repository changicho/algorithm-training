# 1318. Minimum Flips to Make a OR b Equal to c

[링크](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자 A,B,C 중 가장 큰 값을 N이라 하자.

각 자리수 별로 비교하며 C의 현재 숫자를 만들기 위해 변경해야 하는 A,B의 최소 횟수를 구할 수 있다.

이 경우 2진수의 자리수 별로 변환하는 데 O(log_2(N))의 시간 복잡도를 사용한다.

이 때 N은 최대 10^9까지 이므로 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

매 과정별로 직접 변환하며 비교할 경우 별도의 공간이 필요하지 않다.

### one pass & bit compare

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

현재 C의 숫자를 c, A의 숫자를 a, B의 숫자를 b라 하자.

c가 0인 경우 a,b는 모두 0이여야 한다.

c가 1인 경우 a,b중 하나는 1이여야 한다.

이에 맞춰 a,b중 변경이 필요한 경우를 구하면 된다.

이를 구현하면 다음과 같다.

```cpp
int minFlips(int a, int b, int c) {
  int answer = 0;
  for (int i = 0; i < 32; i++) {
    int curA = a % 2, curB = b % 2, curC = c % 2;

    if (curC == 0) {
      answer += curA + curB;
    } else {
      if (curA == 0 && curB == 0) {
        answer++;
      }
    }

    a /= 2, b /= 2, c /= 2;
  }
  return answer;
}
```

## 고생한 점
