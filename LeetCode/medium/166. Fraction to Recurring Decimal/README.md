# 166. Fraction to Recurring Decimal

[링크](https://leetcode.com/problems/fraction-to-recurring-decimal/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 두 수를 N, M이라 하자.

나누기 연산을 수행하므로 이는 거의 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 문자열에 O(1)의 공간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

직접 나누기 연산을 구현한다.

이 때 반복되는 부분을 찾기 위해 미리 해시맵에 반복되는 소숫점들을 저장한다.

```cpp
string fractionToDecimal(int numerator, int denominator) {
  if (numerator == 0) {
    return "0";
  }
  string answer;

  if (numerator < 0 ^ denominator < 0) {
    answer.append("-");
  }

  long long a = abs((long long)numerator);
  long long b = abs((long long)denominator);

  answer.append(to_string(a / b));

  long long r = a % b;
  if (r == 0) {
    return answer;
  }

  answer.append(".");
  unordered_map<long long, int> map;
  while (r != 0) {
    if (map.count(r) > 0) {
      answer.insert(map[r], "(");
      answer.append(")");
      break;
    }

    map[r] = answer.length();
    r *= 10;
    answer.append(to_string(r / b));
    r %= b;
  }
  return answer;
}
```

## 고생한 점
