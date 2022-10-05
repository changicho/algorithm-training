# Problem B: Traffic Control

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/B)

| 난이도 |
| :----: |
| 18 pt  |

## 설계

### 시간 복잡도

입력받은 행의 갯수를 N, 열의 갯수를 M이라 하자.

그리디 알고리즘을 이용해 문제를 풀이할 경우 모든 좌표를 채우면 되므로 이는 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N \* M)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N \* M)  |  O(N \* M)  |

결국 두 경로는 어느순간 교차하게 된다.

따라서 중복 방문하는 구역이 존재한다.

이를 이용해 중복 방문하는 구역을 강제로 생성하고, 나머지는 각자만 방문하는 공간애 가중치를 할당해 정답을 구성한다.

열의 갯수가 2개일때, 3개 이상일 때를 구분해 문제를 풀이한다.

먼저 열의 갯수가 3개 이상인 경우를 살펴보자.

맨 마지막 줄을 두 경우 모두 방문하는 구간으로 정하고, 나머지 맨 왼쪽 세로줄, 맨 오른쪽 세로줄을 남은 수를 채우도록 구성한다.

열의 갯수가 2개인 경우, 한쪽 세로줄이 낮은수가 되면 그쪽으로 이동하는 경로가 최소값이 된다. (연이어 붙어있으므로 벽으로 이동을 막을 수 없음)

따라서 한쪽 세로줄을 두 경로 모두 이용하도록 구성한다.

이 때 이동해야하는 칸수보다 a, b가 작을 경우 정답을 생성할 수 없다.

이를 구현하면 다음과 같다.

```cpp
vector<vector<int>> solution(int rows, int cols, int a, int b) {
  vector<vector<int>> answer(rows, vector<int>(cols, 1000));

  int minimumNeed = rows + cols - 1;
  if (a < minimumNeed || b < minimumNeed) {
    return {};
  }

  if (cols == 2) {
    int minimum = min(a - (rows - 1), b - (rows - 1));

    if (a > b) {
      for (int y = 0; y < rows; y++) {
        answer[y][1] = 1;
      }
      answer[rows - 1][0] = b - rows;
      answer[0][0] = a - rows;
    } else {
      for (int y = 0; y < rows; y++) {
        answer[y][0] = 1;
      }
      answer[rows - 1][1] = a - rows;
      answer[0][1] = b - rows;
    }

    return answer;
  }

  for (int y = 0; y < rows; y++) {
    answer[y][0] = answer[y][cols - 1] = 1;
  }

  // final row for both
  int minimum = min(a - (rows - 1), b - (rows - 1));
  for (int x = 0; x < cols; x++) {
    answer[rows - 1][x] = minimum / cols;
  }
  answer[rows - 1][cols - 1] += minimum % cols;

  int aLeft = a - minimum;
  int bLeft = b - minimum;

  if (aLeft > 0) {
    for (int y = 0; y < rows - 1; y++) {
      answer[y][0] = aLeft / (rows - 1);
    }
    answer[0][0] += aLeft % (rows - 1);
  }
  if (bLeft > 0) {
    for (int y = 0; y < rows - 1; y++) {
      answer[y][cols - 1] = bLeft / (rows - 1);
    }
    answer[0][cols - 1] += bLeft % (rows - 1);
  }

  return answer;
}
```

## 고생한 점
