# 12. Integer to Roman

[링크](https://leetcode.com/problems/integer-to-roman/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

숫자의 최대 값은 3999이다. 각 자리수별로 로마숫자로 변경하면 되므로 시간 복잡도는 O(log_10(N)) 이다.

이는 최악의 경우도 O(4)다.

### 공간 복잡도

각 숫자를 로마숫자로 매핑할 테이블이 필요하다. 숫자의 종류는 7개 이므로 O(7)의 공간이 필요하다.

### 자리수별 변환

현재 자리의 변환은 다음과 같은 분기로 이루어진다.

- 9 ~ : 빼는 경우
- 5 ~ 8 : 더하는 경우
- 4 ~ 5 : 빼는 경우
- 1 ~ 3 : 더하는 경우

각 자리수별로 순회하며 각 조건마다 로마숫자로 변하고 반환한다.

```cpp
string intToRoman(int num) {
  string answer = "";
  char table[1001];

  table[1] = 'I';
  table[5] = 'V';
  table[10] = 'X';
  table[50] = 'L';
  table[100] = 'C';
  table[500] = 'D';
  table[1000] = 'M';

  for (int digit = 1000; digit > 0; digit /= 10) {
    if (num >= digit) {
      int count = num / digit;
      num %= digit;

      if (count > 8) {
        for (int i = 0; i < 10 - count; i++) {
          answer += table[digit];
        }
        answer += table[digit * 10];
      } else if (count > 5) {
        answer += table[digit * 5];
        for (int i = 0; i < count - 5; i++) {
          answer += table[digit];
        }
      } else if (count > 3) {
        for (int i = 0; i < 5 - count; i++) {
          answer += table[digit];
        }
        answer += table[digit * 5];
      } else if (count > 0) {
        for (int i = 0; i < count; i++) {
          answer += table[digit];
        }
      }
    }
  }

  return answer;
}
```

### 최적화

위 규칙을 보면 다음을 파악할 수 있다.

빼는 경우는 맨 앞자리가 9, 4 인 경우만이다.

또한 더하는 경우는 큰 숫자가 앞에 나와야 한다.

따라서 앞자리가 다음과 같은 경우에 탐색을 진행한다.

단위가 큰 경우부터 탐색하며 빼는 경우에 대해 미리 처리하고, 이후 더하는 경우를 고려해 로마 숫자를 제작한다.

```cpp
1 4 5 9 10 ~ ...
```

```cpp
string intToRoman(int num) {
  string romans[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
  int numerals[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

  string answer = "";
  for (int i = 12; i >= 0; i--) {
    int count = num / numerals[i];

    if (count > 0) {
      while (count--) {
        answer += romans[i];
      }

      num %= numerals[i];
    }
  }
  return answer;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
