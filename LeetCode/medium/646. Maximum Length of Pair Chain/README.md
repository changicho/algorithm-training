# 646. Maximum Length of Pair Chain

[링크](https://leetcode.com/problems/maximum-length-of-pair-chain/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이를 N이라 하자.

정렬을 이용해 끝점에 대해서 정렬을 수행한 후 그리디하게 정답을 구할 수 있다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(1) ~ O(N)의 공간 복잡도를 사용한다.

### 정렬 (스위핑)

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      43      | O(N \* log_2(N)) |    O(N)     |

현재 pair를 선택했을 때, 선택 가능한 다음 pair 중에서 가장 끝점이 작은 pair를 선택하는 쪽이 유리하다.

즉 각 경우마다 pair의 끝점이 작은 쪽을 선택해야 앞으로 더 많은 pair를 선택할 수 있는 가능성이 커진다.

이를 위해 끝점을 기준으로 정렬을 수행한다.

이후 직전에 선택한 pair의 끝점보다 현재 pair의 시작점이 큰 경우에만 정답을 갱신한다.

이 때 끝점이 작은 순으로 순회하므로 이전에 방문한 모든 pair는 현재 pair의 끝점보다 작은 경우이다.

```cpp
int findLongestChain(vector<vector<int>> &pairs) {
  int size = pairs.size();
  int answer = 1;

  sort(pairs.begin(), pairs.end(),
        [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

  int last = pairs[0][1];
  for (int i = 1; i < size; i++) {
    if (last < pairs[i][0]) {
      answer++;
      last = pairs[i][1];
    }
  }

  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     189      |   O(N^2)    |    O(N)     |

pairs를 오름차순으로 정렬한다.

dp배열로 각 pair를 선택했을 때 최대로 선택할 수 있는 pair의 개수를 저장한다.

맨 끝 pairs부터 역순으로 순회하며, 각 과정마다 현재 pair보다 오른쪽에 있는 값들을 탐색한다.

이 때 현재 pair의 끝점보다 다음 pair의 시작점이 큰 경우에만 dp를 갱신한다.

```cpp
int findLongestChain(vector<vector<int>> &pairs) {
  int size = pairs.size();
  sort(pairs.begin(), pairs.end());

  vector<int> dp(size, 1);

  int answer = 1;
  for (int i = size - 1; i >= 0; i--) {
    for (int j = i + 1; j < size; j++) {
      if (pairs[i][1] < pairs[j][0]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
    answer = max(answer, dp[i]);
  }
  return answer;
}
```

## 고생한 점
