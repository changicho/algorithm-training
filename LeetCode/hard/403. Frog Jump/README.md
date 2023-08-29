# 403. Frog Jump

[링크](https://leetcode.com/problems/frog-jump/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 stones의 길이를 N이라 하자.

각 stone마다 다음 stone으로 넘어가기 위해 건너뛸 수 있는 step들이 존재한다.

이전 stone들을 탐색하며 다음 stone에 도달할 수 있는 step들을 모두 저장 후, 다음 stone들을 탐색한다.

이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 stone마다 다음 stone으로 넘어가기 위해 건너뛸 수 있는 step들을 저장해야 한다.

이에 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     133      |   O(N^2)    |   O(N^2)    |

현재 stone을 방문했을 때 이전 stone들에서 step 값으로 도달한 경우들이 존재한다.

따라서 해당 step들을 미리 저장해 놨을 경우, 다음 stone들을 탐색하며 해당 step들을 이용해 다음 stone에 도달할 수 있는지 판단할 수 있다.

이 때 맨 처음은 무조건 step이 1로 다음 stone을 방문해야 함에 유의한다.

다음과 같은 dp식을 설정한다.

```cpp
unordered_set<int> dp[i]; // i번째 돌을 방문했을 때의 step들의 집합
```

이후 각 과정마다 step-1, step, step+1에 해당하는 값으로 다음 stone에 도달할 수 있는지 판단한다.

이 때 값에 대한 index를 빠르게 찾기 위해 hash map을 이용한다.

```cpp
bool canCross(vector<int>& stones) {
  int size = stones.size();
  vector<unordered_set<int>> dp(size);

  unordered_map<int, int> indexes;
  for (int i = 0; i < size; i++) {
    int cur = stones[i];
    indexes[cur] = i;
  }

  if (stones[1] - stones[0] == 1) {
    dp[1].insert(1);
  }
  for (int i = 1; i < size; i++) {
    int cur = stones[i];

    for (int step : dp[i]) {
      for (int diff = -1; diff <= 1; diff++) {
        int next = cur + step + diff;

        if (indexes.count(next) && i < indexes[next]) {
          int target = indexes[next];
          dp[target].insert(step + diff);
        }
      }
    }
  }

  return dp.back().size() > 0;
}
```

## 고생한 점
