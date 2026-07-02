# 755. Pour Water

[링크](https://leetcode.com/problems/pour-water/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 물의 양을 V라 하자.

시뮬레이션을 사용할 경우 O(N \* V)의 시간 복잡도가 소요된다.

### 공간 복잡도

입력받은 배열을 제외하고 O(1)의 공간 복잡도가 소요된다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |  O(N \* V)  |    O(1)     |

각 위치별로 물을 떨어뜨리며 조건에 따라 위치를 찾는다.

이 때 왼쪽부터 탐색하며 가장 낮은 최초의 위치를 찾는다. (벽에 도달할 때까지) 만약 찾지 못할 경우 같은 방법으로 오른쪽을 탐색한다.

```cpp
vector<int> pourWater(vector<int>& heights, int volume, int k) {
  int size = heights.size();

  for (int i = 0; i < volume; i++) {
    int cur = heights[k];
    int target = k;
    for (int i = k - 1; i >= 0; i--) {
      if (heights[i] > heights[target])
        break;
      else if (heights[i] < heights[target]) {
        target = i;
      }
    }

    if (target == k) {
      for (int i = k + 1; i < size; i++) {
        if (heights[i] > heights[target])
          break;
        else if (heights[i] < heights[target]) {
          target = i;
        }
      }
    }

    heights[target]++;
  }

  return heights;
}
```

## 고생한 점
