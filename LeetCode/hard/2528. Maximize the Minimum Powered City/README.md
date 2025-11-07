# 2528. Maximize the Minimum Powered City

[링크](https://leetcode.com/problems/maximize-the-minimum-powered-city/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 stations의 크기를 N, 이들의 합을 M이라 하자.

가능한 minimum 값에 대해 이분 탐색을 수행할 수 있다. 해당 탐색에 O(log_2(M))의 시간 복잡도를 사용한다.

각 값에 대해 검증하는데 diff array를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(M))이다.

### 공간 복잡도

diff array에 O(N)의 공간 복잡도를 사용한다.

### diff array & 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      65      | O(N \* log_2(M)) |    O(N)     |

가능한 minimum값에 대해 이분 탐색을 수행하며, 각 값마다 순회를 이용해 가능한지 판단한다.

각 station마다 index에 영향을 주는 범위를 diff array로 표현한다.

이후 diff array를 이용해 현재 index의 영향을 주는 station의 합을 구할 수 있다.

이 때 부족한 경우 k를 이용해 추가하며, 이후의 값들에 최대한 영향을 주는 편이 좋으므로 현재 index에서 가능한 가장 오른쪽 index에 값을 더한다.

```cpp
bool check(long long val, vector<long long>& count, int k, int size, int r) {
  vector<long long> diff = count;
  long long sum = 0;
  long long remaining = k;

  for (int i = 0; i < size; i++) {
    sum += diff[i];
    if (sum < val) {
      long long add = val - sum;
      if (remaining < add) {
        return false;
      }
      remaining -= add;
      int end = min(size, i + 2 * r + 1);
      diff[end] -= add;
      sum += add;
    }
  }
  return true;
};

long long maxPower(vector<int>& stations, int r, int k) {
  int size = stations.size();

  vector<long long> count(size + 1);

  for (int i = 0; i < size; i++) {
    int left = max(0, i - r);
    int right = min(size, i + r + 1);
    count[left] += stations[i];
    count[right] -= stations[i];
  }

  long long left = *min_element(stations.begin(), stations.end());
  long long right = accumulate(stations.begin(), stations.end(), 0LL) + k + 1;
  long long answer = 0;

  while (left < right) {
    long long mid = left + (right - left) / 2;

    if (check(mid, count, k, size, r)) {
      answer = mid;
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
