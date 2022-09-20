# Problem B2: Watering Well - Chapter 2

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/problems/B2)

| 난이도 |
| :----: |
| 18 pt  |

## 설계

### 시간 복잡도

나무와 연못의 크기를 각각 N, Q라 하자.

이를 모두 순회할 경우 시간 복잡도는 O(N \* Q)이며 이는 N과 Q의 범위가 500,000 까지 이므로 제한시간 내에 불가능하다.

각 좌표의 범위 또한 최대 10^9 이므로 좌표에 대해 순회하는것도 불가능하다.

유클리드 거리를 구하는 수식을 변경해, 하나의 나무에 대해 다른 모든 연못까지의 거리의 합을 O(1)의 시간 복잡도로 구할 수 있다.

이 경우 시간 복잡도는 O(N)이 된다.

### 공간 복잡도

각 좌표들을 저장해야 하므로 O(N + Q)의 공간 복잡도를 사용한다.

### 수식

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N + Q)   |  O(N + Q)   |

나무 A와 연못 B의 길이의 합은 다음과 같이 구한다.

- |Ax - Bx|^2 + |Ay - By|^2

이는 x좌표와 y좌표에 대해 분리해 생각할 수 있음을 의미한다.

하나의 연못에 대해 다른 모든 나무들까지의 거리의 합을 다음과 같이 나타낼 수 있다.

```plain_text
# p : 현재 연못의 좌표
# a1, a2 ... : 각 나무들의 좌표
|p - a1|^2 + |p - a2|^2 + ...
```

이를 풀면 다음과 같다.

```plain_text
p^2 - 2 * p(a1) + a1^2 + p^2 - 2 * p(a2) + a2^2 + ...

= sum(p^2) - 2 * p * (a1 + a2 ...) + (a1^2 + a2^2 ...)
```

즉 한 좌표를 고정된 상수라고 생각할 경우 나머지 변수들의 합, 제곱합을 이용해 유클리드 거리를 바로 구할 수 있다.

이를 y, x좌표에 대해 두번 정답에 더한다.

이 때 overflow와 나머지 연산을 주의한다.

이를 구현하면 다음과 같다.

```cpp
int solution(int n, int q, vector<Axis> &trees, vector<Axis> &waters) {
  long long answer = 0;

  unordered_map<int, int> waterXs, waterYs;
  long long treeXSum = 0, treeYSum = 0;
  long long treeXSquareSum = 0, treeYSquareSum = 0;

  for (Axis &tree : trees) {
    treeXSum += tree.x;
    treeXSum %= MOD;
    treeYSum += tree.y;
    treeYSum %= MOD;

    treeXSquareSum += ((long long)tree.x * tree.x);
    treeXSquareSum %= MOD;
    treeYSquareSum += ((long long)tree.y * tree.y);
    treeYSquareSum %= MOD;
  }

  for (Axis &water : waters) {
    waterXs[water.x]++;
    waterYs[water.y]++;
  }

  // calculate y
  for (auto &it1 : waterYs) {
    long long wy = it1.first;
    int count = it1.second;

    long long wYSquare = wy * wy;
    wYSquare %= MOD;

    long long diffSum = (wYSquare * n) + treeYSquareSum - 2 * wy * treeYSum;
    diffSum %= MOD;
    if (diffSum < 0) diffSum += MOD;
    diffSum *= count;
    diffSum %= MOD;

    answer += diffSum;
    answer %= MOD;
  }

  // calculate x
  for (auto &it1 : waterXs) {
    long long wx = it1.first;
    int count = it1.second;

    long long wXSquare = wx * wx;
    wXSquare %= MOD;

    long long diffSum = (wXSquare * n) + treeXSquareSum - 2 * wx * treeXSum;
    diffSum %= MOD;
    if (diffSum < 0) diffSum += MOD;
    diffSum *= count;
    diffSum %= MOD;

    answer += diffSum;
    answer %= MOD;
  }

  return answer % MOD;
}
```

## 고생한 점
