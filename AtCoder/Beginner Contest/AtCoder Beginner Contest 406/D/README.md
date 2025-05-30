# D - Garbage Removal

[링크](https://atcoder.jp/contests/abc406/tasks/abc406_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

행의 갯수를 R, 열의 갯수를 C, 쓰레기의 갯수를 T, 쿼리의 갯수를 Q라고 하자.

각 쿼리를 순회하며 각 행과 열에 대해 지워진 시간을 기록한다. 이에 O(Q)의 시간 복잡도를 사용한다.

이후 각 쓰레기를 순회하며 각 시간마다 지워지는 쓰레기들을 저장한다. 이에 O(T)의 시간 복잡도를 사용한다.

이후 쿼리를 순회하며 해당 시간에 각 행광 열에 남아있는 쓰레기를 구하고, 해당 시간에 지워지는 쓰레기를 제거한다. 이에 O(Q)의 시간 복잡도를 사용한다.

최종적으로 O(Q + T)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 행과 열에 대해 지워진 시간을 저장하기 위해 O(R + C)의 공간 복잡도를 사용한다.

각 시간마다 지워지는 쓰레기를 저장하기 위해 O(T)의 공간 복잡도를 사용한다.

### 시간 제거

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도  |
| :----------: | :---------: | :----------: |
|      64      |  O(Q + T)   | O(R + C + T) |

쿼리를 순회하며 각 행과 열이 지워지는 최초의 시간을 기록한다.

이후 쓰레기를 순회하며 해당 쓰레기의 y, x좌표에 대해서 가장 먼저 지워지는 시간을 찾고, 해당 쓰레기가 해당 시간에 지워지는것을 기록한다. (각 시간마다 지워지는 쓰레기들을 저장한다.)

이후 쿼리를 순회하며 해당 시간에 각 행과 열에 남아있는 쓰레기를 구하고, 해당 시간에 지워지는 쓰레기를 제거한다.

```cpp
vector<int> solution(int rows, int cols, vector<Axis> &trashes, vector<pair<int, int>> &queries) {
  int tSize = trashes.size();
  int qSize = queries.size();

  vector<int> rowErasedTime(rows + 1, INT_MAX);
  vector<int> colErasedTime(cols + 1, INT_MAX);
  for (int i = 0; i < qSize; i++) {
    pair<int, int> &query = queries[i];
    int command = query.first;
    int target = query.second;

    // 1: row, 2: col
    if (command == 1) {
      rowErasedTime[target] = min(i, rowErasedTime[target]);
    } else if (command == 2) {
      colErasedTime[target] = min(i, colErasedTime[target]);
    }
  }

  vector<int> rowCounts(rows + 1, 0);
  vector<int> colCounts(cols + 1, 0);

  vector<vector<Axis>> eraseList(qSize);
  for (Axis &t : trashes) {
    int y = t.y;
    int x = t.x;

    rowCounts[y]++;
    colCounts[x]++;

    int erasedTime = min(rowErasedTime[y], colErasedTime[x]);

    if (erasedTime != INT_MAX) {
      eraseList[erasedTime].push_back(t);
    }
  }

  vector<int> answer;
  for (int i = 0; i < qSize; i++) {
    pair<int, int> &query = queries[i];
    int command = query.first;
    int target = query.second;

    // 1: row, 2: col
    if (command == 1) {
      answer.push_back(rowCounts[target]);
    } else if (command == 2) {
      answer.push_back(colCounts[target]);
    }

    for (Axis &t : eraseList[i]) {
      rowCounts[t.y]--;
      colCounts[t.x]--;
    }
  }

  return answer;
}
```

## 고생한 점
