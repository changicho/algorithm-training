# 2245. Maximum Trailing Zeros in a Cornered Path

[링크](https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

끝자리가 10으로 끝나는 경우를 세기 위해 소인수를 이용한다. 이 경우 2와 5인 소인수의 경우만 세면 된다.

따라서 가능한 path에 따른 2와 5인 소인수의 갯수의 합을 구하면 된다. (곱은 인수들의 갯수의 합 이므로)

path는 한번만 꺾을 수 있으므로 prefixSum을 이용해 인수의 갯수를 한번에 구할 수 있다.

이 경우 prefixSum을 생성하는데 O(R \* C)의 시간 복잡도를 사용하며,

이후 path를 탐색하는 데 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefixSum을 사용하기 위해 O(R \* C)의 공간 복잡도를 사용한다.

### prefix sum with prime factor

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     490      |  O(R \* C)  |  O(R \* C)  |

path의 곱에서 끝자리 0의 갯수를 매번 세지 않고 2와 5인 소인수의 갯수를 세서 구할 수 있다.

이 경우 끝자리 0의 갯수는 2와 5인 소인수의 갯수 중 적은 쪽이다.

둘을 같이 관리하기 위해 다음과 같은 구조체를 사용한다.

```cpp
struct Pair {
  int two, five;

  Pair operator+(const Pair &b) const { return {two + b.two, five + b.five}; }
  Pair operator-(const Pair &b) const { return {two - b.two, five - b.five}; }
};
```

path의 경우의 수를 다음과 같이 볼 수 있다.

- 특정 좌표를 끝점으로 하는 4개의 직선이 있다고 하자.
- path의 소인수의 갯수는 해당 좌표를 기준으로 2개의 직선을 선택한 갯수가 된다. (같은 방향 제외)

직선의 소인수의 갯수를 빠르게 구하기 위해 prefixSum을 이용한다.

이후 각 좌표를 순회하며 각 좌표가 교차점이 되는 모든 경우의수를 비교하며 정답을 구한다.

이를 구현하면 다음과 같다.

```cpp
int countFactor(int number, int factor) {
  int count = 0;
  while (number % factor == 0) {
    number /= factor;
    count++;
  }
  return count;
}

int countPair(Pair p) { return min(p.two, p.five); }

int maxTrailingZeros(vector<vector<int>> &grid) {
  int rows = grid.size();
  int cols = grid.front().size();
  // count 2, 5
  vector<vector<Pair>> fromTop(rows + 1, vector<Pair>(cols + 1, {0, 0}));
  vector<vector<Pair>> fromLeft(rows + 1, vector<Pair>(cols + 1, {0, 0}));

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int num = grid[y][x];
      Pair factors = {countFactor(num, 2), countFactor(num, 5)};

      fromTop[y + 1][x] = fromTop[y][x] + factors;
      fromLeft[y][x + 1] = fromLeft[y][x] + factors;
    }
  }

  int countZero = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int num = grid[y][x];
      Pair v1 = fromTop[y + 1][x], v2 = fromTop[rows][x] - fromTop[y][x];
      Pair h1 = fromLeft[y][x + 1], h2 = fromLeft[y][cols] - fromLeft[y][x];
      // to remove duplicate
      Pair cur = {countFactor(num, 2), countFactor(num, 5)};

      countZero =
          max({countZero, countPair(v1 + h1 - cur), countPair(v1 + h2 - cur),
                countPair(v2 + h1 - cur), countPair(v2 + h2 - cur)});
    }
  }
  return countZero;
}
```

## 고생한 점
