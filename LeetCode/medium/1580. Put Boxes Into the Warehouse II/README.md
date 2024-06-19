# 1580. Put Boxes Into the Warehouse II

[링크](https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 boxes의 크기를 N, 배열 warehouse의 크기를 M이라 하자.

warehouse에서 양 방향으로 box를 집어넣을 때 유효한 height를 계산한다.

이후 정렬을 이용해 투 포인터를 사용할 경우 O(N \* log_2(N) + M \* log_2(M))의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 최대 O(N + M)의 공간 복잡도가 필요하다.

### valid height & 정렬

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|     116      | O(N \* log_2(N) + M \* log_2(M)) |  O(N + M)   |

창고의 양 방향으로 box를 집어넣을 수 있으며, 병목이 생길 수 있다.

따라서 양 방향으로 box를 집어넣을 수 있는 실제 heights를 계산한다.

이후 해당 heights와 boxes를 정렬한 뒤 투 포인터를 이용해 최대한 많은 box를 집어넣을 수 있는 경우를 찾는다.

```cpp
int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
  int bSize = boxes.size(), wSize = warehouse.size();

  vector<int> heights(wSize);

  for (int i = 0, minimum = INT_MAX; i < wSize; i++) {
    minimum = min(minimum, warehouse[i]);
    heights[i] = minimum;
  }
  for (int i = wSize - 1, minHeight = INT_MAX; i >= 0; i--) {
    minHeight = min(minHeight, warehouse[i]);
    heights[i] = max(heights[i], minHeight);
  }

  sort(heights.begin(), heights.end());
  sort(boxes.begin(), boxes.end());

  int answer = 0;
  int bI = 0;
  for (int& height : heights) {
    if (bI < bSize && boxes[bI] <= height) {
      answer++;
      bI++;
    }
  }

  return answer;
}
```

## 고생한 점
