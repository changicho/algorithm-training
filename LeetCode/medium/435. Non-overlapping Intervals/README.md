# 435. Non-overlapping Intervals

[링크](435. Non-overlapping Intervals)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

intervals의 크기를 N이라 하자.

모든 경우를 다 비교해 볼 경우 경우의 수는 총 2^N개이며, 각 경우마다 겹치는지 아닌지 판단하는데 최소 O(N)의 시간 복잡도를 사용한다.

이는 제한시간 내에 불가능하다.

정렬을 이용해 intervals 중 겹치는 경우를 제외할 수 있다.

이 때 끝나는 점에 대해 오름차순으로 정렬해 현재 비교할 때 이미 진전값들은 모두 끝나있음을 보장한다.

이 정렬에 O(N * log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 추가 공간 복잡도를 사용할 수도 있다.

직전에 끝난 시간만을 기록해 비교할 경우 O(1)의 공간 복잡도를 사용한다.

삭제되지 않은 intervals들을 배열에 담아 비교할 경우 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 끝점 비교

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     648      | O(N * log_2(N)) |    O(N)     |

우선 intervals를 끝점에 대해 정렬한다.

이후 intervals의 각 값들을 순회하며 현재 값이 이전에 방문한 값과 겹치는 경우 현재 값을 삭제한다.

이를 구현하면 다음과 같다.

```cpp
int eraseOverlapIntervals(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
  });

  int count = 0;
  int lastEnd = INT_MIN;
  for (vector<int> &i : intervals) {
    if (i[0] < lastEnd) {
      count++;
      continue;
    }
    lastEnd = i[1];
  }

  return count;
}
```

## 고생한 점
