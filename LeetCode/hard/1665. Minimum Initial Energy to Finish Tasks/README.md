# 1665. Minimum Initial Energy to Finish Tasks

[링크](https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 tasks의 크기를 N이라 하자.

탐욕 알고리즘을 위해 정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘 (정렬)

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      88      | O(N \* log_2(N)) |    O(N)     |

현재 task를 수행하기 위한 최소값과 실행 비용이 존재한다.

최소값 - 실행 비용 이 작은 순으로 정렬한다.

이후 정렬된 task를 순회하며 필요한 비용을 갱신한다.

```cpp
int minimumEffort(vector<vector<int>>& tasks) {
  sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
    return a[1] - a[0] < b[1] - b[0];
  });

  int answer = 0;
  for (vector<int>& task : tasks) {
    answer = max(answer + task[0], task[1]);
  }
  return answer;
}
```

## 고생한 점
