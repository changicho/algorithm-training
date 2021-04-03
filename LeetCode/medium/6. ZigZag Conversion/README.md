# 6. ZigZag Conversion

[링크](https://leetcode.com/problems/zigzag-conversion/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이는 최대 1000이다.

문자들을 순회하며 해당하는 문자열을 생성할 경우 시간 복잡도는 O(N) 이다.

### 공간 복잡도

문자열 내부 문자의 자료의 범위는 다음과 같다.

- 영어 소문자
- 영어 대문자
- 쉼표, 마침표

### 순회

> 4ms

- 시간 복잡도 O(N)
- 공간 복잡도 O(N)

각 level 별로 vector를 만든 뒤, 문자열을 순회함과 동시에 index를 옮겨가며 해당하는 vector의 index에 추가해준다.

맨 마지막에 vector 내부의 문자열을 전부 합치고 return한다.

이 때 index는 지그제그로 순회해야 하므로 임계값에 도달했을 경우 증감을 toggle한다.

level이 1인경우에 증감이 일어나면 안됨으로 유의한다.

```cpp
string convert(string s, int numRows) {
  vector<string> rows(numRows);

  int index = 0;
  int diff = +1;
  for (char c : s) {
    rows[index] += c;

    index += diff;
    if (index == numRows - 1) {
      diff = -1;
    } else if (index == 0) {
      diff = +1;
    }
    index %= numRows;
  }

  string answer = "";
  for (string line : rows) {
    answer += line;
  }

  return answer;
}
```

### 규칙을 이용

- 시간 복잡도 : O(N)
- 공간 복잡도 : O(1)

rows의 길이가 주어질 때 index를 순회하는 규칙을 다음과 같이 나타낼 수 있다.

```cpp
// 모든 문자열의 index k에 대해
k * (2 * numRows − 2) // 0번째 줄
k * (2 * numRows − 2) + numRows − 1 // 맨 마지막 줄
k * (2 * numRows -2) + i, (k + 1) * (2 * numRows -2) - i // 그 외 나머지 i번째 줄
```

```cpp
string convert(string s, int numRows) {
  if (numRows == 1) return s;

  string ret = "";
  int N = s.length();
  int cycleLen = 2 * numRows - 2;

  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j + i < N; j += cycleLen) {
      ret += s[j + i];
      if (i != 0 && i != numRows - 1 && j + cycleLen - i < N) {
        ret += s[j + cycleLen - i];
      }
    }
  }
  return ret;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
