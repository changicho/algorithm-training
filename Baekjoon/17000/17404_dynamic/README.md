# 17404. RGB거리 2

[링크](https://www.acmicpc.net/problem/17404)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold IV |   54.203    |      0.5      |

## 설계

### 시간 복잡도

집의 개수 N은 최대 1,000까지이다.

### 공간 복잡도

집을 칠하는 비용은 최대 1,000 이하이다. 최악의 경우 답은 1,000^2 이므로 int형으로 충분하다.

### 동적 계획법

dp 배열을 다음과 같이 설정한다.

```cpp
dp[index][color] // index번째 집을 color로 설정했을 때의 최소값
```

일반식을 다음과 같이 설정한다.

```cpp
dp[index][color] = min(dp[index-1][color-1], dp[index-1][color+1]) + color[index][color]
```

여기서 맨 첫번쨰 집과 맨 마지막 집은 서로 색이 같으면 안된다.

따라서 맨 첫번째 집을 고정시키고 dp 배열을 갱신하며 R,G,B 3가지 경우에 대해서 모두 구해준다.

이 때 첫번쨰 집이 고정되었으므로 두번째 집부터는 첫번쨰 집에서 고정된 색으로 탐색을 진행해야 하므로 이를 주의한다.

```cpp
for (int start_color = 0; start_color < 3; start_color++) {
  for (int color = 0; color < 3; color++) {
    dp[0][color] = start_color == color ? colors[0][color] : 1000 * 1000 + 1;
  }

  for (int index = 1; index < N; index++) {
    for (int color = 0; color < 3; color++) {
      int left_cost = dp[index - 1][make_index(color, +1)];
      int right_cost = dp[index - 1][make_index(color, -1)];

      dp[index][color] = min(left_cost, right_cost) + colors[index][color];
    }
  }
  for (int color = 0; color < 3; color++) {
    if (color == start_color) continue;
    answer = min(answer, dp[N - 1][color]);
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
