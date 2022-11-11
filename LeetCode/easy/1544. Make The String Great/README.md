# 1544. Make The String Great

[링크](https://leetcode.com/problems/make-the-string-great/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

스택을 이용해 현재 문자와 직전의 문자를 비교하고 제거할 수 있다.

이 경우 각 문자를 왼쪽부터 순회하는 데 O(N)의 시간 복잡도를 사용한다.

이후 모든 순회 과정에서 스택에서 push, pop연산에 O(N)의 시간 복잡도를 사용한다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

스택을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

문자를 순차적으로 순회하며 스택의 top과 비교한다.

이 때 두 문자는 대소문자 차이만 존재하고 같은 문자여야 한다.

이를 구현하면 다음과 같다.

```cpp
bool isBad(string &str) {
  int length = str.size();
  char a = str[length - 1], b = str[length - 2];
  if (a != b && (tolower(a) == tolower(b))) return true;
  return false;
}

string makeGood(string s) {
  string answer = "";

  for (char &c : s) {
    answer += c;

    while (answer.size() >= 2 && isBad(answer)) {
      answer.pop_back();
      answer.pop_back();
    }
  }

  return answer;
}
```

## 고생한 점
