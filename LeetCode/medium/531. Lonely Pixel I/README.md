# 531. Lonely Pixel I

[링크](https://leetcode.com/problems/lonely-pixel-i/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 갯수를 R, 열의 갯수를 C라 하자.

각 좌표마다 행열에 대해서 탐색을 반복할 경우 시간 복잡도는 O(R \* C \* (R + C))이다.

각 행과 열마다 존재하는 B의 갯수를 count후에 각 좌표마다 가능한지 여부를 판단할 수 있다.

이 경우 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 좌표마다 B의 갯수를 count할 경우 O(R + C)의 시간 복잡도를 사용한다.

### 좌표 count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     210      |  O(R \* C)  |  O(R + C)   |

각 행, 열에 대한 B의 갯수가 2 이상인 경우 해당 행, 열은 사용이 불가능하다.

따라서 각 행과 열에 대해서 존재하는 B에 대한 count를 수행한다.

이후 각 좌표를 다시 순회하며 해당 행과 열의 갯수가 1인 경우만 정답에 추가한다.

이를 구현하면 다음과 같다.

```cpp
int findLonelyPixel(vector<vector<char>>& picture) {
  int rows = picture.size();
  int cols = picture.front().size();

  vector<int> rowCounts(rows, 0), colCounts(cols, 0);

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (picture[y][x] != 'B') continue;

      rowCounts[y]++;
      colCounts[x]++;
    }
  }

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (picture[y][x] != 'B') continue;

      if (rowCounts[y] == 1 && colCounts[x] == 1) answer++;
    }
  }
  return answer;
}
```

## 고생한 점
