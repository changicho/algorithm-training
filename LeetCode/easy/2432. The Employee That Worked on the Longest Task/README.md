# 2432. The Employee That Worked on the Longest Task

[링크](https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

logs의 크기를 N이라 하자.

N을 endTime에 대해 정렬 후 각 작업이 실제 수행된 시간을 계산한다.

이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용하며, 이후 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(1)의 공간 복잡도를 사용한다.

### 정렬 & one pass

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     202      | O(N \* log_2(N)) |    O(1)     |

각 log를 끝나는 시간에 대해 정렬한다.

이 경우 현재 log와 이전 log의 끝나는 시간의 차이만큼 실제 작업을 수행하는 시간을 구할 수 있다.

정렬 후 각 값을 순회하며 가장 작업을 많이 하는 작업의 id를 구한다.

```cpp
int hardestWorker(int n, vector<vector<int>> &logs) {
  int size = logs.size();
  int answer = logs.front()[0];
  int time = logs.front()[1];

  sort(logs.begin(), logs.end(),
        [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

  for (int i = 1; i < size; i++) {
    int curTime = logs[i][1] - logs[i - 1][1];

    if (curTime > time) {
      answer = logs[i][0];
      time = curTime;
    } else if (curTime == time) {
      answer = min(answer, logs[i][0]);
    }
  }
  return answer;
}
```

## 고생한 점
