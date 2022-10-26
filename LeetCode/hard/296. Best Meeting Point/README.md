# 296. Best Meeting Point

[링크](https://leetcode.com/problems/best-meeting-point/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

행의 갯수를 R, 열의 갯수를 C라 하자. (R, C 는 각각 최대 200)

각 좌표중 집인 좌표들을 찾고 이를 정렬 후 이분탐색을 이용해 distance를 빠르게 구할 수 있다.

이 때 y, x에 대해서 별개로 생각해 거리를 구한다.

이 경우 정렬에 O(R \* C \* log_2(R \* C))의 시간 복잡도를 사용한다.

이후 각 좌표 순회와 이분 탐색에 사용하는 시간 복잡도는 최대 O(R \* C \* log_2(R \* C)) 이다.

정렬된 좌표가 존재할 경우 중앙값(median)을 이용해 O(1)의 시간 복잡도로 최소 거리를 구할 수 있다.

이 때 카운팅 정렬을 수행하는 경우 O(R \* C)의 시간 복잡도를 사용한다.

이후 각 좌표와 중앙값의 차이를 이용해 정답을 구할 경우 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 점들을 저장하는 공간에 O(R \* C)의 공간 복잡도를 사용한다.

### suffix array & binary search

| 내 코드 (ms) |        시간 복잡도         | 공간 복잡도 |
| :----------: | :------------------------: | :---------: |
|      76      | O(R \* C \* log_2(R \* C)) |  O(R \* C)  |

맨하탄 거리를 구할 때 y, x에 대해서 각각 구할 수 있다.

따라서 각 x좌표들과 y좌표들에 대해서 별도로 구한다.

각 좌표들이 오름차순으로 정렬되어있다고 하자.

이 경우 현재 좌표를 A라고 할때, 각 좌표들은 다음과 같은 구성으로 되어있을것이다.

```cpp
[lessThanA, A, moreThanA]
```

즉 A에 대해 더 작은값과 큰 값으로 나눌 수 있다.

이 경우 A보다 작은 값들에 대한 거리는 다음과 같이 구할 수 있다.

- A \* sizeOf(lessThanA) - sum(lessThanA)

A보다 큰 값들에 대한 거리는 다음과 같이 구할 수 있다.

- sum(moreThanA) - A \* sizeOf(moreThanA)

각 값들의 합을 빠르게 구하기 위해 suffixSum을 이용할 수 있다.

또한 A보다 작은 값들의 갯수(index)의 경우 정렬되어 있는 경우 이분 탐색을 이용해 구할 수 있다.

이를 이용해 각 좌표마다 맨하탄 거리의 합을 구하고 최소가 되는 경우를 찾는다.

```cpp
int minTotalDistance(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid.front().size();

  vector<int> pointXs, pointYs;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) continue;

      pointXs.push_back(x);
      pointYs.push_back(y);
    }
  }

  sort(pointXs.begin(), pointXs.end());
  sort(pointYs.begin(), pointYs.end());

  vector<int> suffixX(pointXs.size() + 1), suffixY(pointYs.size() + 1);
  for (int i = 0; i < pointXs.size(); i++) {
    suffixX[i + 1] = suffixX[i] + pointXs[i];
  }
  for (int i = 0; i < pointYs.size(); i++) {
    suffixY[i + 1] = suffixY[i] + pointYs[i];
  }

  int answer = INT_MAX;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int xI =
          lower_bound(pointXs.begin(), pointXs.end(), x) - pointXs.begin();
      int yI =
          lower_bound(pointYs.begin(), pointYs.end(), y) - pointYs.begin();

      int cur = 0;
      cur += abs(suffixX[xI] - xI * x) + abs(suffixX.back() - suffixX[xI] -
                                              (int(pointXs.size()) - xI) * x);

      cur += abs(suffixY[yI] - yI * y) + abs(suffixY.back() - suffixY[yI] -
                                              (int(pointYs.size()) - yI) * y);

      answer = min(answer, cur);
    }
  }
  return answer;
}
```

### counting sort & 중앙값

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |  O(R \* C)  |  O(R \* C)  |

배열에서 멘헤탄 거리가 최소가 되는 지점은, 정렬된 배열의 중앙값을 고르는 것이다.

따라서 x, y좌표들을 정렬 후 각 중앙값의 좌표를 찾아 반환한다.

이 때 각 좌표의 값의 범위가 적으므로 카운팅 정렬을 수행할 수 있다.

```cpp
int getDistSum(vector<int>& points, int axis) {
  int distance = 0;
  for (int& point : points) {
    distance += abs(axis - point);
  }
  return distance;
}

int minTotalDistance(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid.front().size();

  vector<int> pointXs, pointYs;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) continue;
      pointYs.push_back(y);
    }
  }

  for (int x = 0; x < cols; x++) {
    for (int y = 0; y < rows; y++) {
      if (grid[y][x] == 0) continue;
      pointXs.push_back(x);
    }
  }

  // get median
  int y = pointYs[pointYs.size() / 2];
  int x = pointXs[pointXs.size() / 2];

  int answer = getDistSum(pointYs, y) + getDistSum(pointXs, x);
  return answer;
}
```

## 고생한 점
