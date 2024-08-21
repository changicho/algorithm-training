# 3189. Minimum Moves to Get a Peaceful Board

[링크](https://leetcode.com/problems/minimum-moves-to-get-a-peaceful-board/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

룩의 갯수를 N 이라 하자. (보드의 크기는 N^2)

결과적으로 각 룩의 위치 y,x를 count했을 때 값이 모두 1개씩만 존재해야 한다.

그리디 알고리즘을 이용해 y, x축에 대해 각 룩의 위치를 count 한 뒤 남는 좌표와 넘치는 좌표 쌍의 diff를 구한다.

이후 해당 두 diff의 합을 구한다.

이에 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 count를 저장하기 위해 O(N)의 공간 복잡도가 필요하다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(N)     |

각 y, x의 좌표별 룩은 하나만 존재해야 한다.

이 때 해당 좌표의 룩이 2개 이상인 경우와 0개인 경우 두 가지가 존재한다.

따라서 y, x에 대해 각 좌표별 룩의 갯수를 센다.

이후 각 좌표별로 1개씩만 존재하도록 룩을 이동시킨다.

이 때 빈 공간과 남는 룩의 갯수는 동일하며, 어떻게 이동시켜도 같은 횟수만큼 움직여야 한다.

따라서 각 쌍의 diff를 구하고 이를 더한다.

이를 y, x에 대해 구하고 더한 값을 반환한다.

```cpp
int getCount(vector<int> &line) {
  int size = line.size();

  vector<int> remains;
  vector<int> empties;
  for (int i = 0; i < size; i++) {
    while (line[i] > 1) {
      remains.push_back(i);
      line[i]--;
    }
    if (line[i] == 0) {
      empties.push_back(i);
    }
  }

  int ret = 0;
  for (int i = 0; i < empties.size(); i++) {
    int diff = abs(remains[i] - empties[i]);
    ret += diff;
  }
  return ret;
}

int minMoves(vector<vector<int>> &rooks) {
  int rows = rooks.size(), cols = rooks.size();

  vector<int> rowCounts(rows, 0);
  vector<int> colCounts(cols, 0);

  for (vector<int> &rook : rooks) {
    int y = rook[0], x = rook[1];

    rowCounts[y]++;
    colCounts[x]++;
  }

  int answer = getCount(rowCounts) + getCount(colCounts);
  return answer;
}
```

## 고생한 점
