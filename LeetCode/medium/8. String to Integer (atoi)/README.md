# 8. String to Integer (atoi)

[링크](https://leetcode.com/problems/string-to-integer-atoi/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이는 최대 200이다. 문자열을 순회하며 숫자를 찾아야 하므로 시간복잡도는 O(N)이다.

### 공간 복잡도

정답은 int형 범위이다. int형을 초과하는 경우를 고려하기 위해 long 을 사용할 수 있다.

### 순회

고려해야 되는 경우는 다음과 같다.

- 처음 숫자가 나오기 전까지 공백
- +, - 기호
- 문자가 먼저 나오는 경우는 skip
- 숫자가 나오다 문자가 나오는 경우

따라서 문자를 순회하며 해당 조건에 맞는 경우들을 고려한다.

```cpp
int myAtoi(string s) {
  long long ret = 0;

  long long lowerLimit = -2147483648;
  long long upperLimit = 2147483647;

  bool isNumberStart = false;
  bool isPlus = false;
  bool isMinus = false;
  for (char c : s) {
    if (c == ' ') {
      if (isNumberStart || isPlus || isMinus) break;
      continue;
    }
    if (c == '.') break;
    if (c == '-' || c == '+') {
      if (isNumberStart) break;
      if (isMinus || isPlus) {
        ret = 0;
        break;
      }

      if (c == '-') {
        isMinus = true;
      } else {
        isPlus = true;
      }
      continue;
    }

    if (c >= '0' && c <= '9') {
      ret *= 10;
      if (isMinus && ret * -1 < lowerLimit) {
        ret = lowerLimit * -1;
        break;
      }
      if (ret > upperLimit) {
        ret = upperLimit;
        break;
      }
      ret += c - '0';
      isNumberStart = true;
      continue;
    }
    break;
  }

  if (isMinus) ret *= -1;

  if (ret > 0 && ret >= upperLimit) {
    ret = upperLimit;
  }
  if (ret < 0 && ret <= lowerLimit) {
    ret = lowerLimit;
  }

  return (int)ret;
}
```

해당 로직을 다음 3부분으로 분해해 생각할 수 있다.

- 공백과 기호를 판단하는 부분
- 숫자를 찾는 부분
- 숫자가 끝나는 부분

해당 부분을 다음과 같이 표현한다.

```cpp
int myAtoi(string str) {
  int i = 0;
  int sign = 1;
  int result = 0;
  if (str.length() == 0) return 0;

  // find biginning
  while (i < str.length() && str[i] == ' ') {
    i++;
  }

  // Check if optional sign if it exists
  if (i < str.length() && (str[i] == '+' || str[i] == '-')) {
    sign = (str[i] == '-') ? -1 : 1;
    i++;
  }

  // find number
  while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
    int cur = str[i] - '0';
    bool isOver = result > INT_MAX / 10;
    bool isFit = (result == INT_MAX / 10 && cur > INT_MAX % 10);

    if (isOver || isFit) {
      return (sign == 1) ? INT_MAX : INT_MIN;
    }
    result *= 10;
    result += cur;
    i++;
  }
  return result * sign;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
