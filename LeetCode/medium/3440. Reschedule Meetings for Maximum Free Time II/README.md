# 3440. Reschedule Meetings for Maximum Free Time II

[링크](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

이벤트들의 갯수를 N이라 하자.

순회를 사용해 특정 이벤트를 이전 이벤트들 사이 구간에 이동시킬 수 있는지 확인할 수 있다.

이에 O(N)의 시간 복잡도를 사용한다.

이후 이벤트 사이 구간을 순회하며 최대 구간을 구할 수 있다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

특정 이벤트들이 이동 가능한지 여부를 저장하기 위해 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(N)     |

만약 현재 이벤트를 다른 이벤트들 사이 구간에 이동시킬 수 있는 경우, 현재 이벤트를 제거한 뒤 사이 구간의 크기를 구할 수 있다.

따라서 이벤트들을 순회하며 현재 이벤트를 제거할 수 있는지 확인한다.

만약 제거 불가능한 경우 현재 이벤트 양 옆 이벤트 사이 크기와 현재 이벤트를 연이어 붙여 구간 크기를 구한다.

이후 특정 이벤트를 제거했을 때, 혹은 제거하지 않았을 때의 최대 구간 크기를 구한다.

```cpp
int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
  int size = startTime.size();
  int answer = 0;
  vector<bool> canErase(size, false);

  for (int i = 0, maxHole = 0; i < size; i++) {
    if (endTime[i] - startTime[i] <= maxHole) {
      canErase[i] = true;
    }

    int before = (i - 1 < 0) ? 0 : endTime[i - 1];
    maxHole = max(maxHole, startTime[i] - before);
  }

  for (int i = size - 1, maxHole = 0; i >= 0; i--) {
    if (endTime[i] - startTime[i] <= maxHole) {
      canErase[i] = true;
    }

    int next = (i + 1 >= size) ? eventTime : startTime[i + 1];
    maxHole = max(maxHole, next - endTime[i]);
  }

  for (int i = 0; i < size; i++) {
    int before = (i - 1 < 0) ? 0 : endTime[i - 1];
    int next = (i + 1 >= size) ? eventTime : startTime[i + 1];

    int range = next - before;
    int diff = (endTime[i] - startTime[i]);

    if (canErase[i]) {
      answer = max(answer, range);
    } else {
      answer = max(answer, range - diff);
    }
  }
  return answer;
}
```

## 고생한 점
