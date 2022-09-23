# Problem C1: Valet Parking - Chapter 1

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-2/problems/C1)

| 난이도 |
| :----: |
| 16 pt  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

정답의 경우는 현재 상태에서 위로, 아래로만 움직인 경우, 혹은 현재 상태중 하나가 될 수 있다.

현재 이동횟수에 K번째 줄에 남은 차의 갯수만큼 차를 띄운 횟수가 정답이 된다.

이동 횟수는 최대 R번까지 가능하다.

이동을 직접 구현할 경우 O(R \* C)의 시간 복잡도를 사용한다.

지금까지 각 좌표마다 쌓인 차와 현재 이동하는 좌표의 상태를 이용해 이동을 구현할 경우 O(C)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(R \* C)가 된다.

### 공간 복잡도

각 좌표마다의 쌓여있는 차의 수를 이용할 경우 O(C)의 공간 복잡도를 사용한다.

### 그리디 알고리즘 & 쌓인 차 세기

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(R \* C)  |    O(C)     |

정답의 경우는 현재 상태에서 위로, 아래로만 움직인 경우, 혹은 현재 상태중 하나가 될 수 있다.

현재 이동횟수에 K번째 줄에 남은 차의 갯수만큼 차를 띄운 횟수가 정답이 된다.

위로 혹은 아래로 계속 이동시킬 경우 이동 횟수는 최대 R번까지 가능하다. (이 이상 이동시켜도 결과는 같으므로)

현재 X좌표에 대해서 위로 한칸 차를 이동시킨다고 하자.

현재까지 K번째 행 위에(이동하는 방향)으로 차가 K개 쌓여있는 경우 몇번을 위로 차를 이동한다 하더라도 해당 K번째 행 X좌표에는 차가 존재한다.

만약 그 외의 경우, K번쨰 행으로 차가 오는 경우 현재 좌표에 차가 존재하게 된다.

이를 이용해 미리 K번째 행 까지의 각 X좌표마다의 차의갯수를 세고 이후 나머지 행들에 대해 순회하며 K번째 행에 차가 존재하는지 아닌지를 판단한다.

이때 아래로 이동시키는 경우는 해당 구현의 반대로 할 수 있다.

편의를 위해 2차원 좌표를 x축에 대해 대칭하고 K를 뒤집은 K`를 같은 방식으로 구할 수 있다.

이를 구현하면 다음과 같다.

```cpp
int getMinimumChange(vector<string> &board, int k) {
  const int rows = board.size(), cols = board.front().size();

  vector<int> upperCount(cols, 0);

  int answer = 0;
  for (int x = 0; x < cols; x++) {
    if (board[k][x] == 'X') answer++;
  }

  if (answer == 0) return 0;

  // up case
  for (int y = 0; y <= k; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 'X') {
        upperCount[x]++;
      }
    }
  }

  for (int i = 0; i < rows; i++) {
    int target = (k + 1) + i;
    int curAnswer = i + 1;

    if (curAnswer >= answer) break;
    for (int x = 0; x < cols && target < rows; x++) {
      if (board[target][x] == 'X') {
        upperCount[x]++;
      }
    }

    for (int x = 0; x < cols; x++) {
      if (upperCount[x] >= (k + 1) ||
          target < rows && board[target][x] == 'X') {
        curAnswer++;
      }
    }

    answer = min(curAnswer, answer);
  }

  return answer;
}

int solution(int rows, int cols, int k, vector<string> &board) {
  vector<string> reversed = board;
  for (int y = 0; y < rows / 2; y++) {
    int rI = (rows - 1) - y;

    swap(reversed[y], reversed[rI]);
  }

  int minCount = getMinimumChange(board, k);
  int reverseMinCount = getMinimumChange(reversed, (rows - 1) - k);

  int answer = min(minCount, reverseMinCount);

  return answer;
}
```

## 고생한 점
