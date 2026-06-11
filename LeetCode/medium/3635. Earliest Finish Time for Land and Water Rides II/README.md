# 3635. Earliest Finish Time for Land and Water Rides II

[링크](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

각 배열중 최소값을 찾고 다른 배열을 순회할 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |  O(N + M)   |    O(1)     |

`3633. Earliest Finish Time for Land and Water Rides I` 에서 배열의 크기만 변경된 문제

water, land 중 각 하나를 탔을 때 가장 빨리 끝나는 시간을 찾는다.

이 중 하나를 먼저 탈 때 제일 먼저 끝나는 시간을 찾고, 이후 다른 배열에서 순회한다.

```cpp
int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
  int lSize = landStartTime.size();
  int wSize = waterStartTime.size();

  function<int(int, vector<int>&, vector<int>&)> calc =
    [&](int start, vector<int>& starts, vector<int>& durations) {
      int ret = INT_MAX;

      int size = starts.size();

      for (int i = 0; i < size; i++) {
        ret = min(ret, max(start, starts[i]) + durations[i]);
      }
      return ret;
    };

  int answer = INT_MAX;
  int landMin = INT_MAX;
  for (int i = 0; i < lSize; i++) {
    int cur = landStartTime[i] + landDuration[i];
    landMin = min(cur, landMin);
  }
  answer = min(answer, calc(landMin, waterStartTime, waterDuration));

  int waterMin = INT_MAX;
  for (int i = 0; i < wSize; i++) {
    int cur = waterStartTime[i] + waterDuration[i];

    waterMin = min(cur, waterMin);
  }

  answer = min(answer, calc(waterMin, landStartTime, landDuration));

  return answer;
}
```

## 고생한 점
