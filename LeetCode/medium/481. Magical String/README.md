# 481. Magical String

[링크](https://leetcode.com/problems/magical-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

법칙에 따라서 N까지의 문자열 s를 직접 만들 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

직접 길이 N이상의 문자열 s를 생성하는 경우 O(N)의 공간 복잡도를 사용한다.

### 직접 생성하기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      14      |    O(N)     |    O(N)     |

문제 법칙에 따라 시작 문자열을 생성 후 직접 채워나간다.

이 때 현재 채워야 하는 문자열의 갯수와 종류의 차이가 있음에 유의한다.

```cpp
int magicalString(int n) {
  string s = "12211";

  int index = 3;
  while (s.length() < n) {
    if (s[index] == '1') {
      if (s.back() == '2') {
        s += "1";
      } else {
        s += "2";
      }
    } else {
      if (s.back() == '2') {
        s += "11";
      } else {
        s += "22";
      }
    }
    index++;
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') count++;
  }
  return count;
}
```

## 고생한 점
