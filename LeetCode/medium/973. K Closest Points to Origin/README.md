# 973. K Closest Points to Origin

[링크](https://leetcode.com/problems/k-closest-points-to-origin/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

점들의 갯수를 N이라 하자.

정렬을 이용해 k개의 원소를 뽑을 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

힙을 이용해 원하는 K개의 원소를 저장할 경우 heap을 갱신하는 데 O(log_2(K))의 시간 복잡도를 사용한다.

이를 모든 원소에 대해 반복하므로 시간 복잡도는 O(N \* log_2(K))이다.

### 공간 복잡도

힙을 사용할 경우 O(K)의 공간 복잡도를 사용한다.

정렬을 사용할 경우 points 그대로 사용하므로 별도의 공간 복잡도를 사용하지 않는다.

정답을 반환하는데 O(K)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     312      | O(N \* log_2(N)) |    O(K)     |

모든 원소를 원점과의 거리에 대해 가까운 순으로 정렬한다.

이후 각 원소중 앞에서 K개의 원소를 뽑는다.

```cpp
vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
  sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {
    return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
  });

  vector<vector<int>> answer;
  for (int i = 0; i < k; i++) {
    answer.push_back(points[i]);
  }
  return answer;
}
```

### 힙

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     254      | O(N \* log_2(K)) |    O(K)     |

각 원소를 순회하며 K개의 원점에서 가장 가까운 원소들만 저장해야 한다.

만약 현재 heap에서 원소를 교채해야 할 경우,

원점에서 부터 거리가 먼 원소를 교채한다.

따라서 maxHeap을 만들고 K개의 원소만 heap에 저장한다.

여기서 현재 거리가 maxHeap의 top보다 먼 경우 skip한다.

이를 구현하면 다음과 같다.

```cpp
int getDistance(vector<int> &point) {
  return point[0] * point[0] + point[1] * point[1];
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
  priority_queue<pair<int, int>> maxHeap;  // distance, index

  for (int i = 0; i < points.size(); i++) {
    pair<int, int> entry = {getDistance(points[i]), i};
    if (maxHeap.size() < k) {
      maxHeap.push(entry);
    } else if (entry.first < maxHeap.top().first) {
      maxHeap.pop();
      maxHeap.push(entry);
    }
  }

  vector<vector<int>> answer;
  while (!maxHeap.empty()) {
    int entryIndex = maxHeap.top().second;
    maxHeap.pop();
    answer.push_back(points[entryIndex]);
  }
  return answer;
}
```

## 고생한 점
