# 1288. Remove Covered Intervals

[링크](https://leetcode.com/problems/remove-covered-intervals/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

intervals의 크기를 N이라 하자.

모든 interval들끼리 겹치는지 판단하는데 모든 경우를 판단할 경우 O(N^2)의 시간 복잡도를 사용한다.

정렬을 이용해 겹칠 수 있는 후보군들끼리만 탐색할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

브루트 포스, 정렬 두 방법 모두 별도의 공간 복잡도를 사용하지 않는다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |   O(N^2)    |    O(1)     |

한 interval을 다른 모든 interval과 비교하며 겹치는지 판단한다.

만약 겹칠경우 정답에서 제거한다. (감소)

```cpp
bool checkCovered(vector<int> &a, vector<int> &b) {
  return b[0] <= a[0] && a[1] <= b[1];
}

int removeCoveredIntervals(vector<vector<int>> &intervals) {
  int size = intervals.size();
  int answer = size;

  for (int from = 0; from < size; from++) {
    bool isCovered = false;

    for (int to = 0; to < size; to++) {
      if (from == to) continue;

      if (checkCovered(intervals[from], intervals[to])) {
        isCovered = true;
        break;
      }
    }

    if (isCovered) answer--;
  }

  return answer;
}
```

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      32      | O(N \* log_2(N)) |    O(1)     |

모든 interval들을 시작점에 대해서 정렬할 수 있다.

이 경우 같은 시간에 시작하는 interval끼리는 다음만 비교하면 된다.

- 시작시간이 같은 두 interval에서 끝나는 시간이 다른 경우 겹친다.

가장 많이 다른 interval들을 감쌀 수 있는 interval을 우선순위를 높게 설정하고 이후에 있는 interval들을 순회하며 겹쳐지는지 확인한다.

만약 겹쳐지는것이 없는 경우 비교할 interval을 갱신한다.

여기서 우선순위가 높은 순서는 다음과 같다.

- 시작시간이 빠른 순
- 끝 시간이 늦는 순

이는 한 interval이 다른 interval을 감싸기 위해선 범위가 넓고 시작시간이 빨라야 하기 때문이다.

이를 구현하면 다음과 같다.

```cpp
int removeCoveredIntervals(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(),
        [](vector<int> &a, vector<int> &b) {
          return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        });

  int count = 0;
  int prevEnd = 0;
  for (vector<int> &interval : intervals) {
    int end = interval[1];

    if (prevEnd < end) {
      count++;
      prevEnd = end;
    }
  }
  return count;
}
```

## 고생한 점
