# 837. New 21 Game

[링크](https://leetcode.com/problems/new-21-game/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

각 수에 대해 확률을 구해야 한다. 이 때 각 수에 해당하는 확률을 동적 계획법과 슬라이딩 윈도우를 이용해 구할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

각 수에 대한 확률을 저장해야 하므로 공간 복잡도는 O(N)이다.

### 동적 계획법 & 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

현재 index를 i라 하자.

i까지 도달하는 경우의 수는 다음과 같다.

- i-1번째에서 도달하는 경우
- i-2번째에서 도달하는 경우
- ...
- i-(maxPts)번째 에서 도달하는 경우

따라서 각 index마다 이전 값들 중 영향을 받는 범위의 확률들을 더해줄 경우 현재 index까지 도달하는 확률을 구할 수 있다.

맨 처음 점수는 0 이므로 0번째 index의 확률은 1이다. (100%)

이후 index를 순회하며 dp를 갱신한다.

이후 점수가 K ~ N인 경우의 확률을 모두 더한 값이 정답이다.

이 때 k가 0인 경우는 증가가 불가능하기 때문에 시작 확률인 1만을 반환한다.

또한 N이 K + maxPts보다 큰 경우는 모든 경우가 N을 초과하지 않으므로 무조건 1이다.

```cpp
double new21Game(int n, int k, int maxPts) {
  if (k == 0 || n >= k + maxPts) return 1.0;

  vector<double> dp(n + 1);  // probability
  dp[0] = 1;

  double maxPtsSum = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = maxPtsSum / maxPts;
    if (i < k) {
      maxPtsSum += dp[i];
    }
    if (i >= maxPts) {
      maxPtsSum -= dp[i - maxPts];
    }
  }

  double sum = 0;
  for (int i = k; i <= n; i++) {
    sum += dp[i];
  }
  return sum;
}
```

## 고생한 점
