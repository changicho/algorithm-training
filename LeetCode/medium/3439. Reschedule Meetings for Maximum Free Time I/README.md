# 3439. Reschedule Meetings for Maximum Free Time I

[링크](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

이벤트의 갯수를 N이라 하자.

prefix sum을 이용해 특정 구간의 이벤트들을 뭉쳐 남은 공간의 크기를 구할 수 있다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum을 저장하기 위해 O(N)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

최대 k개의 이벤트를 이동시킬 수 있다.

이 때 이벤트들의 순서는 유지되어야 하므로, 연이은 k개의 이벤트를 한곳에 묶고 나머지 남은 공간의 크기 중 최대값을 구하면 된다.

각 이벤트들의 실제 시간의 누적합을 미리 구한다.

현재 k개의 연이은 이벤트를 선택하고, 해당 이벤트들의 시간의 합을 prefix sum을 이용해 빠르게 구한다.

```cpp
int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
  int size = startTime.size();
  vector<int> prefixSum(size + 1);
  for (int i = 0; i < size; i++) {
    prefixSum[i + 1] = prefixSum[i] + endTime[i] - startTime[i];
  }

  int answer = 0;
  for (int i = k - 1; i < size; i++) {
    int right = i == size - 1 ? eventTime : startTime[i + 1];
    int left = i == k - 1 ? 0 : endTime[i - k];

    int scheduleSum = prefixSum[i + 1] - prefixSum[i - k + 1];

    answer = max(answer, right - left - scheduleSum);
  }
  return answer;
}
```

## 고생한 점
