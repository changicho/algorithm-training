# 266. Palindrome Permutation

[링크](https://leetcode.com/problems/palindrome-permutation/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 문자의 수를 세면 팰린드롬으로 변환이 가능한 지 판별할 수 있다.

이 순회에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

count한 값을 알고 있어야 하므로 O(N)의 공간 복잡도가 필요하다.

### odd count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 문자별로 나타나는 수를 센다.

이후 각 count가 모두 짝수인 경우와, 한 문자만 홀수고 나머지는 모두 짝수인 경우만 팰린드롬으로 변환이 가능하다.

```cpp
bool canPermutePalindrome(string s) {
  unordered_map<char, int> um;

  for (char c : s) {
    um[c] += 1;
  }

  int oddCount = 0;
  for (auto &it : um) {
    if (it.second % 2 == 1) {
      oddCount += 1;
    }
  }

  return oddCount < 2;
}
```

## 고생한 점
