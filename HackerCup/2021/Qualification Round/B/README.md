# Problem B: Xs and Os

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B)

| 난이도 |
| :----: |
| 15 pt  |

## 설계

### 시간 복잡도

입력받은 보드의 크기를 N이라 하자.

이를 모두 순회하며 정답을 생성 불가능한 경우를 찾는다. 이에 O(N^2)의 시간 복잡도를 사용한다.

이후 각 row, col에 대해서 정답을 생성할 수 있는 경우를 찾고 이때 채워지는 axis들을 저장한다.

해당 경우를 탐색하는데 O(N^2)의 시간 복잡도를 사용한다.

이 axis들의 갯수와 종류에 대해서 hash set에 저장해 중복을 방지한다.

해당 axis들을 특정 규칙으로 정렬하는데 최대 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 정답을 반환한다.

### 공간 복잡도

각 row, col에 대해서 한줄을 만들 수 있는지 여부를 O(N)의 공간 복잡도를 이용해 미리 계산한다.

이후 정답의 경우를 생성하는 과정에서 axis는 최대 N개가 생성되며 이에 O(N)의 공간 복잡도를 사용한다.

정답의 유일한 경우를 저장하는데 hash set의 배열을 사용하며 이는 O(N^2)의 공간 복잡도를 사용한다.

### 탐색

|      시간 복잡도       | 공간 복잡도 |
| :--------------------: | :---------: |
| O(N^2 + N \* log_2(N)) |   O(N^2)    |

각 좌표를 우선 순회하며 해당 줄을 정답으로 사용하는게 가능한지 판단한다.

이는 해당 줄 (가로, 세로)에 O가 존재하는지를 판단하면 된다.

이후 가능한 경우들을 순회하며 채워지는 axis들을 vector에 저장한다.

이를 정렬 후 사용하는 axis 갯수에 vector를 저장한다.

이 갯수별 채워지는 axis들 타입은 set으로 관리해 중복을 제거한다.

```cpp
pair<int, int> solution(int size, vector<string>& board) {
  vector<bool> flagRows(size, true), flagCols(size, true);

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if (board[y][x] == 'O') {
        flagCols[x] = false;
        flagRows[y] = false;
      }
    }
  }

  set<vector<pair<int, int>>> answerCase[size + 1];
  for (int y = 0; y < size; y++) {
    if (!flagRows[y]) continue;

    vector<pair<int, int>> axises;
    for (int x = 0; x < size; x++) {
      if (board[y][x] == '.') {
        axises.push_back({y, x});
      }
    }
    if (axises.size() == 0) continue;
    sort(axises.begin(), axises.end());
    answerCase[axises.size()].insert(axises);
  }
  for (int x = 0; x < size; x++) {
    if (!flagCols[x]) continue;

    vector<pair<int, int>> axises;
    for (int y = 0; y < size; y++) {
      if (board[y][x] == '.') {
        axises.push_back({y, x});
      }
    }
    if (axises.size() == 0) continue;
    sort(axises.begin(), axises.end());
    answerCase[axises.size()].insert(axises);
  }

  for (int i = 0; i <= size; i++) {
    if (answerCase[i].size() > 0) {
      return {i, answerCase[i].size()};
    }
  }

  return {0, 0};
}
```

## 고생한 점
