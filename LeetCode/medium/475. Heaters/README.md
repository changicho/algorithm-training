# 475. Heaters

[링크](https://leetcode.com/problems/heaters/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

houses의 크기를 N, heaters의 크기를 M, houses와 heaters의 값 중 가장 큰 차이를 K라 하자.

특정 radius일 때 모든 집을 따뜻하게 할 수 있는지 투 포인터를 이용할 경우 O(N + M)의 시간 복잡도를 사용할 수 있다.

이를 K에 대해서 이분 탐색으로 정답을 구할 경우 O((N + M)log_2(K))의 시간 복잡도를 사용한다.

### 공간 복잡도

이분 탐색을 사용하는 데 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      83      | O((N + M)log_2(M)) |    O(1)     |

heaters를 정렬한다.

이후 houses를 순회하며 houses의 가장 왼쪽에서 가장 가까운 heater, 오른쪽에서 가장 가까운 heater를 구하고 그 거리의 차이를 구한다.

두 차이값중 작은값을 정답의 후보군으로 두고 정답의 후보군 중 가장 큰 값을 고른다.

```cpp
int findRadius(vector<int>& houses, vector<int>& heaters) {
  sort(heaters.begin(), heaters.end());

  int answer = 0;
  for (int& house : houses) {
    // nearest right one
    auto right = lower_bound(heaters.begin(), heaters.end(), house);
    int curRadius = INT_MAX;

    if (right != heaters.end()) {
      curRadius = *right - house;
    }
    if (right != heaters.begin()) {
      // nearest left one
      auto left = prev(right);
      curRadius = min(curRadius, house - *left);
    }
    answer = max(answer, curRadius);
  }
  return answer;
}
```

### 이분 탐색

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|     104      | O((N + M)log_2(K)) |    O(1)     |

특정 radius에 대해서 정답 이상의 값은 모든 집을 따뜻하게 하는것이 가능하고, 정답 미만의 값은 모든 집을 따뜻하게 하는게 불가능하다.

따라서 이는 linear하므로 이 값에 대해 이분 탐색을 사용할 수 있다.

특정 radius에 대해서 houses와 heaters에 대해 모두 따뜻하게 가능한지는 투 포인터를 이용해 구현 할 수 있다.

이 경우 houses와 heaters의 index를 순회하며 radius에 대해 범위에 포함 되는지를 검사한다.

이를 위해서 두 배열은 모두 정렬되어있어야 하므로 정렬에 O(N \* log_2(N)), O(M \* log_2(M))의 시간 복잡도를 각각 사용한다.

이를 구현하면 다음과 같다.

```cpp
bool isPossible(vector<int>& houses, vector<int>& heaters, int radius) {
  int n = houses.size(), m = heaters.size();
  int i = 0, j = 0;
  // use two pointer
  while (i < n && j < m) {
    int left = heaters[j] - radius, right = heaters[j] + radius;

    if (left <= houses[i] && houses[i] <= right) {
      i++;
    } else {
      j++;
    }
  }

  if (j == m) return false;
  return true;
}

int findRadius(vector<int>& houses, vector<int>& heaters) {
  sort(houses.begin(), houses.end());
  sort(heaters.begin(), heaters.end());

  int answer = max(houses.back(), heaters.back()) + 1;
  int left = 0, right = max(houses.back(), heaters.back()) + 1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (isPossible(houses, heaters, mid)) {
      // pick left part
      answer = mid;
      right = mid;
    } else {
      // pick right part
      left = mid + 1;
    }
  }

  return answer;
}
```

### 정렬 & 투 포인터

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|      92      | O(N \* log_2(N) + M \* log_2(M)) |    O(N)     |

houses와 heaters를 모두 정렬한다.

이후 i번째 house와 가장 가까운 히터의 거리차이를 저장할 크기 N의 배열을 선언한다.

이를 투 포인터를 이용해 왼쪽에서 봤을 때, 오른쪽에서 봤을 때에 대한 값을 갱신한다.

이를 이용해 각 house에 대한 다른 히터까지의 최소 거리를 각각 구할 수 있고 이 중에 가장 큰 값이 정답이다.

```cpp
int findRadius(vector<int>& houses, vector<int>& heaters) {
  int n = houses.size(), m = heaters.size();

  sort(houses.begin(), houses.end());
  sort(heaters.begin(), heaters.end());
  vector<int> res(n, INT_MAX);

  // distance to nearest RHS heater
  for (int i = 0, j = 0; i < n && j < m;) {
    if (houses[i] <= heaters[j]) {
      res[i] = heaters[j] - houses[i];
      i++;
    } else {
      j++;
    }
  }

  // distance to nearest LHS heater
  for (int i = n - 1, j = m - 1; i >= 0 && j >= 0;) {
    if (houses[i] >= heaters[j]) {
      res[i] = min(res[i], houses[i] - heaters[j]);
      i--;
    } else {
      j--;
    }
  }

  return *max_element(res.begin(), res.end());
}
```

## 고생한 점
