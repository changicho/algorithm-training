# 774. Minimize Max Distance to Gas Station

[링크](https://leetcode.com/problems/minimize-max-distance-to-gas-station/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 stations의 크기를 N, 입력받은 수를 K라 하자. (N <= 2000, K <= 10^6)

배열의 최대값과 오차 범위는 10^8, 10^-6이므로 이 범위를 M이라 하자. M은 10^14 이다.

힙을 사용할 경우 O(N + K \* log_2(N))의 시간 복잡도를 가진다. 이는 K가 크므로 시간 초과가 발생한다.

이분 탐색을 사용할 경우 O(N \* log_2(M))의 시간 복잡도를 가진다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      5       | O(N \* log_2(M)) |    O(1)     |

특정 거리 X에 대해서 최대 K개의 주유소를 더해서 모든 주유소 사이의 거리가 X 이하가 되는지 확인할 수 있다.

이에 O(N)의 시간 복잡도를 사용한다.

이후 X에 대해서 이분 탐색을 수행하며 최소의 X를 찾는다.

```cpp
bool check(vector<int>& stations, double limit, int k) {
  int size = stations.size();
  int used = 0;

  for (int i = 0; i < size - 1; i++) {
    int diff = stations[i + 1] - stations[i];

    used += (int)(diff / limit);
  }
  return used <= k;
}

double minmaxGasDist(vector<int>& stations, int k) {
  int size = stations.size();

  double left = 0, right = 1e8;
  double answer = right;
  while (right - left > 1e-6) {
    double mid = left + (right - left) / 2;

    if (check(stations, mid, k)) {
      right = mid;
      answer = mid;
    } else {
      left = mid;
    }
  }
  return answer;
}
```

## 고생한 점

힙을 이용한 풀이에서 최적화를 진행해도 O(N + K \* log_2(N))으로 시간 초과가 발생