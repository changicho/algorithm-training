# 1758. Minimum Changes To Make Alternating Binary String

[링크](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

조건을 만족하는 경우는 2가지이다. 두 경우를 모두 탐색하며 최소값을 구할 경우 순회에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

두 경우를 직접 탐색할 때 현재 index에서 0, 1로 경우만 판별할 수 있다.

이 경우 O(1)의 공간 복잡도를 사용한다.

### 완전탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

정답은 다음 2가지 경우 중 하나이다.

- 0으로 시작
- 1로 시작

따라서 두 경우 모두 탐색하며 s에서 변화시켜야 하는 문자의 개수를 구한다.

두 값중 작은 값을 정답으로 반환한다.

```cpp
int calc(string &s, int start) {
  int cur = start;
  int ret = 0;
  for (char &c : s) {
    if (c - '0' != cur) {
      ret++;
    }
    cur = !cur;
  }
  return ret;
}

int minOperations(string s) { return min(calc(s, 0), calc(s, 1)); }
```

## 고생한 점
