# A - CBC

[링크](https://atcoder.jp/contests/abc402/tasks/abc402_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

문자열 S의 길이를 N이라 하자.

순회하며 대문자만 추출해 새로 문자열을 만드는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

새로운 문자열을 만드는데 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

```cpp
string solution(string &s) {
  string answer = "";

  for (char &c : s) {
    if (isupper(c)) {
      answer += c;
    }
  }

  return answer;
}
```

## 고생한 점
