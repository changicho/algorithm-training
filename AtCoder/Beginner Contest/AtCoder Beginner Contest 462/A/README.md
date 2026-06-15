# A - Secret Numbers

[링크](https://atcoder.jp/contests/abc462/tasks/abc462_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

문자열 S의 길이를 N이라 하자.

순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

왼쪽부터 순회하며 숫자인 경우만 정답에 더한다.

```cpp
string solution(string& s) {
  string answer = "";
  for (char& c : s) {
    if ('0' <= c && c <= '9') answer += c;
  }

  return answer;
}
```

## 고생한 점
