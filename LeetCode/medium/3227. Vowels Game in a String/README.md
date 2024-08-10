# 3227. Vowels Game in a String

[링크](https://leetcode.com/problems/vowels-game-in-a-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 문자열 s의 길이를 N이라 하자.

s의 모음의 수를 세 정답을 구할 수 있다. 이에 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

모음의 수를 저장하는 데 O(1)의 공간 복잡도가 필요하다.

### 모음의 수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      65      |    O(N)     |    O(1)     |

alice는 홀수개의 모음을 제거해야한다. bob은 짝수개의 모음을 제거해야한다.

만약 현재 문자열의 모음의 갯수가 0개인 경우 alice는 제거할 문자열이 없으므로 패배한다.

모음의 수가 짝수인 경우, alice가 먼저 홀수개를 제거할 경우, bob이 아무리 제거해도 최종적으로는 홀수개의 모음이 남으므로 alice가 승리한다.

모음의 수가 홀수인 경우 모두 삭제할 수 있으므로 alice가 승리한다.

```cpp
unordered_set<char> us = {'a', 'e', 'i', 'o', 'u'};

bool doesAliceWin(string s) {
  int vowels = 0;

  for (int i = 0; i < s.size(); i++) {
    char c = s[i];

    if (us.count(c)) vowels++;
  }

  // alice : odd
  // bob : even
  if (vowels == 0) return false;

  return true;
}
```

## 고생한 점
