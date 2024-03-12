# A - Spoiler

[링크](https://atcoder.jp/contests/abc344/tasks/abc344_a)

| 난이도 |
| :----: |
|  150   |

## 설계

### 시간 복잡도

입력받은 문자열 S의 길이를 N이라 하자.

순회하며 '|' 로 감싸진 부분을 찾아야 한다. 이에 필요한 시간 복잡도는 O(N) 이다.

### 공간 복잡도

변환된 문자열을 생성하는데 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

'|' 로 감싸진 부분을 찾는다.

'|' 문자는 S에 2개만 존재하므로 toggle 변수를 이용해 현재 감싸진 부분인지 판단한다.

```cpp
string solution(string &s) {
  string answer = "";
  int size = s.size();

  bool toggle = false;

  for (char &c : s) {
    if (c == '|') {
      toggle = !toggle;
    } else {
      if (toggle) {
        continue;
      } else {
        answer += c;
      }
    }
  }

  return answer;
}
```

## 고생한 점
