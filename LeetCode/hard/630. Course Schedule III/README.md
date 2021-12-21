# 630. Course Schedule III

[링크](https://leetcode.com/problems/course-schedule-iii/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

course의 갯수를 N, 마지막 lastDay를 D라고 하자.

동적 계획법을 이용할 경우 course의 index와, time에 대해 2가지 변수에 대해 dp를 수행해야한다.

이 경우 시간 복잡도는 최소 O(N \* D)가 된다.

그리디 알고리즘 + heap을 이용해 매번 선택한 course들의 duration 중 가장 긴 duration에 대해 교체하며 최적의 해를 찾아갈 수 있다.

이 때 최적의 순서로 course를 방문하기 위해 정렬을 사용하며 이때 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이 경우 course를 순회하는데 O(N), 순회하며 최적의 duration을 갈아 끼우는데 O(log_2(N))의 시간 복잡도가 소요되므로

최종 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N \* D)의 공간 복잡도를 사용한다.

heap을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 그리디 알고리즘 (heap)

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     164      | O(N \* log_2(N)) |    O(N)     |

탐욕 알고리즘을 이용해 course를 최적의 방법으로 방문한다.

이전에 선택한 course에 영향을 받는건 lastDay이므로 lastDay가 적은 순으로 정렬을 수행한다.

이후 i번째 course를 방문했을 때 다음 규칙이 성립한다.

- i-1 번째 까지 방문한 course에 대해서 현재 course.lastDay보다 이전에 끝나는것이 보장된다.
- 이전에 선택한 course들 중 어느 하나를 제거하더라도 나머지 course들을 고를 수 있다.

이때 2번째 조건이 만족하는 이유는 어떠한 순서대로라도 course를 골랐을 때 lastDay 이내에 끝난다면 선택할 수 있기 때문이다.

따라서 현재 course에 대해서 다음 3가지 경우가 존재한다.

- 현재 course를 선택해도 lastDay이내에 가능.
- 이전에 선택한 course중 가장 duration이 큰 것 대신 현재 course를 선택하면 가능.
- 불가능한 경우 : 건너뛴다.

이전에 선택한 course에 들어가는 비용을 각 3가지 경우마다 변경시켜가며 정답을 구한다.

```cpp
int scheduleCourse(vector<vector<int>> &courses) {
  int size = courses.size();

  priority_queue<int> pq;  // duration max heap
  sort(courses.begin(), courses.end(),
        [&](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

  int day = 0;
  for (vector<int> &cur : courses) {
    int duration = cur[0], lastDay = cur[1];

    if (lastDay >= day + duration) {
      day += duration;
      pq.push(duration);
      continue;
    }
    // find most big duration before we took
    // because if we erase that, we can take current
    if (!pq.empty() && pq.top() > duration) {
      day -= pq.top();
      pq.pop();
      day += duration;
      pq.push(duration);
    }
  }

  return pq.size();
}
```

## 고생한 점
