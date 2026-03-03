# 1536. Minimum Swaps to Arrange a Binary Grid

[링크](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 N^2라 하자.

각 행들을 위에서 부터 순회하며 현재 채워야 하는 행으로 직접 이동한다.

해당 swap에 O(N)의 시간 복잡도를 사용한다. 이를 모든 행에 대해 수행하므로 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 행에 대해 오른쪽부터 유효한 0의 갯수를 저장하는 배열을 하나 사용한다. O(N)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |   O(N^2)    |    O(N)     |

각 행마다 오른쪽부터 연속된 0의 갯수로 변환 후 저장한다.

이후 첫번째 행부터 순회하며 조건을 만족하는 가장 가까운 행을 찾은 뒤 swap한다.

이를 모든 행에 대해 수행한다.

```cpp
int minSwaps(vector<vector<int>>& grid) {
  int rows = grid.size();
  int cols = grid[0].size();

  vector<int> counts;
  for (vector<int>& row : grid) {
    int count = 0;
    for (int x = cols - 1; x >= 0; x--) {
      if (row[x] == 0)
        count++;
      else
        break;
    }

    counts.push_back(count);
  }

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    bool isFind = false;
    for (int i = y; i < rows; i++) {
      if (counts[i] >= (cols - y - 1)) {
        for (int j = i; j > 0; j--) {
          swap(counts[j], counts[j - 1]);
        }
        answer += (i - y);
        isFind = true;
        break;
      }
    }

    if (!isFind) return -1;
  }
  return answer;
}
```

## 고생한 점
