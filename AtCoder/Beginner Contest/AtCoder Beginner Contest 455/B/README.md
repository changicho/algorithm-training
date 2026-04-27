# B - Spiral Galaxy

[링크](https://atcoder.jp/contests/abc455/tasks/abc455_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC라 하자.

완전 탐색을 수행할 경우 O(RC^3)의 시간 복잡도를 사용한다.

### 공간 복잡도

완전 탐색에 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |   O(RC^3)   |    O(1)     |

문제 조건에 맞춰 직사각형의 시작과 끝점에 대해 모두 탐색한다.

```cpp
int solution(int rows, int cols, vector<string>& board) {
  int answer = 0;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      for (int yy = y; yy < rows; yy++) {
        for (int xx = x; xx < cols; xx++) {
          bool isAllSame = true;

          for (int i = y; i <= yy; i++) {
            for (int j = x; j <= xx; j++) {
              char target = board[y + yy - i][x + xx - j];
              if (board[i][j] != target) isAllSame = false;
            }
          }

          answer += isAllSame;
        }
      }
    }
  }

  return answer;
}
```

## 고생한 점
