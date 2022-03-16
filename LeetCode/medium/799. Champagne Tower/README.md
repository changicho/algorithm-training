# 799. Champagne Tower

[링크](https://leetcode.com/problems/champagne-tower/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행, 열의 갯수는 각각 최대 100개이다. 따라서 행의 갯수를 N이라 하자.

시뮬레이션을 통해 모두 시도해볼 경우 O(N^2)의 시간 복잡도를 사용한다.

이는 상수이므로 O(1)의 시간복잡도를 사용한다.

### 공간 복잡도

시뮬레이션을 수행하기 위해 동일한 크기의 2차원 배열을 사용하므로 O(N^2)의 공간 복잡도를 사용한다.

이는 상수이므로 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      61      |    O(1)     |    O(1)     |

첫번째 행부터 각 좌표에 대해 다음 연산을 수행한다.

- 현재 좌표의 poured 양이 1 초과인 경우 해당 값에서 1을 뺀 값을 두개로 나눠 자신과 연결된 두 좌표에 보낸다.
- 1 이하인 경우는 넘어간다.

(0,0) 좌표에 처음 poured를 할당하고 이를 행, 열에 대해 순회를 진행하며 각 좌표마다 값을 갱신한다.

이 때 맨 첫번째 행부터 순회한다.

```cpp
double champagneTower(int poured, int query_row, int query_glass) {
  vector<vector<double>> tower(101, vector<double>(101, 0));

  int row = 0;
  tower[0][0] = poured;
  for (int y = 0; y < 100; y++) {
    for (int x = 0; x <= y; x++) {
      if (tower[y][x] >= 1) {
        double remain = tower[y][x] - 1;
        tower[y][x] = 1;
        tower[y + 1][x] += remain / 2;
        tower[y + 1][x + 1] += remain / 2;
      }
    }
  }

  return tower[query_row][query_glass];
}
```

## 고생한 점
