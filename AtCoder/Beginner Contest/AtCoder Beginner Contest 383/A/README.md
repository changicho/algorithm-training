# A - aaaadaa

[링크](https://atcoder.jp/contests/abc384/tasks/abc384_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

순회하며 변환하면 되므로 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

새로운 문자열에 O(N)의 공간 복잡도가 필요하다.

### 순회

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

순회하며 c1이 아닌 문자를 모두 c2로 바꾼다.

```cpp
string solution(int size, string &s, char &c1, char &c2) {
  string answer = "";

  for (char &c : s) {
    if (c != c1) {
      answer += c2;
    } else {
      answer += c;
    }
  }

  return answer;
}
```

## 고생한 점
