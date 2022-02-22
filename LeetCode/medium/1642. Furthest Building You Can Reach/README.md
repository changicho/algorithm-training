# 1642. Furthest Building You Can Reach

[링크](https://leetcode.com/problems/furthest-building-you-can-reach/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

heights의 크기를 N, ladders를 K라 하자.

heights를 순회하며 각 경우마다 벽돌을 사용하거나 사다리를 써야한다.

만약 둘중하나를 써야하는 경우 최적화된 답을 구하기 위해서 greedy한 방법을 이용한다.

우성 최대한 사다리부터 사용한 뒤, 사다리가 모자랄 때 지금까지 지나온 높이 중 가장 작은 높이를 벽돌로 대체한다.

이 경우 heap을 이용해 각 상황마다 가장 작은 높이를 찾을 수 있다.

heap을 이용하는 경우 시간 복잡도는 O(N \* log_2(N))이 된다.

각 경우마다 도달할 수 있는 최대 index에 대해서 이분탐색으로 풀이할 수 있다.

이 경우 해당 index까지 도달하는지 판단하는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

따라서 이분 탐색을 이용하는 경우 최종 시간 복잡도는 O(N \* (log_2(N))^2)가 된다.

### 공간 복잡도

heap을 이용하는 경우 힙의 크기는 K를 넘지 않는다.

따라서 heap의 경우 공간 복잡도는 O(K)이다.

이분 탐색을 이용하는 경우 O(N)의 공간 복잡도를 사용한다.

### heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      88      | O(N \* log_2(N)) |    O(K)     |

각 높이를 순회하며 높이가 감소하는 경우는 지나치고, 높이가 올라가는 경우에 대해서 아래와 같이 판단한다.

- 우선 사다리부터 사용한다. 이 경우 높이의 차이만큼 힙에 저장한다.
- 사다리를 사용하지 못하는 경우 기존에 지나온 높이에 사다리 대신 벽돌을 사용한다.
- 이 때 가장 높이가 낮은 구간에 사다리 대신 벽돌을 사용한다.
- 만약 벽돌로 줄이지 못하는 경우 현재 높이까지 도달할 수 없다.

여기서 가장 낮은 구간에 벽돌을 대신 사용하는 이유는 최대한 벽돌을 많이 사용하기 위함이다.

이를 구현하면 다음과 같다.

```cpp
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
  int size = heights.size();
  int answer = 0;

  // O(K)
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // O(N)
  for (int i = 1; i < size; i++) {
    int diff = heights[i] - heights[i - 1];

    // use brick or ladder case
    if (diff > 0) {
      // O(log_2(N))
      minHeap.push(diff);
    }

    // use brick case
    if (minHeap.size() > ladders) {
      // O(log_2(N))
      bricks -= minHeap.top();
      minHeap.pop();
    }

    if (bricks < 0) break;

    // can reach to current index
    answer = i;
  }

  return answer;
}
```

## 고생한 점
