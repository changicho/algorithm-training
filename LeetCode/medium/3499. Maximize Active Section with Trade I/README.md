# 3499. Maximize Active Section with Trade I

[링크](https://leetcode.com/problems/maximize-active-section-with-trade-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

순회하며 0인 구간의 길이들을 세는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

0인 구간의 길이를 저장할 경우 O(N)의 공간 복잡도를 사용한다.

직전, 현재 0인 구간의 길이를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 그리디 & 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      70      |    O(N)     |    O(1)     |

문제 조건에 따라서 다음과 같은 구간이 존재한다 하자.

`0인구간 - 1인구간 - 0인구간`

여기서 문제에 주어진 연산을 수행할 경우 해당 전체 구간의 길이만큼 1로 채울 수 있다.

이 때 증가하는 1의 갯수는 두 0인 구간의 합이된다.

이를 이용해 0인 구간을 세며 이전 0인 구간과 현재 0인 구간의 합, 전체 1의 갯수를 사용해 정답을 갱신한다.

```cpp
int maxActiveSectionsAfterTrade(string s) {
  int count = 0;
  int prev = 0;
  int total = 0;

  int answer = 0;
  for (char& c : s) {
    int cur = c - '0';

    if (cur == 0) {
      count++;
    } else {
      total++;
      if (count > 0) {
        prev = count;
      }
      count = 0;
    }

    if (prev > 0 && count > 0) {
      answer = max(answer, prev + count);
    }
  }

  return answer + total;
}
```

## 고생한 점
