# 2500. Delete Greatest Value in Each Row

[링크](https://leetcode.com/problems/delete-greatest-value-in-each-row/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라고 하자.

각 행의 숫자들을 정렬 후 각 과정마다 큰 숫자를 선택한다.

이 경우 행의 정렬에 O(C \* log_2(C))의 시간 복잡도를 사용한다.

이를 모든 행에 반복하므로 시간 복잡도는 O(R \* C \* log_2(C))가 된다.

### 공간 복잡도

입력받은 배열을 사용할 경우 별도의 공간 복잡도를 사용하지 않는다.

### 정렬

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|      15      | O(R \* C \* log_2(C)) |    O(1)     |

```cpp
int deleteGreatestValue(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid.front().size();

  for (vector<int>& row : grid) {
    sort(row.begin(), row.end());
  }

  int answer = 0;
  for (int x = 0; x < cols; x++) {
    int target = 0;
    for (int y = 0; y < rows; y++) {
      target = max(target, grid[y].back());
      grid[y].pop_back();
    }
    answer += target;
  }
  return answer;
}
```

## 고생한 점
