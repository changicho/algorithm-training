# 17609. 회문

[링크](https://www.acmicpc.net/problem/17609)

| 난이도 |
| :----: |
| 골드 V |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

왼쪽에서 오른쪽으로, 오른쪽에서 왼쪽으로 순회하며 회문인지 판별한다.

회문인지 판별하는데 시간 복잡도는 O(N)이다.

이 때 현재 문자를 제거했을 때 회문이 되는 경우가 존재할 수 있으므로, 만약 회문이 아닌 경우에는 현재 문자를 제거하고 다시 회문인지 판별한다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

문자열을 저장하는데 필요한 공간이 필요하다.

이 경우 공간 복잡도는 O(N)이다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |    O(N)     |    O(N)     |

left, right index를 이용하는 투 포인터를 이용해 회문인지 판별한다.

이 때 현재 문자를 제거했을 때 회문이 되는 경우가 존재할 수 있으므로, 만약 회문이 아닌 경우에는 현재 문자를 제거하고 다시 회문인지 판별한다.

이 때 제거할 수 있는 문자는 left, right 중 하나이다.

```cpp
bool isPalindrome(string word) {
  int len = word.length();
  for (int i = 0; i < len / 2; i++) {
    if (word[i] != word[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

int solution(string word) {
  int size = word.length();

  int left = 0, right = word.length() - 1;

  while (left < right) {
    if (word[left] != word[right]) {
      if (isPalindrome(word.substr(left + 1, right - left))) {
        return 1;
      }
      if (isPalindrome(word.substr(left, right - left))) {
        return 1;
      }
      return 2;
    }
    left++;
    right--;
  }

  return 0;
}
```

## 고생한 점
