# 2906. Construct Product Matrix

[링크](https://leetcode.com/problems/construct-product-matrix/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

prefix suffix를 사용할 경우 O(RC)의 시간 복잡도를 가진다.

### 공간 복잡도

prefix suffix를 사용해 이동하며 계산할 경우 O(1)의 공간 복잡도를 가진다.

### prefix suffix

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |    O(RC)    |    O(1)     |

1차원 배열에서 문제 조건과 같이 풀이한다 하자.

이 경우 특정 index를 기준으로 left part, right part로 나뉜다.

index를 이동시켜가며 left part, right part의 곱을 계산하고 이를 갱신할 수 있다.

이를 똑같이 2차원 배열에도 적용할 수 있다.

```cpp
vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
  const int MOD = 12345;

  int rows = grid.size(), cols = grid[0].size();

  long long prefix = 1;
  long long suffix = 1;

  vector<vector<int>> answer(rows, vector<int>(cols));
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      answer[y][x] = prefix;
      prefix *= grid[y][x];
      prefix %= MOD;
    }
  }

  for (int y = rows - 1; y >= 0; y--) {
    for (int x = cols - 1; x >= 0; x--) {
      answer[y][x] *= suffix;
      answer[y][x] %= MOD;
      suffix *= grid[y][x];
      suffix %= MOD;
    }
  }
  return answer;
}
```

## 고생한 점
