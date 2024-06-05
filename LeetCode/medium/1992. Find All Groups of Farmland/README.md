# 1992. Find All Groups of Farmland

[링크](https://leetcode.com/problems/find-all-groups-of-farmland/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

모든 경우를 직접 탐색할 경우 O(R^2 \* C^2)의 시간 복잡도를 사용한다.

각 farmland에 속하는 좌표는 한번만 방문하면 되므로 중복 방문을 방지할 수 있다.

이 경우 한번의 순회만 필요하므로 O(R \* C)의 시간 복잡도가 필요하다.

### 공간 복잡도

입력받은 배열로 중복을 체크할 경우 O(1)의 공간 복잡도가 필요하다.

### 순회 (greedy)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      87      |  O(R \* C)  |    O(1)     |

문제에서 하나의 farmland는 연속된 1로 이루어진 직사각형이다.

따라서 특정 farmland에 속한 좌표는 다른 farmland에 속하지 않는다.

시작점을 순회하며 해당 점이 이전 farmland에 속한 점인경우 skip할 수 있다.

시작점을 순회하는데 O(R \* C)의 시간 복잡도를 사용하며, 해당 시작점에서 farmland에 속한 모든 좌표를 방문하는데 O(R \* C)의 시간 복잡도가 필요하다.

farmland에 속한 좌표를 모두 방문하는데 O(R \* C)의 시간 복잡도만 사용하므로 최종 시간 복잡도는 O(R \* C)이다.

```cpp
vector<vector<int>> findFarmland(vector<vector<int>>& land) {
  int rows = land.size(), cols = land[0].size();
  vector<vector<int>> answer;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (land[y][x]) {
        int ny = y, nx = x;

        for (ny = y; ny < rows && land[ny][x]; ny++) {
          for (nx = x; nx < cols && land[ny][nx]; nx++) {
            land[ny][nx] = 0;
          }
        }

        answer.push_back({y, x, ny - 1, nx - 1});
      }
    }
  }
  return answer;
}
```

## 고생한 점
