# 2609. Find the Longest Balanced Substring of a Binary String

[링크](https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

순회를 진행하며 1과 0의 연속된 수를 셀 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

0, 1의 갯수를 세는데 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

s를 순회하며 0과 1의 연속된 수를 셀 수 있다.

이 때 0이 나온 경우 이전에 센 0, 1의 수를 초기화한다.

각 과정마다 0, 1의 수 중에서 작은 수를 정답으로 갱신한다.

```cpp
int findTheLongestBalancedSubstring(string s) {
  int ones = 0, zeros = 0;

  int answer = 0;
  for (char c : s) {
    if (c == '0') {
      if (ones > 0) {
        ones = 0;
        zeros = 0;
      }
      zeros++;
    } else {
      ones++;

      answer = max(answer, min(zeros, ones) * 2);
    }
  }

  return answer;
}
```

## 고생한 점
