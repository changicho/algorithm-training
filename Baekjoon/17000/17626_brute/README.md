# 17626. Four Squares

[링크](https://www.acmicpc.net/problem/17626)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver V |   60.331    |

## 설계

### 시간 복잡도

N은 최대 50,000 까지이다.

1부터 N까지 증가시키며 몇개의 숫자로 만들 수 있는지를 갱신해나간다.

이 때 제곱수로 만들 수 있는 경우만 count하며 갱신하면 된다.

따라서 시간 복잡도는 다음과 같다.

```cpp
O(N * sqrt(N))
```

이는 제한시간 내에 충분하다.

### 공간 복잡도

N은 50,000 이하의 자연수이므로 int형으로 충분하다.

최악의 경우도 1의 합으로 나타내므로 정답은 50,000 이하임이 보장된다.

### 메모이제이션

현재 숫자는 다음과 같이 나타낼 수 있다.

현재 숫자 = 제곱수 + 숫자

따라서 현재 숫자에서 제곱수를 뺸 나머지 숫자들 중에서, 가장 count가 적은 것을 고른다.

```cpp
for (int cur = 2; cur <= N; cur++) {
  int count = memoization[cur - 1];

  for (int number : sqrt_numbers) {
    if (number > cur) break;

    count = min(count, memoization[cur - number]);
  }

  memoization[cur] = count + 1;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      12      |       0        |

## 고생한 점
