# 45. Jump Game II

[링크](https://leetcode.com/problems/jump-game-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이는 최대 1,000 이다. 배열 안의 값은 최대 100,000 이다.

직접 모든 경우를 탐색하는 경우 N개의 위치를 방문하며 앞으로 진행 가능한 모든 경우에 대해 고려해야 한다.

(jump의 길이는 최대 10^5) 시간 복잡도는 대략 O(N^2)이 소요된다.

탐욕 알고리즘을 이용해 가능한 최소 경우만 고려할 경우 O(N)의 시간 복잡도만 소요된다.

동적 계획법을 이용하는 경우 직접 모든 경우를 탐색하는 경우와 동일하게 O(N^2)가 소요된다.

### 공간 복잡도

동적 계획법을 수행하는 경우 O(N)만큼의 추가 공간이 필요하다.

탐욕 알고리즘을 수행하는경우 O(1)만큼의 추가 공간이 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(N)     |

dp의 일반 식을 다음과 같이 설정한다.

```cpp
dp[index]; // index 위치 까지 필요한 최소한의 점프 횟수
```

dp의 식은 다음과 같다.

```cpp
// 직전 위치를 from 이라고 하자
dp[index] = min(dp[index], dp[from] + 1);
```

따라서 매 위치마다 다음 위치에 대한 dp값을 갱신해 문제를 풀이할 수 있다.

```cpp
int jump(vector<int>& nums) {
  int size = nums.size();
  vector<int> leastJumps(size, 10000);
  leastJumps[0] = 0;

  for (int from = 0; from < size; from++) {
    int reach = nums[from];

    int limit = min(size, from + reach + 1);
    for (int to = from + 1; to < limit; to++) {
      leastJumps[to] = min(leastJumps[to], leastJumps[from] + 1);
    }
  }

  return leastJumps.back();
}
```

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

두 위치를 알아야한다.

- 위치를 순회하며 현재까지 방문한 위치에서부터 가장 멀리까지 갈 수 있는 위치
- 방문하고자 하는 위치

위치를 순회하며 그 때마다 멀리까지 갈 수 있는 위치를 갱신한다.

방문하고자 하는 위치에 도달한 경우 count를 증가시키고 그 다음 위치로 갱신한다.

```cpp
int jump(vector<int>& nums) {
  int size = nums.size();
  int answer = 0;

  int position = 0;
  int next = 0;
  for (int i = 0; i < nums.size() - 1; i++) {
    next = max(next, i + nums[i]);

    if (position == i) {
      answer++;
      position = next;
    }
  }
  return answer;
}
```

## 고생한 점
