# 835. Image Overlap

[링크](https://leetcode.com/problems/image-overlap/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행, 열의 크기를 N이라 하자.

하나의 가로, 세로에 대해서 shift를 수행하는 횟수는 최대 (N - 1) + (N - 1)번이다.

(가로 기준으로 봤을 때 왼쪽으로 N-1번, 오른쪽으로 N-1번 움직임)

따라서 각 좌표에 대해서 가로, 세로에 대해서 shift연산한 지점을 가상의 시작점으로 사용하고 모두 탐색할 수 있다.

이 경우 좌표 설정에 O(N^2)의 시간 복잡도를 사용하고, 내부 순회에 O(N^2)의 시간 복잡도를 사용한다.

따라서 총 O(N^4)의 시간 복잡도를 사용한다.

### 공간 복잡도

직접 비교하므로 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     117      |   O(N^4)    |    O(1)     |

가로에 대해서 N번 이상, 세로에 대해서 N번 이상 shift연산을 수행하는 경우 모든 배열은 빈 배열이 되므로 한쪽으로 N번 이상 shift하는 작업은 의미가 없다.

각 배열을 직접 shift하지 않고 임의의 시작점을 변경해가며 해당 시작점에서 N^2 크기의 배열을 비교한다.

이를 구현하면 다음과 같다.

```cpp
int countOverlap(int y, int x, vector<vector<int>>& img1,
                  vector<vector<int>>& img2) {
  int rows = img1.size(), cols = img1.front().size();
  int count = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int cur = 0;
      if (0 <= y + i && y + i < rows && 0 <= x + j && x + j < cols)
        cur = img2[y + i][x + j];

      if (cur == 1 && img1[i][j] == cur) {
        count++;
      }
    }
  }
  return count;
}

int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
  int rows = img1.size(), cols = img1.front().size();

  int answer = 0;
  for (int y = -rows + 1; y < rows; y++) {
    for (int x = -cols + 1; x < cols; x++) {
      int cur = countOverlap(y, x, img1, img2);
      answer = max(answer, cur);
    }
  }
  return answer;
}
```

## 고생한 점
