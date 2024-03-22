# 1750. Minimum Length of String After Deleting Similar Ends

[링크](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

양 끝에서 부터 동일한 문자를 삭제해야 한다.

이를 투 포인터를 이용해 삭제되는 양 끝 문자들의 index를 이동시킬 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

투 포인터에 별도의 공간이 필요하지 않으므로 O(1)의 공간 복잡도가 필요하다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      27      |    O(N)     |    O(1)     |

비교할 양 끝 문자의 index를 left, right라 하자.

각 경우마다 삭제할 수 있는 문자들이 존재할 때마다 left, right를 이동시킨다.

이후 더이상 이동할 수 없는 경우 left, right를 이용해 남은 문자열의 길이를 구한다.

```cpp
int minimumLength(string s) {
  int size = s.size();

  int left = 0, right = size - 1;

  while (left < right) {
    char cur = s[left];
    int leftMove = 0, rightMove = 0;

    while (left < right && s[left] == cur) {
      left++;
      leftMove++;
    }

    while (right >= left && s[right] == cur) {
      right--;
      rightMove++;
    }

    if (leftMove == 0 || rightMove == 0) {
      left -= leftMove;
      right += rightMove;
      break;
    }
  }

  return right - left + 1;
}
```

## 고생한 점
