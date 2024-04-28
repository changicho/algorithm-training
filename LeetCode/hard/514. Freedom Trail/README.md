# 514. Freedom Trail

[링크](https://leetcode.com/problems/freedom-trail/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 두 문자열 ring, key의 길이를 각각 N, K라 하자.

각 문자열의 길이는 최대 100이다.

동적 계획법을 사용해 이전의 결과를 재사용할 수 있다. 이 경우 현재 index에서의 최소 이동 횟수를 구할 때 O(N^2)의 시간 복잡도가 필요하다.

이를 K번 반복하므로 시간 복잡도는 O(K \* N^2)이다.

### 공간 복잡도

각 index마다 현재 ring의 위치의 최소값을 구해야 하므로 O(K \* N)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      | O(K \* N^2) |  O(K \* N)  |

현재 i번째 key문자열을 채웠을 때 가능한 상태는 다음과 같다.

- ring에서 몇번째 index에 멈춰있는지

따라서 현재 i번째 key문자열을 채웠을 때 ring의 각 index에 대해 이전 key문자열을 채웠을 때의 최소 이동 횟수를 저장한다.

이 때 정방향 이동, 역방향 이동 횟수 모두 고려해야 한다.

다음과 같은 dp식을 생성한다.

```cpp
int key[i][ringI]; // i번째 key를 채웠을 때 ring의 ringI번째 index에 도달하는 최소 이동 횟수

int key[0][ringI] = min(step, reverseStep); // 초기값

key[i][ringI] = min(key[i][ringI], key[i-1][before] + step, key[i-1][before] + reverseStep);
```

여기서 정방향 이동과 역방향 이동은 아래와 같이 구할 수 있다.

- 이동하는 두 index에서 큰값을 bigger, 작은값을 smaller라고 할 때
- 정방향 : bigger - smaller + 1
- 역방향 : (smaller + size) - bigger + 1

이를 이용해 다음과 같이 구현할 수 있다.

```cpp
int findRotateSteps(string ring, string key) {
  int size = ring.size();
  int kSize = key.size();

  vector<vector<int>> dp(kSize, vector<int>(size, INT_MAX));
  for (int i = 0; i < size; i++) {
    if (ring[i] == key[0]) {
      int step = 1 + i;
      int rStep = 1 + (size - i);

      dp[0][i] = min({dp[0][i], step, rStep});
    }
  }

  for (int i = 1; i < kSize; i++) {
    for (int target = 0; target < size; target++) {
      if (ring[target] != key[i]) continue;

      for (int before = 0; before < size; before++) {
        int beforeStep = dp[i - 1][before];
        if (beforeStep == INT_MAX) continue;

        int bigger = max(before, target), smaller = min(before, target);
        int step = bigger - smaller + 1;
        int rStep = (smaller + size) - bigger + 1;

        dp[i][target] =
            min({dp[i][target], beforeStep + step, beforeStep + rStep});
      }
    }
  }

  int answer = *min_element(dp[kSize - 1].begin(), dp[kSize - 1].end());
  return answer;
}
```

## 고생한 점
