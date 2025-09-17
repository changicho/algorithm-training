# 498. Diagonal Traverse

[링크](https://leetcode.com/problems/diagonal-traverse/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

순회를 이용해 풀이할 경우 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(R \* C)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(R \* C)  |  O(R \* C)  |

첫번째 행을 시작점으로 원소들을 순회한 뒤, 마지막 열에 대해 순회한다.

```cpp
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
  int rows = mat.size(), cols = mat[0].size();

  vector<int> answer;
  for (int x = 0; x < cols; x++) {
    int size = answer.size();

    for (int y = 0; y < rows; y++) {
      if (x - y < 0) break;
      answer.push_back(mat[y][x - y]);
    }
    if (x % 2 == 0) {
      reverse(answer.begin() + size, answer.end());
    }
  }
  for (int y = 1; y < rows; y++) {
    int size = answer.size();

    for (int x = 0; x < cols; x++) {
      if (y + x >= rows || cols - 1 - x < 0) break;

      answer.push_back(mat[y + x][cols - 1 - x]);
    }

    if ((cols - 1 + y) % 2 == 0) {
      reverse(answer.begin() + size, answer.end());
    }
  }

  return answer;
}
```

## 고생한 점
