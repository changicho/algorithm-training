# 2000. Reverse Prefix of Word

[링크](https://leetcode.com/problems/reverse-prefix-of-word/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 문자열 word의 길이를 N이라 하자.

순회하며 ch와 같은 문자를 찾고 이를 뒤집을 수 있다.

이에 각각 O(N)의 시간 복잡도를 사용하므로 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

순회, 뒤집기에 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

```cpp
string reversePrefix(string word, char ch) {
  int size = word.size();

  for (int i = 0; i < size; i++) {
    if (word[i] == ch) {
      reverse(word.begin(), word.begin() + i + 1);
      break;
    }
  }

  return word;
}
```

## 고생한 점
