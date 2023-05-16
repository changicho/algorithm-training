# D. Umka and a Long Flight

[링크](https://codeforces.com/contest/1811/problem/D)

## 시간 복잡도

입력받은 피보나치 수열의 크기를 N이라 하자. (N <= 44)

각 단계마다 현재 좌표에 대해서 정사각형을 잘라냈을 때 해당 좌표가 남는지 여부를 체크한다.

이를 크기가 1이 될 때 까지 반복하면 되므로 O(N)의 시간 복잡도를 사용한다.

## 공간 복잡도

피보나치 수열을 저장하고 사용해야 한다. 이에 O(1)의 공간 복잡도를 사용한다.

재귀 호출로 구현할 경우 O(N)의 공간 복잡도를 사용한다.

## 재귀호출

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

문제에서 각 경우마다 F(n), F(n+1) 크기의 직사각형이 주어진다.

이 때 크기가 같은 정사각형은 한번씩만 배치 가능하므로 가장 큰 정사각형들을 각 단계바다 배치하는 것이 최적이다.

해당 직사각형에서 현재 좌표에 대해 다음을 수행할 수 있다.

- 현재 직사각형에 가장 큰 정사각형을 왼쪽, 오른쪽에 배치했을 때 해당 좌표가 남는지 여부를 체크한다.
- 이 때 해당 좌표는 수직을 기준으로 대칭시킬 수 있으므로, 더 작은 좌표로 치환한다.
- 만약 정사각형을 배치할 수 없는 경우 불가능하다.
- 정사각형을 배치할 수 있는 경우 해당 좌표를 남기고 다음 단계로 넘어간다. (더 작은 직사각형)
- 이를 크기가 1일 때 까지 반복한다.

즉 각 경우마다 정사각형을 배치했을 때 좌표를 남길 수 있는지 여부를 판단한다.

```cpp
auto solution(int n, long long x, long long y) {
  if (n == 0) return true;
  if (n == 1) return true;

  long long height = fibo[n];
  long long width = fibo[n + 1];

  long long squareSize = height;

  // compare width, x

  // convert x to lower than square
  if (width / 2 < x) {
    x = width - x + 1;
  }

  if (x + squareSize > width) {
    return false;
  }

  return solution(n - 1, y, x);
}
```