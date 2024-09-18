# 539. Minimum Time Difference

[링크](https://leetcode.com/problems/minimum-time-difference/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 timePoints의 길이를 N이라 하자.

각 시간문자열을 분으로 변경한 뒤 정렬 후 비교를 진행하면 된다.

이 때 시간 복잡도는 O(N \* log_2(N)) 이다.

분으로 변환한 값의 범위가 크지 않으므로 카운팅 정렬을 수행할 수 있다.

이에 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

각 문자열을 변환한 공간에 O(N)의 공간 복잡도를 사용한다.

정렬에 O(N)의 공간 복잡도를 사용한다.

카운팅 정렬에 O(1)의 공간복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      11      | O(N \* log_2(N)) |    O(N)     |

각 수를 변환 후 정렬한 뒤 직전값과 비교를 수행한다.

이 때 시간은 순환하므로 첫번째 값과 마지막 값의 차이를 구해야 한다.

```cpp
int convert(string &time) {
  int hour = (time[0] - '0') * 10 + time[1] - '0';
  int minute = (time[3] - '0') * 10 + time[4] - '0';

  return hour * 60 + minute;
}

int findMinDifference(vector<string> &timePoints) {
  int size = timePoints.size();
  vector<int> nums;
  for (string &t : timePoints) {
    nums.push_back(convert(t));
  }

  sort(nums.begin(), nums.end());
  nums.push_back(nums[0] + 24 * 60);
  int answer = nums[1] - nums[0];
  for (int i = 0; i < size; i++) {
    int diff = nums[i + 1] - nums[i];

    answer = min(answer, diff);
  }
  return answer;
}
```

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(1)     |

각 분의 종류는 24 \* 60 가지 경우가 존재한다.

각 문자열을 변환하고 각 분에 해당하는 index에 카운팅을 수행한다.

이 때 같은 값이 중복된 경우 최소 차이는 0이므로 0을 반환한다.

이후 분에 대해 순회하며 직전에 나타난 값과 현재 값의 차이를 구한다.

이 때 마지막 값과 첫번째 값의 차이도 구한다.

```cpp
int convert(string &time) {
  int hour = (time[0] - '0') * 10 + time[1] - '0';
  int minute = (time[3] - '0') * 10 + time[4] - '0';

  return hour * 60 + minute;
}

int findMinDifference(vector<string> &timePoints) {
  int size = timePoints.size();

  int counts[24 * 60] = {
      0,
  };

  int maximum = INT_MIN;
  for (string &t : timePoints) {
    int time = convert(t);

    counts[time]++;
    maximum = max(maximum, time);
    if (counts[time] >= 2) return 0;
  }

  int answer = INT_MAX;
  int before = maximum - 24 * 60;
  for (int time = 0; time < 24 * 60; time++) {
    if (counts[time] == 0) continue;

    int diff = time - before;

    answer = min(diff, answer);
    before = time;
  }

  return answer;
}
```

## 고생한 점
