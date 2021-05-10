# 171. Excel Sheet Column Number

[링크](https://leetcode.com/problems/excel-sheet-column-number/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

columnTitle의 길이는 최대 7이다.

한번 순회를 통해 수로 변환할 수 있으므로 시간 복잡도는 O(7)이다.

### 공간 복잡도

별도의 공간이 필요하지 않으므로 O(1)이다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

첫째 자리부터 변환을 수행하며, 다음자리로 넘어갈 때 현재 숫자에 26을 곱해준다.

A가 1에 대응해야 하므로 문자에서 아스키 코드 값 A의 값을 빼준 뒤 1을 더해준다.

```cpp
int titleToNumber(string columnTitle) {
  int ret = 0;
  int length = columnTitle.length();

  for (char c : columnTitle) {
    ret = ret * 26 + (c - 'A' + 1);
  }

  return ret;
}
```

## 고생한 점
