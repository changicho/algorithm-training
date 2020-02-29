# 4375. 1

[링크](https://www.acmicpc.net/problem/4375)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Silver III |     40      |

## 설계

### N의 배수가 1로 이루어진 수인지

1 부터 시작하며 N의 배수인지 검사한다.

1, 11, 111 ...

i번째 수가 N의 배수라면 i를 출력한다.

여기서 i가 매우 클 수 있으므로, 1로 이루어진 수는 string으로 구현한다.

### 매우 큰 수가 m의 배수인지 검사

```cpp
bool canDivide(string number, int m) {
  int temp = 0;

  for (int i = 0; i < number.length(); i++) {
    temp *= 10;
    temp += number[i]-'0';
    temp %= m;
  }
  return temp == 0;
}
```

초등학교때 배운 나누기 식을 이용해 구한다.

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
| 668 ms  |           |

## 고생한 점
