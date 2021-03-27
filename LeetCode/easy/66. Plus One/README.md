# 66. Plus One

[링크](https://leetcode.com/problems/plus-one/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

digits 배열의 최대 길이는 100이다. 덧셈시 시간 복잡도는 자리수에 영향을 받으므로 최악의 경우 시간 복잡도는 O(100) 이다.

O(log_10(N))

### 공간 복잡도

digits내부의 수는 0~9 까지만 가능하다.

### 덧셈

digits 배열의 맨 마지막 값에 1을 더해주고, 끝에서부터 순회하며 10이상인 경우 올림 작업을 수행한다.

```cpp
vector<int> plusOne(vector<int>& digits) {
  int length = digits.size();
  digits[length - 1] += 1;
  bool hasNewOne = false;
  for (int i = length - 1; i >= 0; i--) {
    if (digits[i] >= 10) {
      digits[i] -= 10;

      if (i - 1 >= 0) {
        digits[i - 1] += 1;
      } else {
        hasNewOne = true;
      }
    } else {
      break;
    }
  }

  if (hasNewOne) {
    digits.insert(digits.begin(), 1);
  }

  return digits;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      8       |

## 고생한 점
