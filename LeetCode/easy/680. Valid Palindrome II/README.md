# 680. Valid Palindrome II

[링크](https://leetcode.com/problems/valid-palindrome-ii/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 L이라 하자.

문자열이 팰린드롬인지 판단하는데 투 포인터를 사용해 O(L)의 시간 복잡도를 사용한다.

만약 현재 글자에서 팰린드롬이 아닌경우 포인터를 이동해 2가지 경우에 대해 팰린드롬을 판단할 수 있다.

이 경우 O(L)의 시간 복잡도를 사용하므로 총 시간 복잡도는 O(L)이다.

### 공간 복잡도

투 포인터를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      60      |    O(L)     |    O(1)     |

left, right 투 포인터를 이용해 다음 index로 이동시키며 팰린드롬 여부를 탐색한다.

이 때 현재 index에서 팰린드롬이 아닌 경우 두가지 경우에 대해서 팰린드롬 여부를 탐색한다.

- left를 skip
- right를 skip

이 중 하나라도 팰린드롬인 경우 정답은 true가 된다.

```cpp
bool isValid(string &s, int left, int right) {
  while (left < right) {
    if (s[left] == s[right]) {
      left++;
      right--;
    } else {
      return false;
    }
  }
  return true;
}

bool validPalindrome(string s) {
  int length = s.length();
  int left = 0, right = length - 1;

  while (left < right) {
    if (s[left] == s[right]) {
      left++;
      right--;
      continue;
    }

    // skip one char from currnet
    return isValid(s, left + 1, right) || isValid(s, left, right - 1);
  }
  return true;
}
```

## 고생한 점
