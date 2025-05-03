# 2071. Maximum Number of Tasks You Can Assign

[링크](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 tasks의 크기를 N, workers의 크기를 M이라고 하자.

이분 탐색을 사용해 사용할 worker의 수를 탐색하며, 각 탐색마다 탐욕 알고리즘을 사용해 수행 가능한지 판별한다.

이 때 가장 유리한 worker를 탐욕 알고리즘으로 배정하기 위해 multiset을 사용한다.

이를 위해 정렬을 사용하며, 이 때 O(N \* log_2(N)) + O(M \* log_2(M))의 시간이 소요된다.

### 공간 복잡도

정렬에 O(N + M)의 공간이 소요된다.

### 이분 탐색 & 탐욕 알고리즘

| 내 코드 (ms) |             시간 복잡도             | 공간 복잡도 |
| :----------: | :---------------------------------: | :---------: |
|     635      | O(N \* log_2(N)) + O(M \* log_2(M)) |  O(N + M)   |

```cpp
bool check(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
  int used = 0;

  multiset<int> workerSet(workers.end() - mid, workers.end());

  for (int i = mid - 1; i >= 0; i--) {
    auto strongest = prev(workerSet.end());
    if (*strongest >= tasks[i]) {
      workerSet.erase(strongest);
      continue;
    }

    auto target = workerSet.lower_bound(tasks[i] - strength);
    used++;
    if (target == workerSet.end() || used > pills) {
      return false;
    }

    workerSet.erase(target);
  }
  return true;
}

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
  int taskSize = tasks.size();
  int workerSize = workers.size();
  sort(tasks.begin(), tasks.end());
  sort(workers.begin(), workers.end());

  int answer = 0;
  int left = 1, right = min(workerSize, taskSize);
  while (left <= right) {
    int mid = (left + right) / 2;

    if (check(mid, tasks, workers, pills, strength)) {
      answer = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return answer;
}
```

## 고생한 점
