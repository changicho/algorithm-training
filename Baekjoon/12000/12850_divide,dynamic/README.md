# 12850. 본대 산책2

[링크](https://www.acmicpc.net/problem/12850)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold I |   82.940    |       1       |

## 설계

### 시간 복잡도

D는 최대 1,000,000,000까지이다.

가중치 없는 무향 그래프를 이진 행렬로 표현했을 때 행렬 제곱을 통해 N번 이동했을 때의 경우의 수를 구할 수 있다. (N번 제곱)

행렬을 만들고 D번만큼 제곱한 후, 정보과학관에서 정보과학관을 가는 경로의 수를 구해주면 된다.

D가 매우 크므로 분할 정복을 이용한 거듭 제곱 기법을 사용한다.

이 때의 시간 복잡도는 O(N^3 \* log_2(D)) 이므로 제한시간 내에 충분하다. (N은 8이며 행렬 제곱을 할 때의 시간 복잡도)

### 공간 복잡도

행렬의 값은 1,000,000,007 이하임이 보장된다.

행렬의 곱 연산을 수행할 때 덧셈이 들어가므로 1,000,000,007을 넘을 가능성이 존재한다.

따라서 long long 형태를 선언한다.

### 행렬의 곱

정방 행렬 이므로 크기를 통일시킨다.

```cpp
vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b) {
  vector<vector<long long>> ret(SIZE, vector<long long>(SIZE, 0));

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      for (int k = 0; k < SIZE; k++) {
        ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]) % DIV;
      }
    }
  }
  return ret;
}
```

### 분할 정복

D가 매우 크므로 D를 2로 나눠가며 반복한다.

또한 제곱할 대상이 되는 행렬은 단위행렬로 설정한다.

```cpp
vector<vector<long long>> powMatrix(vector<vector<long long>> a, int n) {
  vector<vector<long long>> ret(SIZE, vector<long long>(SIZE, 0));

  for (int i = 0; i < SIZE; i++) {
    ret[i][i] = 1;
  }

  while (n > 0) {
    if (n % 2 == 1) {
      ret = multiply(ret, a);
    }

    n /= 2;
    a = multiply(a, a);
  }

  return ret;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
