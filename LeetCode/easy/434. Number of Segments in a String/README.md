# 434. Number of Segments in a String

[링크](https://leetcode.com/problems/number-of-segments-in-a-string/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

문자열을 순회하며 구할 경우 O(N)의 시간 복잡도를 사용한다.

stringstream을 이용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

공백이 아닌 다른 문자들을 묶는것을 판단하기 위해 문자열을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

문자열 대신 길이만 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

문자열을 순회하며 공백이 아닌 경우 count를 증가시키고 공백인 경우 count가 0이 아닐 때 정답을 증가시킨다.

```cpp
int countSegments(string s) {
  int tempLength = 0;
  int answer = 0;
  for (char &c : s) {
    if (c == ' ') {
      if (tempLength > 0) answer++;
      tempLength = 0;
      continue;
    }
    tempLength++;
  }
  if (tempLength > 0) answer++;

  return answer;
}
```

## 고생한 점
