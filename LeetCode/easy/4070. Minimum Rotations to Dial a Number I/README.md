# 4070. Minimum Rotations to Dial a Number I

[링크](https://leetcode.com/problems/minimum-rotations-to-dial-a-number-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

순회하며 변경횟수를 구하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

두 문자 사이의 이동 거리를 구하며 circular 하게 변하는 경우 또한 구한다.

이를 위해 두 문자중 큰값을 B, 작은값을 A라 하며 A->B의 경우와 B->A의 경우를 구한다.

```cpp
int minRotations(string s) {
  int answer = 0;

  int cur = 0;
  for (char& c : s) {
    int to = c - '0';

    int a = min(cur, to), b = max(cur, to);
    int count = min(abs(a - b), (10 - b) + a);
    answer += count;

    cur = to;
  }
  return answer;
}
```

## 고생한 점
