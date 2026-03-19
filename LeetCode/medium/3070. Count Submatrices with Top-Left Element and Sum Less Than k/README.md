# 3070. Count Submatrices with Top-Left Element and Sum Less Than k

[링크](https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯루를 C라 하자.

2차원 prefix sum을 이용할 경우 O(RC) 의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum에 O(RC) 의 공간 복잡도를 사용한다.

입력받은 배열을 사용할 경우 O(1) 의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(RC)    |    O(1)     |

2차원 prefix sum을 이용해 0,0 부터 y,x 까지의 합을 구한다.

이후 해당 합이 조건을 만족하는 경우 answer 를 증가시킨다.

```cpp
int countSubmatrices(vector<vector<int>>& grid, int k) {
  int rows = grid.size(), cols = grid[0].size();

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (y > 0) {
        grid[y][x] += grid[y - 1][x];
      }
      if (x > 0) {
        grid[y][x] += grid[y][x - 1];
      }
      if (y > 0 && x > 0) {
        grid[y][x] -= grid[y - 1][x - 1];
      }

      if (grid[y][x] <= k) {
        answer++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
