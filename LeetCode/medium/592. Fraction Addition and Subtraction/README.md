# 592. Fraction Addition and Subtraction

[링크](https://leetcode.com/problems/fraction-addition-and-subtraction/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 expression의 길이를 N이라 하자.

expression을 순회하며 분수를 추출하고 더하는 연산을 수행해야 한다.

이에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

분자와 분모를 저장할 변수가 필요하다.

이에 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

각 문자열을 순회하며 숫자의 부호와 분자, 분모를 추출한다.

이후 직전 분수와 현재 분수를 더한 뒤, 최대공약수를 구해 최대공약수로 나눈 값을 반환한다.

```cpp
struct Number {
  int a, b;
};

Number trim(Number num) {
  int gcdVal = abs(gcd(num.a, num.b));

  return {num.a / gcdVal, num.b / gcdVal};
}

Number add(Number a, Number b) {
  int commonB = a.b * b.b;

  a.a *= commonB / a.b;
  a.b = commonB;

  b.a *= commonB / b.b;
  b.b = commonB;

  return trim({a.a + b.a, a.b});
}

string fractionAddition(string expression) {
  int size = expression.size();

  Number answer = {0, 1};

  int i = 0;
  while (i < size) {
    int digit = +1;
    if (expression[i] == '-') {
      digit = -1;
      i++;
    } else if (expression[i] == '+') {
      i++;
    }

    int a = 0;
    while (i < size && isdigit(expression[i])) {
      a = a * 10 + expression[i] - '0';
      i++;
    }
    if (digit == -1) a *= -1;

    // skip '/'
    i++;

    digit = +1;
    if (expression[i] == '-') {
      digit = -1;
      i++;
    }

    int b = 0;
    while (i < size && isdigit(expression[i])) {
      b = b * 10 + expression[i] - '0';
      i++;
    }
    if (digit == -1) b *= -1;

    answer = add(answer, {a, b});
  }

  return to_string(answer.a) + "/" + to_string(answer.b);
}
```

## 고생한 점
