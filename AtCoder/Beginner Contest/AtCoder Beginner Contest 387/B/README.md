# B - 9x9 Sum

[링크](https://atcoder.jp/contests/abc387/tasks/abc387_b)

| 난이도 |
| :----: |
|  150   |

## 설계

### 시간 복잡도

9 * 9 크기의 정방행렬에서 각 값들의 합을 구해야 한다.

이 때 입력받은 수에 해당하는 값은 합에 더하지 않는다.

이를 순회하는 데 O(1)의 시간 복잡도가 소요된다.

### 공간 복잡도

정방행렬의 합은 int형을 벗어나지 않는다.

합에 O(1)의 공간 복잡도가 필요하다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
long long solution(int target) {
  long long sum = 0;
  long long allSum = 0;

  for (int y = 1; y <= 9; y++) {
    for (int x = 1; x <= 9; x++) {
      int cur = (y) * (x);
      allSum += cur;

      if (cur != target) {
        sum += cur;
      }
    }
  }

  return sum;
}
```

## 고생한 점
