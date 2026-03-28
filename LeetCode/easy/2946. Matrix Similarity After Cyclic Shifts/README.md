# 2946. Matrix Similarity After Cyclic Shifts

[링크](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 좌표를 순회하며 판단할 경우 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

비교에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(R \* C)  |    O(1)     |

각 좌표를 순회하며 해당 좌표를 K만큼 시프트한 좌표의 값과 비교한다.

만약 다른값이 있다면 이동 후에 배열의 모양이 달라지는 것이므로 false를 반환한다.

```cpp
bool areSimilar(vector<vector<int>>& mat, int k) {
  int rows = mat.size(), cols = mat[0].size();

  k %= cols;

  for (vector<int>& row : mat) {
    for (int x = 0; x < cols; x++) {
      if (row[x] != row[(x + k) % cols]) return false;
    }
  }
  return true;
}
```

## 고생한 점
