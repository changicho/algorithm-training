# 10830. 행렬 제곱

[링크](https://www.acmicpc.net/problem/10830)

| 난이도  | 정답률(\_%) | 제한 시간 |
| :-----: | :---------: | :-------: |
| Gold IV |   34.712    |   1 초    |

## 설계

### 시간 복잡도

행렬의 크기는 최대 5^2이다.

제곱의 회수는 최대 100,000,000,000 까지이다.

직접 곱을 수행하는 경우 시간 복잡도는 100,000,000,000 이상이므로 제한시간 내에 불가능하다.

따라서 O(log_2(N)) 이내에 수행해야 하므로 분할정복 기법을 이용한다.

### 공간 복잡도

B가 매우 크므로 long long 형태로 선언한다.

행렬의 값은 1000을 초과하지 않으므로 int형으로 선언해도 된다.

### 행렬의 곱

행렬의 곱을 다음과 같이 나타낼 수 있다.

이 때 매번 1000으로 나눈 나머지를 저장함에 유의한다.

```cpp
vector<vector<int> > multiplyMatrix(vector<vector<int> > matrixA, vector<vector<int> > matrixB) {
  vector<vector<int> > temp(N);
  for (int i = 0; i < N; i++) {
    temp[i].resize(N, 0);
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      int sum = 0;

      for (int i = 0; i < N; i++) {
        sum += matrixA[y][i] * matrixB[i][x];
        sum %= 1000;
      }

      temp[y][x] = sum;
    }
  }

  return temp;
}
```

### 행렬의 제곱

B는 최대 100,000,000,000 까지이므로 분할 정복을 이용해야 한다.

행렬을 matrix, 남은 제곱수를 K, K번 제곱한 행렬을 multipliedMatrix(K)라고 할 때 다음 식이 성립한다.

```cpp
// K % 2 == 0
multipliedMatrix(K) = multipliedMatrix(K/2) * multipliedMatrix(K/2)

// K % 2 == 1
multipliedMatrix(K) = multipliedMatrix(K/2) * multipliedMatrix(K/2) * matrix
```

K를 나누기 2씩 하면서 줄여가므로 시간 복잡도는 O(log_2(K))이다.

이는 B가 최대값이여도 제한시간 내에 가능하다.

```cpp
vector<vector<int> > squaredMatrix(long long N, vector<vector<int> > matrix) {
  if (N == 1) {
    return matrix;
  }

  vector<vector<int> > targetA = squaredMatrix(N / 2, matrix);

  vector<vector<int> > ret = multiplyMatrix(targetA, targetA);
  if (N % 2 == 1) {
    ret = multiplyMatrix(ret, origin);
  }
  return ret;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

```sh
# data
2 1
1000 1000
1000 1000

# answer
0 0
0 0
```

맨 처음 배열의 값으로 1000이 들어올 수 있음에 유의한다.
