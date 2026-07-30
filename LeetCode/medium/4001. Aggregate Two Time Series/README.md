# 4001. Aggregate Two Time Series

[링크](https://leetcode.com/problems/aggregate-two-time-series/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열의 크기를 N, M이라 하자.

투 포인터를 사용할 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N + M)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      83      |  O(N + M)   |  O(N + M)   |

각 배열은 시간순으로 오름차순 정렬되어있다.

이를 낮은 시간대로 각 배열을 순회하며 현재 정답을 추가한다.

```cpp
vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
  int size1 = series1.size(), size2 = series2.size();
  vector<vector<int>> answer;

  int i1 = 0, i2 = 0;

  while (i1 < size1 && i2 < size2) {
    int time = min(series1[i1][0], series2[i2][0]);
    int val1 = series1[i1][1];
    int val2 = series2[i2][1];

    int val = val1 + val2;

    answer.push_back({time, val});

    if (series1[i1][0] == time) {
      i1++;
    }
    if (series2[i2][0] == time) {
      i2++;
    }
  }

  while (i1 < size1) {
    answer.push_back(series1[i1]);
    i1++;
  }
  while (i2 < size2) {
    answer.push_back(series2[i2]);
    i2++;
  }

  return answer;
}
```

## 고생한 점
