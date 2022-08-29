# 2390. Removing Stars From a String

[링크](https://leetcode.com/problems/removing-stars-from-a-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

한번 순회하는 데 O(N)의 시간 복잡도를 사용한다.

stack 을 이용해 *와 다른 문자를 지울 경우 총 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

stack을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     114      |    O(N)     |    O(N)     |

문자는 다음 두 종류가 존재한다.

- 별
- 별이 아닌 문자

별을 만날 경우 남은 문자들 중 가장 가까이 왼쪽에 있는 문자를 제거한다.

왼쪽부터 순회하며 스택 구조에 문자를 쌓는다고 생각할 경우 top을 제거하면 된다.

이를 구현하면 다음과 같다.

```cpp
string removeStars(string s) {
  string answer = "";

  for (char &c : s) {
    if (c == '*') {
      if (answer.size() == 0) continue;

      answer.pop_back();
      continue;
    }
    answer.push_back(c);
  }

  return answer;
}
```

## 고생한 점
