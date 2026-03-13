# 3856. Trim Trailing Vowels

[링크](https://leetcode.com/problems/trim-trailing-vowels/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

순회를 이용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

맨 뒤에 붙는 모음들을 삭제하면 된다.

```cpp
string trimTrailingVowels(string s) {
  bool isVowel[26] = {false};
  isVowel['a' - 'a'] = true;
  isVowel['e' - 'a'] = true;
  isVowel['i' - 'a'] = true;
  isVowel['o' - 'a'] = true;
  isVowel['u' - 'a'] = true;

  int size = s.size();
  int target = -1;
  for (int i = size - 1; i >= 0; i--) {
    if (!isVowel[s[i] - 'a']) {
      target = i;
      break;
    }
  }

  return s.substr(0, target + 1);
}
```

## 고생한 점
