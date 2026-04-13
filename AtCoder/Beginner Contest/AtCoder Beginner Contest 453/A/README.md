# A - Trimo

[링크](https://atcoder.jp/contests/abc453/tasks/abc453_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

앞부분에 o가 붙은 부분을 제거하기위해 순회에 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

정답 문자열에 O(N)의 공간 복잡도를 갖는다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

문자열 앞부분에 o가 붙은 부분을 제외하고 정답 문자열에 추가한다.

```cpp
string solution(int size, string& s) {
  string answer = "";

  bool find = false;
  for (char& c : s) {
    if (c == 'o' && !find) continue;
    find = true;
    answer += c;
  }

  return answer;
}
```

## 고생한 점
