# 861. Score After Flipping Matrix

[링크](https://leetcode.com/problems/score-after-flipping-matrix/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

그리디 알고리즘을 이용해 각 행마다 최선의 값을 생성한 뒤 각 열을 순회하며 최선의 값을 찾아내야 한다.

이 경우 O(R \* C)의 시간 복잡도가 소요된다.

### 공간 복잡도

그리디 알고리즘을 사용할 때 직접 입력받은 배열을 바꾸는 경우 O(1)의 공간 복잡도가 필요하다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |  O(R \* C)  |    O(1)     |

각 행의 비트를 아래와 같이 최대로 만들 수 있다.

- 첫번째 비트(가장 큰 비트)가 1이 아니면 flip한다.

이는 가장 큰 비트값이 나머지 비트의 합보다 크기 때문이다. 따라서 가장 큰 비트의 값이 1이 되어야 한다.

이후 각 열마다 순회하며 뒤집는 경우와 뒤집지 않는 경우 중 최선의 값을 찾는다.

```cpp
void flipRow(vector<int> &row) {
  for (int &n : row) {
    n = !n;
  }
}

int matrixScore(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  for (vector<int> &row : grid) {
    if (row[0] == 0) {
      flipRow(row);
    }
  }

  int answer = 0;
  for (int x = 0; x < cols; x++) {
    int bit = 1 << (cols - 1 - x);

    int oneCount = 0, zeroCount = 0;
    for (int y = 0; y < rows; y++) {
      if (grid[y][x] == 1) {
        oneCount++;
      } else {
        zeroCount++;
      }
    }

    answer += max(oneCount, zeroCount) * bit;
  }
  return answer;
}
```

## 고생한 점
