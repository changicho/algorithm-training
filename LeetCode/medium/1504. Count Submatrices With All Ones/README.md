# 1504. Count Submatrices With All Ones

[링크](https://leetcode.com/problems/count-submatrices-with-all-ones/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

모든 경우를 탐색할 경우 O(R^2 \* C^2)의 시간 복잡도를 사용한다.

연속된 1의 갯수를 사용할 경우 O(R^2 \* C)의 시간 복잡도를 사용한다.

모노토닉 스택을 사용할 경우 O(R \* C) 시간 복잡도를 사용한다.

### 공간 복잡도

2차원 배열에 O(R \* C)의 공간 복잡도를 사용한다.

모노토닉 스택에 O(C)의 공간 복잡도를 사용한다.

### 연속된 1의 갯수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(R^2 \* C) |  O(R \* C)  |

각 좌표마다 왼쪽에 연이은 1의 갯수를 저장하는 배열을 생성한다.

이후 모든 좌표를 순회하며 현재 좌표에서 y좌표를 감소시켜가며 1의 갯수들 중 최소값을 매번 찾는다.

해당 최솟값 만큼 정답에 더해준다.

이는 현재 좌표를 포함하는 직사각형을 만들기 위해선 현재 좌표 상단 (y가 감소하는 방향)에서 연속된 1의 갯수가 작아지는 경우 해당 width의 직사각형을 만들기 때문이다.

```cpp
int numSubmat(vector<vector<int>>& mat) {
  int rows = mat.size(), cols = mat[0].size();

  int rowCounts[150][150] = {
      0,
  };

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    int ones = 0;
    for (int x = 0; x < cols; x++) {
      if (mat[y][x] == 0) {
        ones = 0;
      } else {
        ones++;
      }

      rowCounts[y][x] = ones;
      int cur = rowCounts[y][x];

      for (int by = y; by >= 0; by--) {
        cur = min(cur, rowCounts[by][x]);
        if (cur == 0) break;

        answer += cur;
      }
    }
  }

  return answer;
}
```

## 고생한 점
