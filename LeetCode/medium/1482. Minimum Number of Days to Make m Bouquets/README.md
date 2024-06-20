# 1482. Minimum Number of Days to Make m Bouquets

[링크](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 배열 bloomDay의 크기를 N, 최대값을 M이라 하자.

현재 day에 대해 가능한지 판별하기 위해 bloomDay를 순회하며 가능한지 판별해야 한다. 이에 O(N)의 시간 복잡도가 필요하다.

이분 탐색으로 day를 탐색할 수 있다. 이 경우 O(N \* log_2(M))의 시간 복잡도가 필요하다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도가 필요하다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     147      | O(N \* log_2(M)) |    O(1)     |

현재 지난일 d에 대해 만들 수 있는 부케의 수를 다음과 같이 구할 수 있다.

- bloomDay를 왼쪽부터 순회한다.
- 현재 day가 d이하인 경우 count를 증가시킨다.
- d초과인 경우 count를 0으로 초기화한다.
- count가 k인 경우 부케를 만들고 0으로 초기화시킨다.

여기서 d를 이분 탐색으로 찾을 수 있다.

이를 구현하면 다음과 같다.

```cpp
int getCount(vector<int>& bloomDay, int mid, int k) {
  int ret = 0;
  int count = 0;
  for (int& day : bloomDay) {
    if (day <= mid) {
      count++;
    } else {
      count = 0;
    }

    if (count == k) {
      ret++;
      count = 0;
    }
  }
  return ret;
}

int minDays(vector<int>& bloomDay, int m, int k) {
  int left = 0, right = *max_element(bloomDay.begin(), bloomDay.end()) + 1;

  int answer = -1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (getCount(bloomDay, mid, k) >= m) {
      answer = mid;
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return answer;
}
```

## 고생한 점
