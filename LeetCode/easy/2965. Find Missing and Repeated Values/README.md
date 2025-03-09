# 2965. Find Missing and Repeated Values

[링크](https://leetcode.com/problems/find-missing-and-repeated-values/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열 grid의 모든 원소의 수를 N이라 하자. (N <= 50^2)

각 숫자별로 count할 경우 O(N)의 시간 복잡도가 필요하다.

수학적 방법을 이용할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

각 숫자별로 count할 경우 O(N)의 공간 복잡도가 필요하다.

수학적 방법을 이용할 경우 O(1)의 공간 복잡도로 풀이가 가능하다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

수들의 갯수를 센 뒤 중복된 수와 빠진 수를 찾는다.

```cpp
vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  int duplicated = -1, missed = -1;
  bool visited[2501] = {
      false,
  };
  for (vector<int> &row : grid) {
    for (int &num : row) {
      if (visited[num]) {
        duplicated = num;
      }
      visited[num] = true;
    }
  }

  for (int i = 1; i <= rows * cols; i++) {
    if (!visited[i]) {
      missed = i;
    }
  }
  return {duplicated, missed};
}
```

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

빠진 수와 중복된 수를 각각 A, B라 하자.

1부터 N까지의 합과 실제 값의 합의 차이는 B - A이다.

1부터 N까지의 제곱의 합과 실제 값의 제곱의 합의 차이는 B^2 - A^2이다.

이는 (B - A) \* (B + A)이므로 (B - A)를 구할 수 있으므로 나머지 (B + A) 또한 구할 수 있다.

이를 이용해 빠진 수와 중복된 수를 구할 수 있다.

```cpp
vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  long long sum = 0, sqrSum = 0;
  long long total = rows * cols;

  for (vector<int> &row : grid) {
    for (int &num : row) {
      sum += num;
      sqrSum += (long long)num * num;
    }
  }

  long long totalSum = total * (total + 1) / 2;
  long long totalSqrSum = total * (total + 1) * (2 * total + 1) / 6;

  long long sumDiff = sum - totalSum;
  long long sqrDiff = sqrSum - totalSqrSum;

  int duplicated = (sqrDiff / sumDiff + sumDiff) / 2;
  int missed = (sqrDiff / sumDiff - sumDiff) / 2;

  return {duplicated, missed};
}
```

## 고생한 점
