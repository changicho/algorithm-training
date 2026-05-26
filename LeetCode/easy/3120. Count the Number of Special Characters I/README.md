# 3120. Count the Number of Special Characters I

[링크](https://leetcode.com/problems/count-the-number-of-special-characters-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

배열의 각 문자를 카운팅 후 판단할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 문자를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 알파벳의 갯수를 센 뒤 소문자, 대문자가 모두 존재하는지 판단한다.

```cpp
int numberOfSpecialChars(string word) {
  int count[256] = {
      0,
  };

  for (char& c : word) {
    count[c]++;
  }

  int answer = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i + 'a'] > 0 && count[i + 'A'] > 0) answer++;
  }
  return answer;
}
```

## 고생한 점
