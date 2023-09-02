# 1326. Minimum Number of Taps to Open to Water a Garden

[링크](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

주어진 ranges의 크기, 물을 뿌릴 수 있는 공간의 길이를 N, 각 range의 범위를 M이라 하자.

각 범위에 대해 정렬 후 각 진행상황마다 제일 유리한 범위를 선택할 수 있다.

이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 순회를 이용해 최소한의 횟수를 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

동적 계획법을 이용해 각 index와 range에 대해 최소한의 횟수를 구할 수 있다.

이 경우 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 데이터를 새로운 범위 데이터로 생성하는 데 O(N)의 공간 복잡도를 사용한다.

### 그디디 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      15      | O(N \* log_2(N)) |    O(N)     |

현재까지 채운 범위의 가장 오른쪽 값을 R이라 하자.

만약 좌표들을 시작점에 대해서 정렬 할 경우, 특정 index 이후의 좌표들은 R을 초과하는 시작점을 가진 범위들이다.

따라서 현재 R까지 탐색할 수 있는 좌표들을 탐색하며 가장 멀리까지 뻗어나가는 범위를 찾고 R을 갱신한다.

즉 각 상황에서 가장 멀리까지 탐색 가능한 좌표만을 선택한다.

이를 위해 정렬 후 순회를 이용한다.

이 때 이전에 방문한 index들은 다시 방문하지 않아도 된다.

```cpp
int minTaps(int n, vector<int> &ranges) {
  int size = ranges.size();

  vector<pair<int, int>> arr;
  for (int i = 0; i < size; i++) {
    arr.push_back({i - ranges[i], i + ranges[i]});
  }

  sort(arr.begin(), arr.end());

  int right = 0;
  int index = 0;

  int answer = 0;
  while (index < size && right < n) {
    int next = -1;
    while (index < size && arr[index].first <= right) {
      if (right <= arr[index].second) {
        next = max(next, arr[index].second);
      }
      index++;
    }

    if (next == -1) return -1;
    answer++;
    right = next;
  }

  if (answer == 0) return -1;
  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      34      |  O(N \* M)  |    O(N)     |

```cpp
int minTaps(int n, vector<int>& ranges) {
  const int MAX = 1e9;
  vector<int> dp(n + 1, MAX);

  dp[0] = 0;

  for (int i = 0; i <= n; i++) {
    int left = max(0, i - ranges[i]);
    int right = min(n, i + ranges[i]);

    for (int j = left; j <= right; j++) {
      dp[right] = min(dp[right], dp[j] + 1);
    }
  }

  if (dp[n] == MAX) return -1;

  return dp[n];
}
```

## 고생한 점
