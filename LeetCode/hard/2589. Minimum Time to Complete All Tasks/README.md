# 2589. Minimum Time to Complete All Tasks

[링크](https://leetcode.com/problems/minimum-time-to-complete-all-tasks/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

tasks의 크기를 N이라 하자. O(N <= 2,000)

task들의 시간의 범위는 1 ~ 2,000 이다.

모든 시간을 선택하는 경우에 대해 탐색할 경우 O(2^2000)의 시간 복잡도를 사용한다.

이는 매우 크므로 불가능하다.

각 task에서 시간을 선택할 때 다음 task들과 겹칠 가능성이 가장 높은 값들을 선택해야한다.

이를 위해 정렬을 수행할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 시간에 대해 사용했는지 여부를 저장할 공간이 필요하다.

이에 O(2,000)의 공간 복잡도를 사용한다.

### 그리디 & 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     138      | O(N \* log_2(N)) |  O(2,000)   |

각 task별로 현재 시간을 선택할 때, 이후 task들과 최대한 겹치는 시간을 골라야 한다.

이를 위해 각 task별로 시작 시간을 기준으로 정렬을 수행한다.

이 때 끝나는 시간에 대해 오름차순으로 정렬하고, 각 task에 대해 가장 오른쪽부터 가능한 시간을 선택할 경우 최대한 겹치는 시간을 선택할 수 있다.

이를 위해 각 task별로 끝나는 시간을 기준으로 정렬을 수행한후, 각 task에 대해 가장 오른쪽부터 가능한 시간을 선택한다.

이후 선택한 시간의 종류를 센다.

```cpp
int findMinimumTime(vector<vector<int>>& tasks) {
  bool isTimeSpent[2001] = {
      false,
  };

  // sort endtime ascending
  sort(tasks.begin(), tasks.end(),
        [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

  for (vector<int>& task : tasks) {
    int usedTime = 0;
    for (int t = task[0]; t <= task[1]; t++) {
      if (isTimeSpent[t]) usedTime++;
    }

    for (int t = task[1]; usedTime < task[2] && t >= task[0]; t--) {
      if (isTimeSpent[t] == false) {
        usedTime++;
        isTimeSpent[t] = true;
      }
    }
  }

  int answer = 0;
  for (int t = 0; t <= 2000; t++) {
    if (isTimeSpent[t]) answer++;
  }
  return answer;
}
```

## 고생한 점
