# 168. Excel Sheet Column Title

[링크](https://leetcode.com/problems/excel-sheet-column-title/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

숫자는 최대 2^31 - 1 이다.

A ~ Z 까지 총 26개의 알파벳이 있으며 알파벳 숫자로 표현할 경우 2^31 - 1 을 표현하기 위해선 최대 7자리가 필요하다.

(26^i) > (2^31 - 1) 인 i는 7이다.

따라서 O(7) 이내에 풀이가 가능하다.

### 공간 복잡도

문제를 풀이하기 위해 columnNumber를 숫자로 변환했을 때 맨 끝자리부터 채워나간다.

이 때 별도의 공간이 필요하지 않으므로 필요한 공간 복잡도는 O(1)이다.

### 수 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

1부터 26까지 알파벳으로 나타낼 수 있고 27부터 AA로 나타내는것에 유의한다.

일반적으로 0에 해당하는 알파벳이 없고, mod 연산으로는 0을 표현할 수 있으므로 columnNumber에서 1을 뺀 값들을 이용해 변환을 수행한다.

이 때 끝자리 부터 변환한 후 이후 뒤집는 연산을 수행한다.

한번 끝자리를 채운 후에는 26으로 수를 나눠준 몫을 사용하며, 나눠준 이후에도 1을 빼서 알파벳을 사용한다.

만약 연산한 결과의 columnNumber이 0 미만인 경우 변환을 중지한다.

```cpp
string convertToTitle(int columnNumber) {
  string ret = "";
  columnNumber -= 1;

  while (columnNumber >= 0) {
    int div = columnNumber % 26;
    columnNumber /= 26;
    columnNumber -= 1;

    ret += (char)('A' + div);
  }

  reverse(ret.begin(), ret.end());
  return ret;
}
```

## 고생한 점
