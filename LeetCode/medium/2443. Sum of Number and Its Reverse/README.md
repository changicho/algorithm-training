# 2443. Sum of Number and Its Reverse

[링크](https://leetcode.com/problems/sum-of-number-and-its-reverse/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. N은 최대 10^5 이다.

1부터 N까지 순회하며 더해서 N이 생성되는 수를 찾는다.

이 경우 숫자 변환에 O(1)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

별도의 공간을 사용하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      59      |    O(N)     |    O(1)     |

0부터 순회하며 현재 숫자와 뒤집은 숫자를 더했을 때 num을 만들 수 있는지 판단한다.

```cpp
int reverseDigit(int num) {
  int ret = 0;
  while (num > 0) {
    ret *= 10;
    ret += num % 10;
    num /= 10;
  }
  return ret;
}

bool sumOfNumberAndReverse(int num) {
  for (int i = 0; i <= num; i++) {
    if (i + reverseDigit(i) == num) {
      return true;
    }
  }
  return false;
}
```

## 고생한 점

0인 경우에 대한 처리
