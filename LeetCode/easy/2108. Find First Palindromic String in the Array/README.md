# 2108. Find First Palindromic String in the Array

[링크](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 words의 크기를 N, 문자열의 최대 길이를 L이라 하자.

모든 word를 순서대로 순회하며 팰린드롬인지 확인할 경우 시간 복잡도는 O(N \* L)이다.

### 공간 복잡도

index를 이용해 팰린드롬 여부를 판별할 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      54      |  O(N \* L)  |    O(1)     |

words를 순회하며 word가 팰린드롬인지 확인한다.

```cpp
bool isPalindrome(string &word) {
  int size = word.size();
  for (int i = 0; i < size / 2; i++) {
    int rI = size - 1 - i;

    if (word[i] != word[rI]) return false;
  }
  return true;
}

string firstPalindrome(vector<string> &words) {
  for (string &word : words) {
    if (isPalindrome(word)) return word;
  }
  return "";
}
```

## 고생한 점
