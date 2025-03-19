# [PCCP 기출문제] 2번 / 퍼즐 게임 챌린지

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/340212)

| 난이도 |
| :----: |
|  LV2   |

## 설계

### 시간 복잡도

배열 diffs의 크기를 N, 가능한 레벨의 최대값을 M이라 하자.

레벨에 대해서 이분 탐색을 수행할 수 있다. 이 경우 O(N \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

|   시간 복잡도    | 공간 복잡도 |
| :--------------: | :---------: |
| O(N \* log_2(M)) |    O(1)     |

각 레벨에 대해서 제한시간 내에 수행이 가능한지 순회를 이용해 판단할 수 있다.

레벨에 대해 이분 탐색을 사용해 가능한 레벨의 최소값을 구한다.

```cpp
long long check(vector<int> &diffs, vector<int> &times, int level) {
  long long ret = 0;

  int timePrev = 0;
  int size = diffs.size();
  for (int i = 0; i < size; i++) {
    if (diffs[i] <= level) {
      ret += times[i];
    } else {
      long long trial = diffs[i] - level;
      long long cost = trial * (timePrev + times[i]) + times[i];

      ret += cost;
    }
    timePrev = times[i];
  }
  return ret;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
  long long left = 1, right = INT_MAX;

  int answer = 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    long long curCost = check(diffs, times, mid);

    if (curCost <= limit) {
      // pick left
      right = mid;
      answer = mid;
    } else {
      // pick right
      left = mid + 1;
    }
  }

  return answer;
}
```

## 고생한 점
