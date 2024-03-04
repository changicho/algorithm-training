# 2864. Maximum Odd Binary Number

[링크](https://leetcode.com/problems/maximum-odd-binary-number/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

s를 순회하며 1의 갯수를 세고 이를 탐욕 알고리즘을 이용해 재배열한다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

1의 갯수를 세는 데 O(1)의 공간 복잡도가 필요하다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

s를 홀수로 만들기 위해 맨 마지막 비트는 1이여야 한다.

이후 가장 큰 홀수를 만들기 위해선 남은 1들을 맨 앞에 배치해야 한다.

따라서 1의 갯수를 세고, 이를 이용해 재배열한 가장 큰 홀수를 만들 수 있다.

```cpp
string maximumOddBinaryNumber(string s) {
  int size = s.size();
  int oneCount = 0;
  for (char &c : s) {
    if (c == '1') oneCount++;
  }

  s[size - 1] = '1';
  oneCount--;

  for (int i = 0; i < size - 1; i++) {
    if (oneCount > 0) {
      s[i] = '1';
      oneCount--;
    } else {
      s[i] = '0';
    }
  }
  return s;
}
```

## 고생한 점
