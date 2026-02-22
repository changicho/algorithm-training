# A - Handmaid

[링크](https://atcoder.jp/contests/abc446/tasks/abc446_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

정답 문자열을 생성하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N)     |    O(N)     |

```cpp
string solution(string& s) {
  string answer = "Of";
  s[0] = tolower(s[0]);
  answer += s;
  return answer;
}
```

## 고생한 점
