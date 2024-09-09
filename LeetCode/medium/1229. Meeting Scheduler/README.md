# 1229. Meeting Scheduler

[링크](https://leetcode.com/problems/meeting-scheduler/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열 slots1, slots2의 길이는 각각 N, M이라 하자.

각 배열을 시간순으로 정렬하는데 O(N \* log_2(N)), O(M \* log_2(M))의 시간 복잡도가 필요하다.

이후 투포인터를 사용해 intersection을 찾는데 O(N + M)의 시간 복잡도가 필요하다.

따라서 시간 복잡도는 O(N \* log_2(N) + M \* log_2(M)) 이다.

### 공간 복잡도

정렬에 O(N + M)의 공간 복잡도가 필요하다.

### 정렬 & 투 포인터

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|     108      | O(N \* log_2(N) + M \* log_2(M)) |  O(N + M)   |

slots1, slots2를 시간순으로 정렬한다.

이후 투 포인터를 이용해 겹치는 부분을 찾고 정답을 갱신한다.

```cpp
int getIntersect(vector<int>& a, vector<int>& b) {
  if (a[1] < b[0] || b[1] < a[0]) return 0;

  return min(a[1], b[1]) - max(a[0], b[0]);
}

vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
  int size1 = slots1.size(), size2 = slots2.size();
  int i1 = 0, i2 = 0;

  sort(slots1.begin(), slots1.end());
  sort(slots2.begin(), slots2.end());

  while (i1 < size1 && i2 < size2) {
    int intersect = getIntersect(slots1[i1], slots2[i2]);

    if (intersect >= duration) {
      int left = max(slots1[i1][0], slots2[i2][0]);
      return {left, left + duration};
      break;
    }

    if (slots1[i1][1] < slots2[i2][1]) {
      i1++;
    } else if (slots2[i2][1] < slots1[i1][1]) {
      i2++;
    } else {
      i1++;
      i2++;
    }
  }

  return {};
}
```

## 고생한 점
