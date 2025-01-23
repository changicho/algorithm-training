# 1267. Count Servers that Communicate

[링크](https://leetcode.com/problems/count-servers-that-communicate/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 R \* C라 하자.

각 좌표를 순회하며 각 행과 열마다의 갯수를 세어 연결된 갯수를 센다.

이 경우 O(R \* C)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 행과 열의 갯수를 저장하는 데 O(R + C)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(R \* C)  |  O(R + C)   |

각 서버는 행과 열에 같은 서버가 있어야 활성화된다.

각 행과 열에 대한 서버의 갯수를 세고 만약 현재 서버의 갯수가 2개 이상인 경우 연결되었으므로 active한다.

```cpp
int countServers(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  vector<int> rowCount(rows, 0);
  vector<int> colCount(cols, 0);

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) continue;
      rowCount[y]++;
      colCount[x]++;
    }
  }

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) continue;
      if (rowCount[y] > 1 || colCount[x] > 1) answer++;
    }
  }

  return answer;
}
```

## 고생한 점
