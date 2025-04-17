# 2594. Minimum Time to Repair Cars

[링크](https://leetcode.com/problems/minimum-time-to-repair-cars/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 ranks의 크기를 N, 가능한 시간의 최대 값을 M이라 하자.

가능한 시간 값에 대해 이분 탐색을 수행할 경우 시간 복잡도는 O(N \* log_2(M)) 이다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도가 필요하다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      51      | O(N \* log_2(M)) |    O(1)     |

특정 시간에 대해서 수리가 가능한지 판단하는데 O(N)의 시간 복잡도를 사용한다.

이후 가능한 시간들에 대해서 이분 탐색을 사용해 사용 가능한지, 불가능한지 판단할 수 있다.

이 때 가능한 시간의 최대값은 다음과 같다.

- cars^2 \* ranks의 최대값
- 가장 rank가 높은 사람이 모든 차를 수리하는 경우

```cpp
bool check(long long time, vector<int> &ranks, int cars) {
  long long count = 0;

  for (int &r : ranks) {
    long long d = sqrt(time / r);
    count += d;
  }

  return count >= cars;
}

long long repairCars(vector<int> &ranks, int cars) {
  long long answer = 0;

  long long left = 1, right = 1e14 + 1;

  while (left < right) {
    long long mid = left + (right - left) / 2;

    if (check(mid, ranks, cars)) {
      // pick left part
      right = mid;
    } else {
      // pick right part
      left = mid + 1;
    }
  }
  return left;
}
```

## 고생한 점
