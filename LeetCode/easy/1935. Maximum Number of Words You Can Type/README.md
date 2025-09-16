# 1935. Maximum Number of Words You Can Type

[링크](https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 문자열의 길이를 각각 N, M이라 하자.

고장난 알파벳을 순회해 저장하는데 O(M)의 시간 복잡도를 사용한다.

각 단어별로 고장난 알파벳을 포함하는지 판단하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

알파벳의 종류는 26가지 이며 각각 고장났는지 저장하는 데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(1)     |

고장난 알파벳 테이블을 생성한 뒤, 각 단어별로 순회하며 고장난 알파벳을 포함하는지 판단한다.

```cpp
int canBeTypedWords(string text, string brokenLetters) {
  bool broken[26] = {
      false,
  };

  for (char &c : brokenLetters) {
    broken[c - 'a'] = true;
  }

  bool flag = false;
  int answer = 0;
  for (char &c : text) {
    if (c == ' ') {
      answer++;
      answer -= flag;
      flag = false;
      continue;
    }
    if (broken[c - 'a']) flag = true;
  }
  answer -= flag;
  answer++;

  return answer;
}
```

## 고생한 점
