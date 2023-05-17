# 1572. Matrix Diagonal Sum

[링크](https://leetcode.com/problems/matrix-diagonal-sum/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 정사각형 배열의 한 변의 크기를 N이라 하자.

y좌표에 대해 0부터 N-1까지 순회하며 더해야되는 부분들만 더할 수 있다.

이 떄 정 중앙의 값은 한번만 더한다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

별도의 배열을 선언하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      13      |    O(N)     |    O(1)     |

y좌표에 대해 0부터 N-1까지 순회하며 더해야되는 부분들만 더한다.

각 좌표마다의 x좌표 2가지는 다음과 같다.

- leftX : y
- rightX : N - 1 - y

이 때 leftX와 rightX가 같은 경우는 한번만 더한다.

```cpp
int diagonalSum(vector<vector<int>>& mat) {
  int sum = 0;

  int size = mat.size();
  for (int y = 0; y < size; y++) {
    int leftX = y, rightX = size - 1 - leftX;

    sum += mat[y][leftX];
    if (leftX != rightX) {
      sum += mat[y][rightX];
    }
  }

  return sum;
}
```

## 고생한 점
