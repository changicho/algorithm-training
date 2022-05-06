# 7. Reverse Integer

[링크](https://leetcode.com/problems/reverse-integer/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

숫자를 N이라 하자.

이를 거꾸로 뒤집어야 하므로 각 자리수별로 순회할 때 10의 자리수만큼 순회하게 된다.

이는 O(log_10(N))이다.

### 공간 복잡도

새로운 수를 생성하는 데 상수만큼의 공간 복잡도를 사용할 수 있다.

이는 O(1)의 공간 복잡도를 사용한다.

### 나머지

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      9       | O(log_10(N)) |    O(1)     |

MOD연산을 이용해 각 자리수를 추출하고, 10씩 나누고 새로운 수는 10씩 곱해 자리를 맞춰준다.

이를 이용하면 수를 역순으로 순회하게 되므로 수를 뒤집을 수 있다.

이 때 INT 범위를 초과할 수 있으므로 미리 체크해준다.

이를 구현하면 다음과 같다.

```cpp
int reverse(int x) {
  bool isNeg = x < 0;

  int ret = 0;
  while (x) {
    if (isNeg && ret < INT_MIN / 10) return 0;
    if (!isNeg && ret > INT_MAX / 10) return 0;

    ret *= 10;
    ret += x % 10;
    x /= 10;
  }
  return ret;
}
```

## 고생한 점
