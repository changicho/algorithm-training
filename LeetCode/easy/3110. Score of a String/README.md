# 3110. Score of a String

[링크](https://leetcode.com/problems/score-of-a-string/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

주어진 문자열 s의 길이를 N이라 하자.

순회를 이용해 구현할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

차이만 저장할 경우 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N)     |    O(1)     |

순회하며 양 옆에 붙어있는 문자의 차이만큼 정답에 더한다.

```cpp
int scoreOfString(string s) {
  int size = s.size();

  int answer = 0;
  for (int i = 0; i < size - 1; i++) {
    answer += abs(s[i] - s[i + 1]);
  }

  return answer;
}
```

## 고생한 점
